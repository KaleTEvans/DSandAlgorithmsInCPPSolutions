#include "Progression.h"

// Now let us consider arithmetic progression, we will add a new variable, inc, 
// which provides the value to be added to each new element of the progression
class ArithProgression : public Progression {
    public:
        ArithProgression(long i = 1);
    protected:
        virtual long nextValue();
    protected:
        long inc;
};

// The following is a geometric progression class, which inherits first and cur from Progression
// and its member functions, and adds a new variable base which holds the multiplier value
class GeomProgression : public Progression {
    public:
        GeomProgression(long b = 2); // construct with a default multiplier of 2
    protected:
        virtual long nextValue();
    protected:
        long base;
};

// For a fibonacci progression, in addition to the value cur, we will store the value of the previous element, prev
class FibonacciProgression : public Progression {
    public:
        FibonacciProgression(long f = 0, long s = 1);
    protected:
        virtual long firstValue();
        virtual long nextValue();
    protected:
        long second;
        long prev;
};
