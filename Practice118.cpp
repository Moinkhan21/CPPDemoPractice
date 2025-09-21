#include <iostream>
using namespace std;

// ---------------- FUNCTION: lastOccRTL ----------------
// Purpose: Find the last occurrence of a character `x` in string `s`
// by scanning from right to left recursively.
//
// Parameters:
//   s   -> reference to the input string
//   x   -> character to search for
//   i   -> current index in the string (starting from the rightmost index)
//   ans -> reference variable to store the last found index of x
//
// Working:
//   - The function begins at the end of the string (rightmost character).
//   - It checks each character moving leftwards (decreasing index).
//   - Once the target character is found, that index is stored in `ans`
//     and recursion stops immediately because the "first occurrence"
//     encountered from the right is indeed the last occurrence in the string.
void lastOccRTL(string& s, char x, int i, int& ans) {

    // ---------- BASE CASE ----------
    // If index goes out of bounds (less than 0),
    // stop recursion (character not found in this path).
    if(i < 0) {
        return;
    }

    // ---------- PROCESSING ONE CASE ----------
    // Check if current character matches the target `x`
    if(s[i] == x) {
        ans = i;       // Store the index of occurrence
        return;        // Stop further recursion as last occurrence is found
    }

    // ---------- RECURSIVE CALL ----------
    // Move one step leftwards in the string
    lastOccRTL(s, x, i - 1, ans);
}

int main() {
    // ---------- INPUT SECTION ----------
    string s;
    cout << "Enter string and character to find last occurrence (from right -> first occ is last occ for string): ";
    cin >> s;   // Input string

    char x;
    cout << "Enter character: ";
    cin >> x;   // Input target character

    // ---------- INITIALIZATION ----------
    int ans = -1;   // Default value: -1 means character not found
    int i = 0;      // Unused variable here, but initialized for clarity

    // ---------- FUNCTION CALL ----------
    // Start recursion from the last index (rightmost character of string)
    lastOccRTL(s, x, s.size() - 1, ans);

    // ---------- OUTPUT SECTION ----------
    // Display result index (or -1 if not found)
    cout << "Last occurrence of '" << x << "' is at index: " << ans << endl;

    return 0;
}
