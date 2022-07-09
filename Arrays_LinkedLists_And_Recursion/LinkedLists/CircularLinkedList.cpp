// A circular linked list is very similar to a single linked list, except that there is no head or tail

#include <iostream>

using namespace std;

typedef string Elem;
class CNode {
    private:
        Elem elem;
        CNode* next;

        friend class CircleList;
};

class CircleList {
    public:
        CircleList();
        ~CircleList();
        bool empty() const;
        const Elem& front() const; // element at cursor
        const Elem& back() const; // element following cursor
        void advance();
        void add(const Elem& e);
        void remove();

    private:
        CNode* cursor; // cursor to follow along list
};

CircleList::CircleList() : cursor(NULL) {}
CircleList::~CircleList() { while (!empty()) remove(); }

// Accessors
bool CircleList::empty() const { return cursor == NULL; }
const Elem& CircleList::back() const { return cursor->elem; }
const Elem& CircleList::front() const { return cursor->next->elem; }

// Methods
void CircleList::add(const Elem& e) { // add after cursor
    CNode* v = new CNode;
    v->elem = e;
    if (cursor == NULL) { // is list empty
        v->next = v;
        cursor = v;
    } else {
        v->next = cursor->next;
        cursor->next = v;
    }
}

void CircleList::remove() {
    CNode* old = cursor->next;
    if (old == cursor) cursor = NULL;
    else cursor->next = old->next;
    delete old;
}

// Use of circular list as a playlist
int main() {
    CircleList playList;
    playList.add("Stayin Alive");
    playList.add("Le Freak");
    playList.add("Jive Talkin");

    playList.advance(); // now on Jive Talkin
    playList.advance(); // now on Le Freak
    playList.remove(); // removes Stayin Alive
    playList.add("Disco Inferno");

    return EXIT_SUCCESS;
}