#include <iostream>
#include <vector>
using namespace std;

void printRowWiseSum(int arr[][3], int rows) {
    cout << "Row-wise sum:" << endl;
    for(int i = 0; i < rows; i++) {
        int sum = 0;
        for(int j = 0; j < 3; j++) {
            sum += arr[i][j];
        }
        cout << sum << endl;
    }
}

void printColumnWiseSum(int arr[][3], int rows) {
    cout << "Column-wise sum:" << endl;
    for(int i = 0; i < rows; i++) {
        int sum = 0;
        for(int j = 0; j < 3; j++) {
            sum += arr[j][i];
        }
        cout << sum << endl;
    }
}

int main() {

    int arr[3][3];
    int rows = 3;
    int cols = 3;

    cout << "Enter elements for a 3x3 array:" << endl;
    // Input elements for a 3x3 array

    // Outer loop for rows
    for(int i = 0; i < rows; i++) {
        // Inner loop for columns
        for(int j = 0; j < cols; j++) {
            cin >> arr[i][j]; // Read each element
        }
        cout << endl; // New line after each row input
    }

    cout << "You entered:" << endl;
    // Print the 3x3 array
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            cout << arr[i][j] << " "; // Print each element
        }
        cout << endl; // New line after each row
    }

    printRowWiseSum(arr,rows);
    printColumnWiseSum(arr,rows);

    return 0; // Return 0 to indicate successful execution
}