#include <iostream>
#include <vector>
using namespace std;

/**
 * Function to print the elements of a 2D matrix in a wave pattern.
 * The wave pattern is defined as:
 * - For even-indexed columns: print top to bottom
 * - For odd-indexed columns: print bottom to top
 *
 * Example:
 * Input matrix:
 * 1   2   3   4
 * 5   6   7   8
 * 9  10  11  12
 *
 * Output (Wave Print):
 * 1 5 9 10 6 2 3 7 11 12 8 4
 */
void wavePrintMatrix(vector<vector<int>> v) {
    int m = v.size();       // Total number of rows
    int n = v[0].size();    // Total number of columns (assumes all rows have equal columns)

    // Iterate through each column one by one
    for (int startCol = 0; startCol < n; startCol++) {
        
        // If the column index is even: print from top to bottom
        if ((startCol & 1) == 0) { // Using bitwise AND to check if column is even
            for (int i = 0; i < m; i++) {
                cout << v[i][startCol] << " "; // Print each element in the column from top to bottom
            }
        }
        // If the column index is odd: print from bottom to top
        else {
            for (int i = m - 1; i >= 0; i--) {
                cout << v[i][startCol] << " "; // Print each element in the column from bottom to top
            }
        }
    }
}

// ---------- MAIN FUNCTION ----------
int main() {
    // Initialize a 2D vector (3x4 matrix)
    vector<vector<int>> v {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };

    // Call function to print wave pattern
    wavePrintMatrix(v);

    return 0; // Indicate successful execution
}
