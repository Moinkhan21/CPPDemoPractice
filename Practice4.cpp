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

    
    // Separator lines for clarity between patterns
    cout << "----------------------------------------" << endl;
    cout << "----------------------------------------" << endl;
    cout << "----------------------------------------" << endl;

    for (int i=0; i<n; i++) {
        int cond = i <= n/2 ? 2*i : 2*(n-i-1);  // Calculate the condition for the number of elements in each row
        for(int j=0; j<=cond; j++) {
            if(j<=cond/2) {
                cout << j+1;
            }
            else {
                cout << cond - j + 1;  // Print decreasing numbers after the middle
            }
        }
        cout << endl;  // Move to the next row
    }

    // Separator lines for clarity between patterns
    cout << "----------------------------------------" << endl;
    cout << "----------------------------------------" << endl;
    cout << "----------------------------------------" << endl;

    int a = 1; 
    for(int i = 0; i < n; i++) {
        for(int j=0; j<=i; j++) {
            cout << a << " ";  // Print the current number with a space
            a++;  // Increment the number for the next print
        }
        cout << endl;  // Move to the next row
    }

        // Separator lines for clarity between patterns
    cout << "----------------------------------------" << endl;
    cout << "----------------------------------------" << endl;
    cout << "----------------------------------------" << endl;

    for(int i=1; i<=n; i++) {
        int d=1;
        for(int j=1; j<=i; j++) {
            cout << d << " ";  // Print the current number with a space
            d = d*(i-j)/j;  // Calculate the next number in the row using binomial coefficient logic
        }
        cout << endl;  // Move to the next row
    }
}
