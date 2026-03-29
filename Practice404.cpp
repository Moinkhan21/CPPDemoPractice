#include <iostream>
using namespace std;

// ======================================================================
// PROGRAM: Pyramid Number Pattern
// ----------------------------------------------------------------------
// PURPOSE:
//   Prints a pyramid pattern with increasing and then decreasing numbers.
//
// EXAMPLE (n = 4):
//
//        1
//       121
//      12321
//     1234321
//
// APPROACH:
//   1. Print spaces
//   2. Print increasing numbers
//   3. Print decreasing numbers
//
// TIME COMPLEXITY: O(n²)
// ======================================================================
int main() {

    int n;
    cout << "Enter number of rows: ";
    cin >> n;

    // --------------------------------------------------
    // Outer loop → rows
    // --------------------------------------------------
    for (int i = 0; i < n; i++) {

        // --------------------------------------------------
        // Step 1: Print spaces
        // --------------------------------------------------
        for (int j = 0; j < n - i - 1; j++) {
            cout << " ";
        }

        // --------------------------------------------------
        // Step 2: Print increasing numbers
        // --------------------------------------------------
        for (int j = 0; j < i + 1; j++) {
            cout << j + 1;
        }

        // --------------------------------------------------
        // Step 3: Print decreasing numbers
        // --------------------------------------------------
        int start = i;
        for (int j = i; j >= 1; j--) {
            cout << start;
            start--;
        }

        cout << endl;
    }

    return 0;
}