#include <iostream>
#include <climits>
using namespace std;

void printRowWiseSum(int arr[][3], int rows, int cols) {
    cout << "Row-wise sum:" << endl;
    for(int i = 0; i < rows; i++) {
        int sum = 0;
        for(int j = 0; j < 3; j++) {
            sum += arr[i][j];
        }
        cout << sum << endl;
    }
}

void printColumnWiseSum(int arr[][3], int rows, int cols) {
    cout << "Column-wise sum:" << endl;
    for(int i = 0; i < rows; i++) {
        int sum = 0;
        for(int j = 0; j < 3; j++) {
            sum += arr[j][i];
        }
        cout << sum << endl;
    }
}

bool findKey(int arr[][3], int rows, int cols, int key) {
    bool found = false;
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            if(arr[i][j] == key) {
                cout << "Key " << key << " found at position (" << i << ", " << j << ")." << endl;
                return true;
            }
        }
    }
    // If the key is not found
    return false;
}

int getMaxi(int arr[][3], int rows, int cols) {
    int maxi = INT_MAX;

    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            if(arr[i][j] > maxi) {
                maxi = arr[i][j];
            }
        }
    }
    return maxi;
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

    printRowWiseSum(arr, rows, cols);
    printColumnWiseSum(arr, rows, cols);

    int key = 5;
    if(findKey(arr, rows, cols, key)){
        cout << "Key " << key << " found in the array." << endl;
    } else {
        cout << "Key " << key << " not found in the array." << endl;
    }

    int maxElement = getMaxi(arr, rows, cols);
    cout << "Maximum element in the array is: " << maxElement << endl;

    return 0; // Return 0 to indicate successful execution
}