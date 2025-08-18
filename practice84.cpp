#include <iostream>

using namespace std;

int main() {
    int a = 5;
    int b = 5;

    cout << b << endl;
    cout << a << endl;

    cout << &a << endl; // Print the address of variable 'a'
    cout << &b << endl; // Print the address of variable 'b'

    int c = 10;
    //pointer create
    int* ptr = &c;

    cout << c << endl;
    cout << &c << endl; // Print the address of variable 'c'

    // Accessing the value of 'c' using the pointer or access the value ptr is pointing to
    cout << "Address of c is: " << &c << endl;
    cout << "value stored at ptr is: " << ptr << endl;
    cout << "Value of c is pointing to: " << *ptr << endl;
    cout << "Address of ptr is: " << &ptr << endl; // Print the address of pointer 'ptr'

    int d = 5;
    int* ptr2 = &d; // Create another pointer pointing to 'd'

    cout << sizeof(ptr2) << endl; // Print the size of pointer 'ptr2'

    char ch = 'b';
    char* ptr3 = &ch; // Create a pointer pointing to 'ch'

    cout << sizeof(ptr3) << endl; // Print the size of pointer 'ptr3'

    double e = 5.5;
    double* ptr4 = &e; // Create a pointer pointing to 'e'

    cout << sizeof(ptr4) << endl; // Print the size of pointer 'ptr4'

    // Bad Practice
    int* ptr5;
    // ptr5 is declared but not initialized, it points to an undefined location
    cout << *ptr5 << endl; // This will lead to undefined behavior

    // Null pointer
    int* ptr6 = 0; // int* ptr6 = NULL; Initialize ptr6 to a null pointer(Old version)
    cout << ptr6 << endl; // This will print 0 or NULL

    int* ptr7 = nullptr; // Initialize ptr7 to a null pointer
    cout << ptr7 << endl; // This will also print 0 or NULL

    int s = 5;

    int* ptr8 = &s; // Create a pointer pointing to 's'
    cout << sizeof(ptr8) << endl; // Print the size of pointer 'ptr8'

    //copy pointer
    int* ptr9 = ptr8; // Create another pointer pointing to the same address as ptr8
    cout << sizeof(ptr9) << endl; // Print the size of pointer 'ptr9'

    cout << *ptr8 << endl; // Print the value pointed to by ptr8
    cout << *ptr9 << endl; // Print the value pointed to by ptr9

    int t = 10;
    int* ptr10 = &t; // Create a pointer pointing to 't'
    int* ptr11 = ptr10; // Create another pointer pointing to the same address as ptr10
    int* ptr12 = ptr11; // Create yet another pointer pointing to the same address as ptr11

    cout << t << endl;
    cout << &t << endl; // Print the address of variable 't'
    cout << ptr10 << endl; // Print the address stored in ptr10
    cout << &ptr10 << endl; // Print the address of pointer 'ptr10'
    cout << *ptr10 << endl; // Print the value pointed to by ptr10
    cout << ptr11 << endl; // Print the address stored in ptr11
    cout << &ptr11 << endl; // Print the address of pointer 'ptr11'
    cout << *ptr11 << endl; // Print the value pointed to by ptr11
    cout << ptr12 << endl; // Print the address stored in ptr12
    cout << &ptr12 << endl; // Print the address of pointer 'ptr12'
    cout << *ptr12 << endl; // Print the value pointed to by ptr12
    cout << (*ptr10 + *ptr11 + *ptr12) << endl; // Print the sum of values pointed to by ptr10, ptr11, and ptr12
    cout << (*ptr10)*2 + (*ptr12)*3 << endl;
    cout << (*ptr10/2) - (*ptr11/2) << endl;

    return 0;
}
