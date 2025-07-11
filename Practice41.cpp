#include <iostream>
using namespace std;

// =============================================================
// Function: binarySearch
// Purpose : To search for a target value in a 2D matrix using
//           binary search by treating the 2D matrix as a 1D array
// Time    : O(log(m * n)) where m is rows and n is columns
// =============================================================
bool binarySearch(int arr[][4], int rows, int cols, int target) {
    int s = 0;                    // Start index of 1D flattened array
    int e = rows * cols - 1;     // End index of flattened array
    int mid = s + (e - s) / 2;   // Middle index for binary search

    while (s <= e) {
        // Convert 1D index to 2D row and column index
        int rowIndex = mid / cols;
        int colIndex = mid % cols;

        // Check if the element at calculated index matches the target
        if (arr[rowIndex][colIndex] == target) {
            cout << "Element found at index: [" << rowIndex << "][" << colIndex << "]" << endl;
            return true; // Target found
        }

        // If current element is less than target, search in right half
        if (arr[rowIndex][colIndex] < target) {
            s = mid + 1;
        }
        // Else search in left half
        else {
            e = mid - 1;
        }

        // Recalculate mid after updating start or end
        mid = s + (e - s) / 2;
    }

    return false; // Target not found
}

// =============================================================
// Function: main
// Purpose : Driver function to demonstrate 2D binary search
// =============================================================
int main() {
    // Sample 2D array (5 rows × 4 columns)
    int arr[5][4] = {
        {1,  2,  3,  4},
        {5,  6,  7,  8},
        {9, 10, 11, 12},
        {13,14, 15,16},
        {17,18, 19,20}
    };

    int rows = 5;   // Number of rows
    int cols = 4;   // Number of columns

    int target = 19;  // Element to search for

    // Call the binarySearch function
    bool ans = binarySearch(arr, rows, cols, target);

    // Print the result
    if (ans) {
        cout << "Element found!" << endl;
    } else {
        cout << "Element not found!" << endl;
    }

    return 0; // Successful execution
}
