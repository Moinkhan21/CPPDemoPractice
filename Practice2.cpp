#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;  // Input the size (number of rows or levels for the patterns)

    // ---------------- Pattern 1 ----------------
    // Print a left-aligned triangle:
    // Print number at start, end of each row, and full last row. Rest are spaces.
    /*
        Sample for n = 5:
        1
        12
        1 3
        1  4
        12345
    */
    for(int row = 0; row < n; row++) {
        for(int col = 0; col <= row; col++) {
            // If it's the first column, last column, or last row — print number
            if(col == 0 || col == row || row == n - 1) {
                cout << col + 1;  // Numbers start from 1
            } else {
                cout << " ";  // Empty spaces in between
            }
        }
        cout << endl;  // Move to next row
    }

    // Separator lines for clarity between patterns
    cout << "----------------------------------------" << endl;
    cout << "----------------------------------------" << endl;
    cout << "----------------------------------------" << endl;

    // ---------------- Pattern 2 ----------------
    // Print an inverted right-aligned triangle:
    // Print number at start and end of each row, and full top row. Rest are spaces.
    /*
        Sample for n = 5:
        12345
        2  5
        3 5
        45
        5
    */
    for(int i = 0; i < n; i++) {
        for (int j = i + 1; j <= n; j++) {
            // Print at boundaries (first column of this row, last column, or top row)
            if(j == i + 1 || j == n || i == 0) {
                cout << j;  // Print the number directly
            } else {
                cout << " ";  // In-between space
            }
        }
        cout << endl;
    }

    // Separator lines for clarity between patterns
    cout << "----------------------------------------" << endl;
    cout << "----------------------------------------" << endl;
    cout << "----------------------------------------" << endl;

    // ---------------- Pattern 3 ----------------
    // Print a centered pyramid with numbers increasing then decreasing
    /*
        Sample for n = 5:
            1
           123
          12321
         1234321
        123454321
    */
    int k = n;  // 'k' is total columns per row and increases each row to center the pyramid

    for(int i = 0; i < n; i++) {
        int c = 1;  // Start counting from 1

        for(int j = 0; j < k; j++) {
            if(j < n - i - 1) {
                cout << " ";  // Leading spaces for pyramid shape
            }
            else if(j <= n - 1) {
                cout << c;  // Left half numbers (increasing part)
                c++;
            }
            else if(j == n) {
                c = c - 2;   // Setup for center to right half (start from second last number)
                cout << c;
                c--;
            }
            else {
                cout << c;  // Right half numbers (decreasing part)
                c--;
            }
        }

        k++;  // Increment total columns for the next row
        cout << endl;  // Move to next row
    }

    // Separator lines for clarity between patterns
    cout << "----------------------------------------" << endl;
    cout << "----------------------------------------" << endl;
    cout << "----------------------------------------" << endl;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < i+1; j++) {
            cout << "*";
        }
        cout << endl;
    }
    for (int i= n - 1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            cout << "*";
        }
        cout << endl;
    }
}
