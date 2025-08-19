#include <iostream>
using namespace std;

int main() {

    int arr[4] = {12, 14, 16, 18};
    int arr1[4] = {12, 44, 66, 18};

    cout << arr << endl; // Print the address of the array
    cout << arr[0] << endl; // Print the first element of the array
    cout << &arr << endl; // Print the address of the array
    cout << &arr[0] << endl; // Print the address of the first element of the array

    int* ptr = arr; // Initialize a pointer to the array
    cout << ptr << endl; // Print the address stored in the pointer
    cout << &ptr << endl; // Print the address of the pointer itself

     

    return 0;
}