#include <iostream>
#include <climits> // For INT_MIN and INT_MAX
using namespace std;

// Function to print row-wise sum of a 2D array
void printRowWiseSum(int arr[][3], int rows, int cols) {
    cout << " Row-wise sum:\n";
    for(int i = 0; i < rows; i++) {
        int sum = 0; // Initialize sum for each row
        for(int j = 0; j < cols; j++) {
            sum += arr[i][j]; // Add elements of the row
        }
        cout << sum << endl; // Print row sum
    }
}

// Function to print column-wise sum of a 2D array
void printColumnWiseSum(int arr[][3], int rows, int cols) {
    cout << " Column-wise sum:\n";
    for(int i = 0; i < cols; i++) {
        int sum = 0; // Initialize sum for each column
        for(int j = 0; j < rows; j++) {
            sum += arr[j][i]; // Add elements of the column
        }
        cout << sum << endl; // Print column sum
    }
}

// Function to search for a key in a 2D array
bool findKey(int arr[][3], int rows, int cols, int key) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            if(arr[i][j] == key) {
                // Print the position and return true
                cout << " Key " << key << " found at position (" << i << ", " << j << ").\n";
                return true;
            }
        }
    }
    // If not found
    return false;
}

// Function to find the maximum element in the 2D array
int getMaxi(int arr[][3], int rows, int cols) {
    int maxi = INT_MIN; // Smallest possible value initially
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            if(arr[i][j] > maxi) {
                maxi = arr[i][j]; // Update max
            }
        }
    }
    return maxi;
}

// Function to find the minimum element in the 2D array
int getMini(int arr[][3], int rows, int cols) {
    int mini = INT_MAX; // Largest possible value initially
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            if(arr[i][j] < mini) {
                mini = arr[i][j]; // Update min
            }
        }
    }
    return mini;
}

// Function to transpose a 2D array
void transpose2DArray(int arr[][3], int rows, int cols, int transposedArr[][3]) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            transposedArr[j][i] = arr[i][j]; // Transpose logic
        }
    }
}

// Function to print a 2D array
void print2DArray(int arr[][3], int rows, int cols) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            cout << arr[i][j] << " "; // Print each element
        }
        cout << endl; // Move to next row
    }
}

int main() {
    int arr[3][3]; // Declare 3x3 array
    int rows = 3;
    int cols = 3;

    // ──────────────────────────────
    // Input the 3x3 matrix from user
    // ──────────────────────────────
    cout << "Enter elements for a 3x3 array:\n";
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            cin >> arr[i][j]; // Read input from user
        }
    }

    // ──────────────────────────────
    // Print the original array
    // ──────────────────────────────
    cout << "\n You entered:\n";
    print2DArray(arr, rows, cols);

    // ──────────────────────────────
    // Perform operations
    // ──────────────────────────────
    printRowWiseSum(arr, rows, cols);        // Row-wise sum
    printColumnWiseSum(arr, rows, cols);     // Column-wise sum

    // Search for a specific key
    int key = 5;
    if(findKey(arr, rows, cols, key)) {
        cout << " Key " << key << " found in the array.\n";
    } else {
        cout << " Key " << key << " not found in the array.\n";
    }

    // Find max and min elements
    int maxElement = getMaxi(arr, rows, cols);
    cout << " Maximum element in the array is: " << maxElement << endl;

    int minElement = getMini(arr, rows, cols);
    cout << " Minimum element in the array is: " << minElement << endl;

    // Transpose the array
    int transposedArr[3][3];
    transpose2DArray(arr, rows, cols, transposedArr);

    // ──────────────────────────────
    // Print the transposed array
    // ──────────────────────────────
    cout << "\n Transposed array:\n";
    print2DArray(transposedArr, rows, cols);

    return 0; // End of program
}
