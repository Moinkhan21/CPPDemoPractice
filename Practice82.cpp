#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
    Function: convert
    Purpose:
        Convert a given string `s` into a "zigzag" pattern 
        based on the given number of rows (numRows) and then 
        read the zigzag row by row to produce the final string.
    Example:
        s = "HelloWorld", numRows = 3

        Pattern:
        H   l   o   r
        e l W l d
        l   o

        Output = "Hlo r elWld lo" (without spaces)
*/
string convert(string s, int numRows) {
    // If numRows is 1, the zigzag is just the original string
    if (numRows == 1) return s;

    // Vector of strings to store characters for each row in the zigzag
    vector<string> zigzag(numRows);

    int i = 0;           // Index to iterate through characters of s
    int row = 0;         // Current row in the zigzag
    bool direction = 1;  // Direction flag: true = going downwards, false = going upwards

    // Loop until all characters are placed in zigzag rows
    while (true) {
        if (direction) { // Moving from top row to bottom row
            while (row < numRows && i < s.size()) {
                zigzag[row++].push_back(s[i++]); // Place character in current row, move down
            }
            row = numRows - 2; // After reaching bottom, move up to the second-last row
        }
        else { // Moving from bottom row to top row
            while (row >= 0 && i < s.size()) {
                zigzag[row--].push_back(s[i++]); // Place character in current row, move up
            }
            row = 1; // After reaching top, move down to the second row
        }

        // Stop if we have placed all characters
        if (i >= s.size()) break;

        // Change direction after completing one vertical move
        direction = !direction;
    }

    // Combine all rows into one final result string
    string result = "";
    for (int i = 0; i < numRows; i++) {
        result += zigzag[i];
        cout << zigzag[i] << endl; // Debugging: Print each row's content to visualize zigzag
    }

    return result;
}

int main() {
    string str = "Hello, World!";
    cout << convert(str, 3) << endl; // Convert string into zigzag with 3 rows
    return 0;
}
