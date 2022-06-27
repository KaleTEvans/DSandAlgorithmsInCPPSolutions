// Write an algorithm to solve a summation puzzle

/*
    A summation puzzle example is:
        send + more = money
    To solve this, you must find a series of numbers that represent each of these letters to solve the puzzle.
    The solution to this would be 
        9567 + 1085 = 10652

    This is solved with multiple recursion. 
*/

#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

bool check(vector<int>& S) {
    unordered_map<char, int> map;
    map['a'] = S[0];
    map['b'] = S[1];
    map['i'] = S[2];
    map['n'] = S[3];
    map['o'] = S[4];
    map['p'] = S[5];
    map['t'] = S[6];

    if (((map['p'] + map['p'] - map['b']) * 100) +
        ((map['o'] + map['a'] - map['i']) * 10) +
        ((map['t'] + map['n'] - map['b']) == 0)) return true;
}

vector<int> puzzleSolve(int k, vector<int>& S, unordered_set<int>& U) {
    for (auto i : U) {
        int e = i;
        U.erase(e);
        S.push_back(e);

        if (k == 1) {
            if (check(S)) {
                return S;
            }
        } else {
            puzzleSolve(k-1, S, U);
        }

        U.insert(e);
        S.pop_back();
    }
}

int main() {
    // lets solve pot + pan = bib
    // the unique letters in this, in alphabetical order, are abinopt

    unordered_set<int> U = {0,1,2,3,4,5,6,7,8,9};
    vector<int> S = {};

    vector<int> ans = puzzleSolve(7, S, U);

    cout << "Solution Found: abinopt = ";
    for (auto i : ans) {
        cout << i;
    }
    cout << endl;
}