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

    return 0;
}
