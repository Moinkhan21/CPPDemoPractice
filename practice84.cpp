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

    return 0;
}
