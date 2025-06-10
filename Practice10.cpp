#include <iostream>
using namespace std;

int main() {
    //array declare

    int arr[7];

    cout << "Array created successfully." << endl;
    cout << arr << endl; // This will print the address of the array
    cout << &arr << endl; // This will also print the address of the array

    // Array initialization
    int arr1[] = {1, 2, 3, 4, 5};
    cout << "Array 1 created successfully." << endl;

    int arr2[5] = {1, 2, 3, 4, 5};
    cout << "Array 2 created successfully." << endl;

    int arr3[10] = {1, 2, 3, 4, 5}; // All elements initialized to 0
    cout << "Array 3 created successfully." << endl; 

    cout << arr1[0] << endl; // Accessing the first element of arr1
    cout << arr2[4] << endl; // Accessing the first element of arr2

    //Printing the array's vlaues
    for(int i = 0; i < 5; i++) {
        cout << arr1[i] << " ";
    }

    return 0;
}