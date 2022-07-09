/*
    This was a previous interview question:

    Suppose that you are trying to organize running linux processes, which are listed by user PID, command, and process PID. The command is the name of the process,
    while user PID is the user owning the process, and process PID is the PID of the running process. In this case, we need to organize the files such that user PID -> process PID -> command

    Process PID        User PID         Command
    ___________        ___________      _________

    1234               9876             /bin/sh
 
    3456               9876             /usr/bin/gnome-shell
 
    2345               5647             /snap/code/78 
 
    1543               9876             /usr/lib/xorg

    3333               5647             /usr/NetworkManager

    1111               9876             ./build/monitor

*/ 

// In this instance, we can use a tree, where the tree root is the whole system (root) and the second layer of branches is users, and the bottom is pairs of processes and their commands

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

// simple graph node class
class Node {
    public:
        string key;
        vector<Node* > child;
};

// helper function to create new nodes
Node* newNode(string key) {
    Node* temp = new Node;
    temp->key = key;
    return temp;
}

class OrganizeFiles {
    vector<vector<string>> files = {{"1234", "9876", "/bin/sh"},
                                {"3456", "9876", "/usr/bin/gnome-shell"},
                                {"2345", "5647", "/snap/code/78 "},
                                {"1543", "9876", "/usr/lib/xorg"},
                                {"3333", "5467", "/usr/NetworkManager"},
                                {"1111", "9876", "./build/monitor"}};

    public:
        void organize(vector<vector<string>>& files) {
            // initialize tree with root node
            Node* root = newNode("root");

            // initialize a set here, will be used to ensure the user PIDs aren't duplicated
            unordered_set<string> set;

            // now loop through the array and add items to graph
            for (int i=0; i < files.size(); i++) {
                if (set.find(files[i][1]) != set.end()) {
                    set.insert(files[i][1]);
                    (root->child).push_back(newNode(files[i][1]));
                }

                
            }
        }
};

int main() {

}