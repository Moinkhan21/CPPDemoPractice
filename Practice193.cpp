#include <iostream>
using namespace std;

// ======================================================================
// CLASS: abc
// ----------------------------------------------------------------------
// Demonstrates SHALLOW COPY behavior in C++.
//
// DATA MEMBERS:
//   • x → normal integer
//   • y → pointer to dynamically allocated memory
//
// KEY CONCEPT:
//   Default copy constructor performs SHALLOW COPY
// ======================================================================
class abc {
public:
    int x;
    int* y;

    // --------------------------------------------------
    // PARAMETERIZED CONSTRUCTOR
    // --------------------------------------------------
    // Allocates memory dynamically for pointer y
    abc(int _x, int _y) : x(_x), y(new int(_y)) {}

    // --------------------------------------------------
    // COPY CONSTRUCTOR (Shallow Copy)
    // --------------------------------------------------
    // Copies pointer ADDRESS, not actual data
    abc(const abc &obj) {
        x = obj.x;
        y = obj.y;   // ❌ SHALLOW COPY (same memory shared)
    }

    // --------------------------------------------------
    // PRINT FUNCTION
    // --------------------------------------------------
    void print() const {
        printf("X:%d\nPTR Y:%p\nContent (*y):%d\n\n", x, y, *y);
    }

    // --------------------------------------------------
    // DESTRUCTOR
    // --------------------------------------------------
    // Deletes dynamically allocated memory
    ~abc() {
        delete y;
    }
};

// ======================================================================
// MAIN FUNCTION
// ======================================================================
int main() {

    abc a(1, 2);
    a.print();

    // Copy object
    abc b = a;
    b.print();

    return 0;
}