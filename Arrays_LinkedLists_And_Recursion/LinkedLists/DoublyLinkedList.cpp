// Here we implement a doubly linked list

#include <iostream>

using namespace std;

typedef string Elem;  // list element type
class DNode {
    private:
        Elem elem;
        DNode* prev;
        DNode* next;
        friend class DLinkedList;
};

class DLinkedList {
    public:
        DLinkedList();
        ~DLinkedList();
        bool empty() const; // check if list is empty
        // Note the use of const at the beginning and end of these functions
        // This means the function must return an Elem type and will not change
        const Elem& front() const; // get front element
        const Elem& back() const; // get rear element
        void addFront(const Elem& e);
        void addBack(const Elem& e);
        void removeFront();
        void removeBack();
        
    private:
        DNode* header;
        DNode* trailer;
    
    protected:
        void add(DNode* v, const Elem& e); // insert new node before v
        void remove(DNode* v); // remove v
};

DLinkedList::DLinkedList() {
    header = new DNode;
    trailer = new DNode;
    header->next = trailer;
    trailer->prev = header;
}

DLinkedList::~DLinkedList() {
    while (!empty()) removeFront(); // remove all but sentinels
    delete header;
    delete trailer;
}

// Accessor functions
bool DLinkedList::empty() const { return (header->next == trailer); }
const Elem& DLinkedList::front() const { return header->next->elem; }
const Elem& DLinkedList::back() const { return trailer->prev->elem; }

// Methods for Adding Nodes
// Observe that the add method works even if the list is empty
// This also explains why we should place the node before v rather than after
void DLinkedList::add(DNode* v, const Elem& e) {
    DNode* u = new DNode;
    u->elem = e; // create new node for e
    u->next = v;
    u->prev = v->prev;
    v->prev->next = v->prev = u;
}

void DLinkedList::addFront(const Elem& e) {
    add(header->next, e);
}

void DLinkedList::addBack(const Elem& e) {
    add(trailer, e);
}

// Methods for Deleting Nodes
void DLinkedList::remove(DNode* v) {
    DNode* u = v->prev;
    DNode* w = v->next;
    u->next = w;
    w->prev = u;
    delete v;
}

void DLinkedList::removeFront() {
    remove(header->next);
}

void DLinkedList::removeBack() {
    remove(trailer->prev);
}