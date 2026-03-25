#include <iostream>
using namespace std;

// ======================================================================
// CLASS: Base
// ----------------------------------------------------------------------
// Demonstrates use of VIRTUAL DESTRUCTOR.
//
// KEY POINT:
//   Destructor is declared as virtual to ensure
//   proper cleanup of derived class objects.
// ======================================================================
class Base {
public:

    // Constructor
    Base() {
        cout << "Base ctor\n";
    }

    // Virtual Destructor
    virtual ~Base() {
        cout << "Base dtor\n";
    }
};

// ======================================================================
// CLASS: Derived
// ----------------------------------------------------------------------
// Inherits from Base class.
//
// Has its own constructor and destructor.
// ======================================================================
class Derived : public Base {
public:

    // Constructor
    Derived() {
        cout << "Derived ctor\n";
    }

    // Destructor
    ~Derived() {
        cout << "Derived dtor\n";
    }
};

// ======================================================================
// MAIN FUNCTION
// ======================================================================
int main() {

    // Base pointer pointing to Derived object
    Base* b = new Derived();

    // Deleting using base pointer
    delete b;

    return 0;
}