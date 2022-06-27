/*  
    Textbook Problem C-2.4

    Design a class Line that implements a line, which is represented by the formula y = ax+b. 
    Your class should store a and b as double member variables. 
    Write a member function intersect(ℓ) that returns the x coordinate
    at which this line intersects line ℓ. If the two lines are parallel, then your
    function should throw an exception Parallel. Write a C++ program that
    creates a number of Line objects and tests each pair for intersection. Your
    program should print an appropriate error message for parallel lines.
*/

#include <iostream>

using namespace std;

// Definition of a line
class Line {
    public:
        Line(double a, double b);
        double intersect(Line* l);

    private:
        double a;
        double b;
};

// Definition of the parallel error exception
class ParallelException {
    public:
        ParallelException(const string& err) : errMsg(err) {}
        string getError() { return errMsg; }
    private:
        string errMsg;
};

Line::Line(double a, double b) : a(a), b(b) {}

double Line::intersect(Line* L) {
    try {
        if (a == L->a) {
            throw ParallelException("These lines are parallel\n");
        }
    }
    catch (ParallelException& pl) {
        cout << pl.getError();
        return 0;
    }

    int x = (b - L->b) * (a / L->a);
    // If there is a vertical line, that means that the intercept can only be at the lines x location
    if (a == 0 && L->a != 0) {
        return b;
    } else if (a != 0 && L->a == 0) {
        return L->b;
    } else {
        return x;
    }
}

int main() {
    Line* l = new Line(1, 0);  // Initialize comparision line to be y = x

    Line* test = new Line(0, 2); // Create a test line at y = 2, so intersect should be at x = 2    
    cout << test->intersect(l) << endl;

    Line* testTwo = new Line(1, 2); // Testing for parallel error case
    cout << testTwo->intersect(l) << endl;
}