#include <iostream>
#include <vector>
using namespace std;

// Function to return matrix elements in spiral order
vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> result;

    int m = matrix.size();              // Number of rows
    int n = matrix[0].size();           // Number of columns
    int totalElements = m * n;          // Total elements in matrix

    int startingRow = 0;
    int startingCol = 0;
    int endingRow = m - 1;
    int endingCol = n - 1;

    int count = 0;

    while (count < totalElements) {
        // Print starting row
        for (int i = startingCol; i <= endingCol && count < totalElements; i++) {
            result.push_back(matrix[startingRow][i]);
            count++;
        }
        startingRow++;

        // Print ending column
        for (int i = startingRow; i <= endingRow && count < totalElements; i++) {
            result.push_back(matrix[i][endingCol]);
            count++;
        }
        endingCol--;

        // Print ending row
        for (int i = endingCol; i >= startingCol && count < totalElements; i--) {
            result.push_back(matrix[endingRow][i]);
            count++;
        }
        endingRow--;

        // Print starting column
        for (int i = endingRow; i >= startingRow && count < totalElements; i--) {
            result.push_back(matrix[i][startingCol]);
            count++;
        }
        startingCol++;
    }

    return result;
}

int main() {
    // Example input matrix
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    // Get the spiral order
    vector<int> result = spiralOrder(matrix);

    // Print the result
    cout << "Spiral Order: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
