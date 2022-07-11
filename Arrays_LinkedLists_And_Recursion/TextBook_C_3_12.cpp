// In the towers of hanoi puzzle, we are given a platform with three pegs a, b, and c. On peg a is a stack of n disks, each larger than the next,
// so that the the smallest is on top and the largest is on bottom. The puzzle is to move all the disks from peg a to peg c, moving one disk at a time
// so that we never place a larger disk on top of a smaller one.

// Describe a recursive algorithm for solving the Towers of Hanoi puzzle for an arbitraty n

// We can represent each of the pegs as an array

#include <iostream>
#include <list>

using namespace std;

class TowerOfHanoi {
    public:
        TowerOfHanoi(int n);
        void solvePuzzle(char a, char b, char c, int n); // where we will write our algorithm 
        void printAnswer();
    
        int n;
        int moves = 0;
};

TowerOfHanoi::TowerOfHanoi(int n) : n(n) {}

/*
    The base solution here is to move disk 1 from a to c. If we had two disks, the focus would be to move the top one to b 
    so that we can move the bottom one to c. The pattern here is we need to move all of n-1 disks from a to b, using c as 
    auxilliary storage if needed. Then we move the bottom disk from a to c. Now, we need to move all of the disks from b to c, 
    using a as storage.

    Here is a recursive trace for 3 pucks:
    - f('a', 'b', 'c', 3)
        - f('a', 'c', 'b', 2)
            - f('a', 'b', 'c', 1) -> move disk 1 from rod a to c
            - move disk 2 from rod a to rod b
            - f('c', 'a', 'b', 1) -> move disk 1 from rod c to rod b
        
        = move disk 3 from rod a to rod c
            
        - f('b', 'a', 'c', 2)
            - f('b', 'c', 'a', 1) -> move disk 1 from rod b to a
            - move disk 2 from rod b to c
            - f('a', 'b', 'c', 1) -> move disk 1 from rod a to c
*/

void TowerOfHanoi::solvePuzzle(char a, char b, char c, int n) {
    if (n == 1) {
        cout << "Move disk " << n << " from rod " << a << " to rod " << c << endl;
        return;
    } else {
        solvePuzzle(a, c, b, n-1);
        cout << "Move disk " << n << " from rod " << a << " to rod " << c << endl;
        solvePuzzle(b, a, c, n-1);
    }
}

int main() {
    TowerOfHanoi tower(4);

    tower.solvePuzzle('A', 'B', 'C', tower.n);
}