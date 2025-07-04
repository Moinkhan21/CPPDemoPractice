#include <iostream>
#include <vector>
using namespace std;

// Function to return matrix elements in spiral order
vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> result; // This will store the final spiral order output

    int m = matrix.size();              // Total number of rows
    int n = matrix[0].size();           // Total number of columns
    int totalElements = m * n;          // Total elements in the matrix

    // Initialize boundaries for spiral traversal
    int startingRow = 0;
    int startingCol = 0;
    int endingRow = m - 1;
    int endingCol = n - 1;

    int count = 0; // To track how many elements we have added to result

    // Loop until we have added all elements
    while (count < totalElements) {

        // -------- Traverse top row (left to right) --------
        for (int i = startingCol; i <= endingCol && count < totalElements; i++) {
            result.push_back(matrix[startingRow][i]); // Add element to result
            count++; // Increment element count
        }
        startingRow++; // Move top boundary down

        // -------- Traverse right column (top to bottom) --------
        for (int i = startingRow; i <= endingRow && count < totalElements; i++) {
            result.push_back(matrix[i][endingCol]); // Add element to result
            count++;
        }
        endingCol--; // Move right boundary left

        // -------- Traverse bottom row (right to left) --------
        for (int i = endingCol; i >= startingCol && count < totalElements; i--) {
            result.push_back(matrix[endingRow][i]); // Add element to result
            count++;
        }
        endingRow--; // Move bottom boundary up

        // -------- Traverse left column (bottom to top) --------
        for (int i = endingRow; i >= startingRow && count < totalElements; i--) {
            result.push_back(matrix[i][startingCol]); // Add element to result
            count++;
        }
        startingCol++; // Move left boundary right
    }

    return result; // Return the final spiral-ordered vector
}

int main() {
    // Example matrix to test spiral order
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    // Call the spiralOrder function and get the result
    vector<int> result = spiralOrder(matrix);

    // Display the result
    cout << "Spiral Order: ";
    for (int val : result) {
        cout << val << " "; // Print each element in spiral order
    }
    cout << endl;

    return 0; // Successful execution
}
