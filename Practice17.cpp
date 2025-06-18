#include <iostream>
#include <vector>
using namespace std;

int main() {

    // Declare 2D Array
    int arr[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    // Print the 2D Array
    cout << "2D Array:" << endl;
    cout << arr[1][2] << endl; // Accessing an element in the 2D array`

    //row-wise print
    cout << "Row-wise print:" << endl;
    // Outer loop 
    for(int i = 0; i < 3; i++) {
        //for every row, we need to print value in each column
        for(int j = 0; j < 3; j++) {
            cout << arr[i][j] << " "; // Print each element in the row
        }
        cout << endl; // New line after each row
    }

    // Column-wise print
    cout << "Column-wise print:" << endl;   

    // Outer loop 
    for(int i = 0; i < 3; i++) {
        //for every row, we need to print value in each column
        for(int j = 0; j < 3; j++) {
            cout << arr[j][i] << " "; // Print each element in the row
        }
        cout << endl; // New line after each row
    }

    int arr1[4][3];
    int rows = 4;
    int cols = 3;

    cout << "Enter elements for a 4x3 array:" << endl;
    // Input elements for a 4x3 array

    // Outer loop for rows
    for(int i = 0; i < rows; i++) {
        // Inner loop for columns
        for(int j = 0; j < cols; j++) {
            cin >> arr1[i][j]; // Read each element
        }
        cout << endl; // New line after each row input
    }

    cout << "You entered:" << endl;
    // Print the 4x3 array
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            cout << arr1[i][j] << " "; // Print each element
        }
        cout << endl; // New line after each row
    }

    return 0; // Return 0 to indicate successful execution
}