#include <iostream>
using namespace std;

// ---------------- FUNCTION: lastOccLTR ----------------
// Purpose: Find the last occurrence of a character `x` in string `s`
// by scanning from left to right recursively.
//
// Parameters:
//   s   -> reference to the input string
//   x   -> character to search for
//   i   -> current index in the string
//   ans -> reference variable to store the last found index of x
void lastOccLTR(string& s, char x, int i, int& ans) {

    // ---------- BASE CASE ----------
    // If index goes out of bounds (end of string reached),
    // stop recursion.
    if(i >= s.size()) {
        return;
    }

    // ---------- PROCESSING ONE CASE ----------
    // Check if current character matches the target `x`
    if(s[i] == x) {
        // Update answer with current index.
        // This ensures that the last matching index will overwrite
        // the previous ones as recursion progresses.
        ans = i;
    }

    // ---------- RECURSIVE CALL ----------
    // Move to the next character (left-to-right traversal).
    lastOccLTR(s, x, i + 1, ans);
}

int main() {
    string s;
    cout << "Enter string and character to find last occurrence from left: ";
    cin >> s;

    char x;
    cout << "Enter character: ";
    cin >> x; 

    // Initialize answer to -1 (default if character not found)
    int ans = -1;

    // Start recursion from index 0
    int i = 0;
    lastOccLTR(s, x, i, ans);

    // Print the result
    cout << "Last occurrence of '" << x << "' is at index: " << ans << endl;

    return 0;
}
