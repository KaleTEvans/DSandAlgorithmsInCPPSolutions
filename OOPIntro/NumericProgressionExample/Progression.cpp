#include "Progression.h"

void Progression::printProgression(int n) {
    cout << firstValue();
    for (int i = 2; i <= n; i++) {
        cout << ' ' << nextValue();
    }
    cout << endl;
}

// firstValue and nextValue are inteded as utilities that will only be invoked from within the class or derived classes, and therefore are protected
long Progression::firstValue() {
    cur = first;
    return cur;
}

long Progression::nextValue() {
    return ++cur;
}