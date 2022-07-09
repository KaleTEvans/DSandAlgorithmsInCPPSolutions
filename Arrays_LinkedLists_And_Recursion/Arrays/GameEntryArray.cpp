// Book example for storing game entries in an array

#include <iostream>

using namespace std;

class GameEntry {
    public:
        GameEntry(const string& n = "", int s = 0);
        string getName() const; // get player name
        int getScore() const; // get player score
    private:
        string name;
        int score;
};

GameEntry::GameEntry(const string& n, int s) : name(n), score(s) {}

string GameEntry::getName() const { return name; }
int GameEntry::getScore() const { return score; }

// Classs for the index out of bounds exception
class IndexOutOfBounds {
    public:
        IndexOutOfBounds(const string& err) : errMsg(err) {}
        string getError() { return errMsg; }
    private:
        string errMsg;
};

// Now we'll design a class called scores, to store our game score information
// We will store the highest scores in an array entries, with a variable maxEntries to determine how many entries we want to keep track of
class Scores {
    public:
        Scores(int maxEnt = 10);
        ~Scores();
        void add(const GameEntry& e); // add a game entry
        GameEntry remove(int i) throw(IndexOutOfBounds); // remove an entry
    private:
        int maxEntries;
        int numEntries;
        GameEntry* entries; // array of game entries
};

Scores::Scores(int maxEnt) {
    maxEntries = maxEnt;
    entries = new GameEntry[maxEntries];
    numEntries = 0;
}

Scores::~Scores() { delete[] entries; }

// Since we want the scores to be ordered, when we add an entry, we should determine the correct placement of the score and adjust the array if needed
void Scores::add(const GameEntry& e) {
    int newScore = e.getScore();
    if (numEntries == maxEntries) {
        if (newScore <= entries[maxEntries-1].getScore()) return; // if the array is full
    } else {
        numEntries++;
    }

    int i = numEntries - 2; // start with the next to last
    while (i >= 0 && newScore > entries[i].getScore()) {
        entries[i+1] = entries[i];
        i--;
    }
    entries[i+1] = e; // put e in the empty slot
}

// Now, if the amount of entries is full, we should remove one
GameEntry Scores::remove(int i) throw(IndexOutOfBounds) {
    // throw error if we receive an index outside of the array
    if ((i < 0) || (i >= numEntries)) throw IndexOutOfBounds("Invalid index");

    GameEntry e = entries[i]; // save the removed object
    for (int j = i+1; j < numEntries; j++) {
        entries[j-1] = entries[j]; // shift entries left
    }
    numEntries--; // one fewer entry
    return e; // return the removed object
}