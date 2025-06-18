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

}