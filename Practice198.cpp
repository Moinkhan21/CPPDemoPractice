#include <iostream>
using namespace std;

// ---------------- CLASS: Base ----------------
// Purpose: Represents the base (parent) class that provides a
// constructor and destructor for demonstration of inheritance,
// destructor behavior, and virtual destructor usage in C++.
class Base
{
    public:
        // ---------- CONSTRUCTOR ----------
        // Called automatically when an object of `Base`
        // (or derived class object) is created.
        Base()
        {
            cout << "Base ctor\n";
        }

        // ---------- DESTRUCTOR ----------
        // Declared as **virtual** so that when a `Derived` object
        // is deleted through a `Base*` pointer, the `Derived` destructor
        // is also called automatically.
        //
        // Without `virtual`, only `Base`'s destructor runs,
        // causing a memory leak if the derived class has
        // dynamically allocated resources.
        virtual ~Base()
        {
            cout << "Base dtor\n";
        }
};

// ---------------- CLASS: Derived ----------------
// Purpose: Inherits from `Base` and allocates a dynamic
// array to demonstrate proper resource cleanup using destructors.
class Derived : public Base
{
    int *a; // Pointer to a dynamically allocated integer array

    public:
        // ---------- CONSTRUCTOR ----------
        // 1. Implicitly calls `Base()` constructor first.
        // 2. Allocates memory for an array of 1000 integers.
        // 3. Displays message indicating `Derived` constructor execution.
        Derived()
        {
            a = new int[1000];   // Dynamic memory allocation
            cout << "Derived ctor\n";
        }

        // ---------- DESTRUCTOR ----------
        // 1. Frees the dynamically allocated memory using `delete[]`.
        // 2. Displays message indicating `Derived` destructor execution.
        // 3. Called automatically when deleting a `Derived` object.
        //
        // Because `Base`’s destructor is virtual,
        // this destructor will also be invoked properly
        // even if the deletion happens via a `Base*` pointer.
        ~Derived()
        {
            delete[] a;          // Properly release allocated memory
            cout << "Derived dtor\n";
        }
};

int main() {
    // ---------- MAIN FUNCTION EXECUTION ----------
    // Step 1: Create a pointer `b` of type `Base*`
    // and assign it an object of type `Derived`.
    // This demonstrates **runtime polymorphism**
    // (base pointer pointing to derived object).
    Base *b = new Derived();

    // Step 2: Delete the `Derived` object using the `Base` pointer.
    // Because the `Base` destructor is now virtual,
    // both `Derived` and `Base` destructors will be called
    // in the correct order.
    delete b;

    // Step 3: End of program — all resources are released properly.
    return 0;
}
