// Write a C++ program that can input any polynomial in standard algebraic notation and outputs the first derivative of that polynomial

// We will probably need to use a string input here, such as "4x^2 + 3x + 1", which would return "8x + 3"

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class FirstDerivative {
    public:
        FirstDerivative(const string& polynomial);
        // We will split the string into single components 
        void splitPolynomial();
        // Next we will get the derivative of each individual component
        void findDerivative();
        // Finally we will concatenate the string
        string concatenate(vector<string>& v);
        // check to see our string is split properly
        void printPolynomial();
    private:
        string polynomial;
        vector<vector<char>> splitString;
        vector<vector<char>> derivedArr;
        // helper function to derive each element
        vector<char> deriveSet(vector<char>& single);
};

FirstDerivative::FirstDerivative(const string& polynomial) : polynomial(polynomial) {}

void FirstDerivative::splitPolynomial() {
    vector<char> temp;

    for (int i=0; i < polynomial.size(); i++) {
        if (polynomial[i] != ' ' && polynomial[i] != '-' && polynomial[i] != '+') {
            temp.push_back(polynomial[i]);
        } else {
            if (!temp.empty()) {
                splitString.push_back(temp);
                temp.clear();
            }
        }
    }

    splitString.push_back(temp);
}

void FirstDerivative::findDerivative() {
    // First we will check the last subarray, if the last one has no x, it is 0 so we will remove it
    int m = splitString.size()-1;
    int n = splitString[m].size()-1;
    if (splitString[m][n] != 'x') splitString.pop_back();

    // now loop through array and derive each element
    for (int i = 0; i < splitString.size(); i++) {
        vector<char> temp = deriveSet(splitString[i]);;
        derivedArr.push_back(temp);
    }
}

vector<char> FirstDerivative::deriveSet(vector<char>& single) {
    vector<char> derive;
    string coeff = "";
    int i;
    for (i=0; single[i] != 'x'; i++) {
        coeff += single[i];
    }
    double c = atol(coeff.c_str());
    // // now skip two for x and ^
    string power = "";
    // // if it is just an x
    if (i+2 >= single.size()) {
        vector<char> temp;
        for (auto i : coeff) temp.push_back(i);
        return temp;
    }
    // get the exponent
    for (i = i+2; i != single.size(); i++) {
        power += single[i];
    }
    double p = atol(power.c_str());
    // now put it together in the derived string
    c = c * p;
    p--;
    auto s = to_string(c);
    auto s2 = to_string(p);

    string derived = "";
    if (p == 1) {
        derived = s + 'x';
    } else {
        derived = s + 'x' + '^' + s2;
    }
    // now put it all back into the array
    for (auto i : derived) derive.push_back(i);
    return derive;
}

// ***** NOTE: This solution will only provide the unsigned derivative
void FirstDerivative::printPolynomial() {
    for (int i=0; i < derivedArr.size(); i++) {
        for (int j=0; j < derivedArr[i].size(); j++) {
            cout << derivedArr[i][j];
        }
        cout << endl;
    }
}

int main() {
    FirstDerivative* poly = new FirstDerivative("4x^2 - 3x - 2");
    poly->splitPolynomial();
    poly->findDerivative();
    poly->printPolynomial();
}