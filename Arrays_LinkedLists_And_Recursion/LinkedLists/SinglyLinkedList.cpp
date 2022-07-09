// Simple implementation of a singly linked list of strings

// Note that to make this generic rather than only for strings, we can use class templates

#include <iostream>

using namespace std;

class StringNode {
    private:
        string elem;
        StringNode* next;

        friend class StringLinkedList;
};

class StringLinkedList {
    public:
        StringLinkedList();
        ~StringLinkedList();
        bool empty() const; // is list empty?
        const string& front() const; // get front element
        void addFront(const string& e); // add to front of list
        void removeFront(); // remove front item list

    private:
        StringNode* head; // pointer to the head of the list
};

StringLinkedList::StringLinkedList() : head(NULL) {}

StringLinkedList::~StringLinkedList() { while (!empty()) removeFront(); }

bool StringLinkedList::empty() const { return head == NULL; }

const string& StringLinkedList::front() const { return head->elem; }

void StringLinkedList::addFront(const string& e) {
    StringNode* v = new StringNode;
    v->elem = e;
    v->next = head;
    head = v;
} 

void StringLinkedList::removeFront() {
    StringNode* old = head;
    head = old->next;
    delete old;
}