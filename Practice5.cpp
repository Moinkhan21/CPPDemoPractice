#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;  // Input the number of rows (height of the upper triangle part)

    // Outer loop to iterate through 2*n rows
    for(int i = 0; i < 2 * n; i++) {
        
        // Determine how many stars (left side) should be printed based on current row 'i'
        // If i < n (upper half), cond = i
        // Else (lower half), cond = n + (n - i - 1) to mirror the upper half
        int cond = i < n ? i : n + (n - i - 1);

        // Determine the number of spaces between the left and right stars
        // If i < n (upper half), spaces decrease from top to middle
        // Else (lower half), spaces increase from middle to bottom
        int space_count = i < n ? 2 * (n - cond - 1) : i - cond - 1;

        // Inner loop to iterate through each column in a row (2*n columns)
        for(int j = 0; j < 2 * n; j++) {

            // Print the left group of stars: j should be less than or equal to cond
            if(j <= cond) {
                cout << "*";
            }

            // Print the spaces in the middle section if space_count is greater than 0
            else if(space_count > 0) {
                cout << " ";
                space_count--;  // Decrease space_count after printing a space
            }

            // After spaces are exhausted, print the remaining right side stars
            else {
                cout << "*";
            }
        }

        cout << endl;  // Move to the next row
    }
}
