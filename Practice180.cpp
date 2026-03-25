#include <iostream>
using namespace std;

// ======================================================================
// CLASS: abc
// ----------------------------------------------------------------------
// Demonstrates the use of the `this` pointer in C++.
//
// DATA MEMBERS:
//   • x → integer value
//   • y → integer value
//
// KEY CONCEPT:
//   `this` pointer refers to the CURRENT OBJECT
// ======================================================================
class abc {
public:
    int x, y;

    // --------------------------------------------------
    // FUNCTION: print()
    // --------------------------------------------------
    // PURPOSE:
    //   Prints values of x and y using `this` pointer.
    //
    // WHAT IS `this`?
    //   • A pointer to the current object
    //   • Automatically passed to all non-static member functions
    //
    void print() const {

        // Accessing members using this pointer
        cout << this->x << " " << this->y << endl;
    }
};

// ======================================================================
// MAIN FUNCTION
// ======================================================================
int main() {

    // Object initialization
    abc obj1 = {1, 2};
    abc obj2 = {4, 5};

    obj1.print();   // Output: 1 2
    obj2.print();   // Output: 4 5

    return 0;
}