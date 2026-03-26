#include <iostream>
using namespace std;

// ======================================================================
// FUNCTION: solve()
// ----------------------------------------------------------------------
// PURPOSE:
//   Demonstrates how arrays behave when passed to functions.
//
// KEY CONCEPT:
//   Arrays decay into pointers when passed to functions.
//
//   So:
//     int arr[]  → becomes → int* arr
//
// IMPORTANT:
//   sizeof(arr) inside function ≠ actual array size
// ======================================================================
void solve(int arr[]) {

    cout << "Size inside solve function: " << sizeof(arr) << endl;

    // Prints base address of array
    cout << "arr (base address): " << arr << endl;

    // Address of pointer variable inside function
    cout << "&arr (address of pointer): " << &arr << endl;

    // Modify first element
    arr[0] = 50;
}

// ======================================================================
// FUNCTION: update()
// ----------------------------------------------------------------------
// PURPOSE:
//   Demonstrates pointer passing and modification.
//
// KEY CONCEPT:
//   Pointer stores address of variable
//   Dereferencing (*) modifies actual value
// ======================================================================
void update(int* p) {

    cout << "Address stored inside p: " << p << endl;
    cout << "Address of pointer p: " << &p << endl;

    // Modify value at address
    *p = *p + 10;
}

// ======================================================================
// MAIN FUNCTION
// ======================================================================
int main() {

    // --------------------------------------------------
    // ARRAY DEMO
    // --------------------------------------------------
    int arr[10] = {1, 2, 3, 4};

    cout << "Size inside main: " << sizeof(arr) << endl;

    // Base address of array
    cout << "arr: " << arr << endl;

    // Address of entire array
    cout << "&arr: " << &arr << endl;

    // Print array elements
    cout << "Array elements:\n";
    for (int i = 0; i < 10; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "\nNow calling solve()\n";

    solve(arr);

    cout << "Back to main()\n";

    // After modification
    for (int i = 0; i < 10; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // --------------------------------------------------
    // POINTER DEMO
    // --------------------------------------------------
    int a = 5;

    cout << "\nAddress of a: " << &a << endl;

    int* ptr = &a;

    cout << "Address stored in ptr: " << ptr << endl;
    cout << "Address of ptr: " << &ptr << endl;

    update(ptr);

    cout << "Updated value of a: " << a << endl;

    return 0;
}