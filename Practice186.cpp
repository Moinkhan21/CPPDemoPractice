#include <iostream>
using namespace std;

// ======================================================================
// PROGRAM: Pointer Basics (Dynamic + Static Memory)
// ----------------------------------------------------------------------
// PURPOSE:
//   Demonstrates:
//   • Dynamic memory allocation (new/delete)
//   • Pointer reassignment
//   • Pointer behavior with variables
// ======================================================================
int main() {

    // --------------------------------------------------
    // Step 1: Dynamic Memory Allocation
    // --------------------------------------------------
    int* a = new int;   // Allocate memory on heap

    *a = 2;             // Store value in allocated memory
    cout << "Value at a: " << *a << endl;

    // --------------------------------------------------
    // Step 2: Free allocated memory
    // --------------------------------------------------
    delete a;           // Prevent memory leak

    // --------------------------------------------------
    // Step 3: Reassign pointer to another variable
    // --------------------------------------------------
    int b = 5;

    a = &b;             // Now pointer points to b

    cout << "Value at a (now pointing to b): " << *a << endl;

    return 0;
}