#include "ProgressionMethods.h"

// Note the constructor invokes the base class constructor Progression to initialize the base object along with inc
ArithProgression::ArithProgression(long i) : Progression(), inc(i) {} 

// This is an example of polymorphism. When a Progression pointer is pointing to an ArithProgression object, it will use the
// AirthProgression functions firstValue and nextValue
long ArithProgression::nextValue() {
    cur += inc;
    return cur;
}

GeomProgression::GeomProgression(long b) : Progression(1), base(b) {} // We initialize the base class with a starting value of 1 rather than 0

long GeomProgression::nextValue() {
    cur *= base;
    return cur;
}

// For the fibonacci initialization, we need to create a ficticious element that precedes the first element
// we will denote this as second - first
FibonacciProgression::FibonacciProgression(long f, long s) :
    Progression(f), second(s), prev(second - first) {}

long FibonacciProgression::firstValue() {
    cur = first;
    prev = second - first;
    return cur;
}

long FibonacciProgression::nextValue() {
    long temp = prev;
    prev = cur;
    cur += temp;
    return cur;
}