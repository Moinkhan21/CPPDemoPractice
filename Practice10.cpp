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

    cout << "Enter the input values in array: " << endl;

    int arr4[10] = {};

    // Taking input for arr4
    for(int i = 0; i < 10; i++){
        // int n;
        // cin >> n;
        // arr3[i] = n; 

        cin >> arr4[i]; // Taking input for arr4
    }

    cout << "Array4 values: " << endl;
    for(int i = 0; i < 10; i++) {
        cout << arr4[i] << " "; // Printing the values of arr4
    }

    cout << endl;

    cout << "Array4 double values: " << endl;
    for(int i = 0; i < 10; i++) {
        cout << arr4[i]*2 << " "; // Printing the values of arr4
    }

    cout << endl;

    int arr5[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    for(int i = 0; i < 10; i++) {
        arr5[i] = 1; // Initializing all elements of arr5 to 1
    }
    
    cout << "Array5 values: " << endl;

    for(int i = 0; i < 10; i++) {
        cout << arr5[i] << " "; // Printing the values of arr5
    }

    cout << endl;

    int arr6[10] = {1, 2};

    cout << "Array6 values: " << endl;

    for(int i=0; i<10; i++) {
        cout << arr6[i] << " "; // Printing the values of arr6
    }

    cout << endl;

    int arr7[10] = {0};

    cout << "Array7 values: " << endl;

    for(int i=0; i<10; i++) {
        cout << arr7[i] << " "; // Printing the values of arr7
    }

    return 0;
}