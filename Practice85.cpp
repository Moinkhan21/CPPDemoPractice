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

    cout << *arr1 << endl; // Print the first element of arr1
    cout << arr[0] << endl; // Print the first element of arr
    cout << *arr1 + 1 << endl; // Print the second element of arr1
    cout << *(arr1) + 1 << endl; // Print the second element of arr1
    cout << *(arr1 + 1) << endl; // Print the second element of arr1
    cout << arr1[1] << endl; // Print the second element of arr1
    cout << *(arr1 + 2) << endl; // Print the third element of arr1
    cout << arr1[2] << endl; // Print the third element of arr1
    cout << *(arr1 + 3) << endl; // Print the fourth element of arr1

    return 0;
}