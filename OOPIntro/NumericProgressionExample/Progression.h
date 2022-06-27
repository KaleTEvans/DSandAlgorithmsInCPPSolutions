// A numeric progression is a sequence of numbers, where the value of each number depends on one or more of the previous values. 
// For example, an arithmatec progression determines a next number by addition of a fixed increment. A geometric progression determines a next number by
// multiplication of a fixed base value

#include <iostream>

using namespace std;

// We will first define a class, Progression, defining the generic members and functions of a numeric progression

class Progression {
    public:
        Progression(long f = 0) : first(f), cur(f) {}
        virtual ~Progression() {} // virtual destructor, as the parent class will include virtual functions
        void printProgression(int n); // print the first n values

    protected: // we use protected because we want these methods and variables to be accessible from derived classes
        virtual long firstValue(); // reset the progression to the first value and return it
        virtual long nextValue(); // Step the progression to the next value and return it
    
    protected:
        long first; // first value of the progression
        long cur; // curent value of the progression
};