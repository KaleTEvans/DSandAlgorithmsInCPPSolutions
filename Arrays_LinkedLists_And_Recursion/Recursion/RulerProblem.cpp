/*
    Suppose you want to create a function that draws an English ruler. It is broken into intervals, 1/2 inch, 1/4 inch, etc. As the size of the interval decreases by half, the tick length increases by 1

    ---- 0       ----- 0
    -            -
    --           --
    -            -
    ---          ---
    -            -
    --           --
    -            -
    ---- 1       ----
    -            -
    --           --
    -            -
    ---          ---
    -            -
    --           --
    -            -   
    ---- 2       ----- 1

    We will call the longest tick length the major tick length. We will use three functions to complete this. The first, drawRuler draws the entire ruler. Its arguments are the number of inches
    in the ruler, nInches, and the major tick length, majorLength. The second function, drawOneTick draws a single tick of given length. It can also be given an optional integer label, which is
    printed if non negative. The last function, drawTicks, is a recursive function which draws the sequence of ticks within some interval. Its only argument is the tick length associated with the
    interval's central tick. 

    If we ignore the top and bottom ticks for now, we can assume that the function drawTicks, given an interval with central tick length L >= 1, is composed of the following:
        1. An interval with a central tick length L-1
        2. A single tick length L
        3. An interval with central tick length L-1

    With each recursive call, the length decreases by 1, ie drawTicks(L - 1). Once this drops to 0, we exit the function, so the base case is L = 0.
*/

// Lets write our three functions now.
#include <iostream>

using namespace std;
                                    //one tick with optional label
void drawOneTick(int tickLength, int tickLabel = -1) {
    for (int i=0; i < tickLength; i++) {
        cout << "-";
    }
    if (tickLabel >= 0) cout << " " << tickLabel;
    cout << endl;
} 

void drawTicks(int tickLength) {  // draw ticks of given length
    if (tickLength > 0) {  // stop when length drops to 0
        drawTicks(tickLength - 1); // recursively draw top ticks
        drawOneTick(tickLength); // draw center tick
        drawTicks(tickLength - 1); // recursively draw bottom ticks
    }
}

void drawRuler(int nInches, int majorLength) { // draw the entire ruler
    drawOneTick(majorLength, 0); // draw tick 0 and its label
    for (int i=1; i <= nInches; i++) {
        drawTicks(majorLength-1); // draw ticks for this inch
        drawOneTick(majorLength, i); // draw tick i and its label
    }
}

int main() {
    drawRuler(3, 4);
}