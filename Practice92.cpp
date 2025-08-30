#include <iostream>
using namespace std;

//--------------------------------------
// Function: util
// Purpose : Demonstrates what happens when 
//           you pass a pointer by value and
//           try to change it inside the function.
//--------------------------------------
void util(int* p) {
    // Here 'p' is a local copy of the pointer passed.
    // Adding 1 moves this local pointer to the next memory location
    // but does NOT affect the original pointer in main().
    p = p + 1;
}

//--------------------------------------
// Function: util1
// Purpose : Demonstrates dereferencing and modifying
//           the value pointed to by a pointer.
//--------------------------------------
void util1(int* s) {
    // Here we dereference the pointer and increase the value
    // of the variable it points to.
    // So, this WILL affect the original variable in main().
    *s = *s + 1; // same as: (*s)++
}

int main() {
    //--------------------------------------
    // Part 1: Working with pointers to int
    //--------------------------------------
    int a = 5;        // A normal integer variable
    int* p = &a;      // p stores the address of a
    int** q = &p;     // q is a pointer to pointer, stores address of p

    // Printing addresses and values step by step
    cout << "&a (Address of a): " << &a << endl;
    cout << "a  (Value of a): " << a << endl;
    cout << "p  (Value stored in p = Address of a): " << p << endl;
    cout << "&p (Address of p): " << &p << endl;
    cout << "*p (Value at address stored in p = value of a): " << *p << endl;
    cout << "q  (Value stored in q = Address of p): " << q << endl;
    cout << "&q (Address of q): " << &q << endl;
    cout << "*q (Value at address stored in q = Value of p = Address of a): " << *q << endl;
    cout << "**q (Value at address stored in *q = Value of a): " << **q << endl;

    //--------------------------------------
    // Part 2: Using util() function
    //--------------------------------------
    int b = 5;
    int* r = &b;

    cout << "\nBefore util() call" << endl;
    cout << "b (Value): " << b << endl;
    cout << "r (Pointer holding address of b): " << r << endl;
    cout << "*r (Value at address r = value of b): " << *r << endl;

    util(p); // call util with pointer p

    cout << "\nAfter util() call" << endl;
    // Since util() only modified a LOCAL copy of pointer p,
    // the original pointer r and the value of b remain unchanged.
    cout << "b (Value): " << b << endl;
    cout << "r (Pointer holding address of b): " << r << endl;
    cout << "*r (Value at address r = value of b): " << *r << endl;

    //--------------------------------------
    // Part 3: Using util1() function
    //--------------------------------------
    int c = 5;
    int* s = &c;

    cout << "\nBefore util1() call" << endl;
    cout << "c (Value): " << c << endl;
    cout << "s (Pointer holding address of c): " << s << endl;
    cout << "*s (Value at address s = value of c): " << *s << endl;

    util1(s); // call util1 with pointer s

    cout << "\nAfter util1() call" << endl;
    // util1 dereferenced the pointer and modified c directly,
    // so the value of c actually changed.
    cout << "c (Value): " << c << endl;
    cout << "s (Pointer holding address of c): " << s << endl;
    cout << "*s (Value at address s = value of c): " << *s << endl;

    return 0;
}
