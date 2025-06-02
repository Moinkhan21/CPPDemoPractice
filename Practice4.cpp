#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;  // Input: number of rows (levels) for the patterns
    int c = 1; // Initialize counter to print increasing numbers

    // ---------------------- FIRST TRIANGLE ------------------------
    // This loop prints a left-aligned triangle with increasing numbers
    // Example for n=4:
    // 1
    // 23
    // 456
    // 78910

    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= i; j++) {
            cout << c;  // Print the current number
            c++;        // Increment number for next print
            if (j<i) {
                cout << "*";  // Print a star after each number except the last in the row
            }
        }
        cout << endl;   // Move to the next row
    }

    // ---------------------- SECOND TRIANGLE -----------------------
    // Now we print an inverted triangle using decreasing row lengths
    // The pattern starts from a calculated 'start' value to maintain continuity

    int start = c - n; // Set the start value for second triangle
                       // For n=4, c=11 (from previous triangle), so start=7

    for(int i = 0; i < n; i++) {
        int k = start; // Reset k for each row
        for(int j = 0; j <= n - i - 1; j++) {
            cout << k;  // Print the current number
            k++;        // Increment for next column in the row
            if(j < n - i - 1) {
                cout << "*";  // Print a star after each number except the last in the row
            }
        }
        // Update 'start' for the next row:
        // Each time, decrease by the number of elements printed in the current row
        start = start - (n - i - 1);
        cout << endl;   // Move to the next row
    }

    return 0;
}
