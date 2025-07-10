#include <iostream>
using namespace std;

bool binarySearch(int arr[][4], int rows, int cols, int target) {
    int s = 0;
    int e = rows * cols - 1;
    int mid = s + (e - s) / 2;

    while(s <= e) {
        int rowIndex = mid / cols; // Calculate the row index
        int colIndex = mid % cols;  // Calculate the column index

        if(arr[rowIndex][colIndex] == target) {
            cout << "Element found at index: [" << rowIndex << "][" << colIndex << "]" << endl;
            return true; // Element found
        }

        if(arr[rowIndex][colIndex] < target) {
            // Move to the right half
            s = mid + 1;
        } else {
            // Move to the left half
            e = mid - 1;
        }
        mid = s + (e - s) / 2; // Recalculate mid after updating s or e
    }
    return false; // Element not found
}

int main() {
    int arr[5][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16},
        {17, 18, 19, 20}
    };

    int rows = 5;
    int cols = 4;

    int target = 19;
    bool ans = binarySearch(arr, rows, cols, target);

    if (ans) {
        cout << "Element found!" << endl;
    } else {
        cout << "Element not found!" << endl;
    }

    return 0;
}