#include <iostream>
#include <vector>
using namespace std;

int main() {

    // ─────────────────────────────────────────────────────────────
    // 🟢 Part 1: Create a 2D vector manually and push rows
    // ─────────────────────────────────────────────────────────────

    vector<vector<int>> arr;  // Declare a 2D vector (vector of vectors)

    // Create individual 1D vectors (rows)
    vector<int> a{1, 2, 3};
    vector<int> b{4, 5, 6};
    vector<int> c{7, 8, 9};

    // Add each 1D vector to the 2D vector
    arr.push_back(a);  // Add row a to arr
    arr.push_back(b);  // Add row b to arr
    arr.push_back(c);  // Add row c to arr

    // Print the manually created 2D vector
    cout << "2D Array using manual push_back:\n";
    for (int i = 0; i < arr.size(); i++) {
        for (int j = 0; j < arr[i].size(); j++) {
            cout << arr[i][j] << " ";  // Print each element in row
        }
        cout << endl;  // New line after each row
    }

    cout << endl;

    // ─────────────────────────────────────────────────────────────
    // 🟢 Part 2: Create a 2D vector with fixed size and default value
    // ─────────────────────────────────────────────────────────────

    int rows = 3;     // Number of rows
    int cols = 5;     // Number of columns

    // Create a 2D vector of size [rows][cols], initialized with value 101
    vector<vector<int>> arr1(rows, vector<int>(cols, 101));

    // Print the initialized 2D vector
    cout << "2D Array initialized with 101:\n";
    for (int i = 0; i < arr1.size(); i++) {
        for (int j = 0; j < arr1[i].size(); j++) {
            cout << arr1[i][j] << " ";  // Print each element
        }
        cout << endl;  // New line after each row
    }

    return 0;  // Program executed successfully
}
