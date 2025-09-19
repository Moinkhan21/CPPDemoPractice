#include <iostream>
#include <string>
using namespace std;

// Recursive helper function to check if string `s` matches pattern `p`
bool isMatchHelper(string &s, int si, string &p, int pi) {
    // ---------------------- BASE CASES ----------------------

    // Case 1: Both string `s` and pattern `p` are fully traversed → it's a match
    if (si == s.size() && pi == p.size()) {
        return true;
    }

    // Case 2: String `s` is finished but pattern `p` still has characters left
    if (si == s.size() && pi < p.size()) {
        // Remaining characters in `p` must all be '*', 
        // because '*' can represent empty sequence
        while (pi < p.size()) {
            if (p[pi] != '*') return false; // If non-* char remains → not a match
            pi++;
        }
        return true; // All remaining are '*', so it's a match
    }

    // ---------------------- MATCHING LOGIC ----------------------

    // Case 3: Current characters match directly
    // OR pattern has '?' (which matches any single character)
    if (s[si] == p[pi] || p[pi] == '?') {
        // Move both pointers forward
        return isMatchHelper(s, si + 1, p, pi + 1);
    }

    // Case 4: Current pattern character is '*'
    if (p[pi] == '*') {
        // '*' can represent:
        
        // (A) Empty sequence → move only pattern pointer forward
        bool caseA = isMatchHelper(s, si, p, pi + 1);

        // (B) '*' consumes one character of string `s`
        // → move string pointer forward but keep pattern pointer same
        bool caseB = isMatchHelper(s, si + 1, p, pi);

        return caseA || caseB; // Match found if any case is true
    }

    // ---------------------- NO MATCH CASE ----------------------

    // If current characters don't match and it's not '?', not '*'
    return false;
}

// Main function wrapper
bool isMatch(string s, string p) {
    int si = 0; // Pointer for string
    int pi = 0; // Pointer for pattern

    return isMatchHelper(s, si, p, pi);
}

int main() {
    string s, p;

    // Input: string and pattern
    // Example:
    // Input: abefcdgiescdfimde  ab*cd?i*de
    // Output: Match!
    cin >> s >> p;

    // Check match and print result
    if (isMatch(s, p)) {
        cout << "Match!" << endl;
    } else {
        cout << "No match!" << endl;
    }

    return 0;
}
