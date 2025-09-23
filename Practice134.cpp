#include <iostream>
using namespace std;

// ---------------- FUNCTION: printPermutation ----------------
// Purpose: Generate and print all permutations of a given string
// using recursion and backtracking.
//
// Parameters:
//   str -> reference to the input string
//   i   -> current index for which we want to fix a character
//
// Approach:
//   - At each position `i`, try placing every character (from i..end).
//   - Swap the chosen character with str[i].
//   - Recursively call for the next index (i + 1).
//   - After recursion, swap back (backtracking) to restore original string.
//
// Base Case:
//   - When i >= str.length(), it means a full permutation is formed.
//     Print the string.
void printPermutation(string &str, int i){
    // ---------- BASE CASE ----------
    // If index goes beyond the length, print the current permutation
    if(i >= str.length()) {
        cout << str << " ";
        return;
    }

    // ---------- RECURSIVE CASE ----------
    // Loop through all characters from index i to end
    for(int j = i; j < str.length(); j++) {

        // Swap the current character with the ith character
        // This fixes one character at position i
        swap(str[i], str[j]);

        // Recursive call for the next position (i + 1)
        printPermutation(str, i + 1);
        
        // Backtracking step:
        // Swap back to restore original string before next iteration
        swap(str[i], str[j]);
    }
}

int main() {
    // ---------- INPUT SECTION ----------
    string str = "abc"; // Example string
    int i = 0;          // Start from first index

    // ---------- FUNCTION CALL ----------
    cout << "All permutations of \"" << str << "\": ";
    printPermutation(str, i);

    cout << endl;
    return 0;
}
