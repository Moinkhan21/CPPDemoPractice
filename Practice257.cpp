#include <iostream>
#include <stack>
using namespace std;

// =======================================================================
// FUNCTION: isValid
// -----------------------------------------------------------------------
// PURPOSE:
//   Validate whether a string can be produced **only** by repeatedly
//   inserting the substring "abc" into any position of a previously
//   valid string.
//
//   Example of valid strings:
//     "abc", "aabcbc", "abcabc", "aabcabcc"
//
// APPROACH:
//   Use a STACK to simulate "abc" formation:
//
//   1. 'a' starts a new potential "abc" block → push 'a'.
//   2. 'b' must follow an 'a' → push 'b' only if stack top is 'a'.
//   3. 'c' must close the pattern "abc":
//          stack must contain "ab" in order (top == 'b' and under that 'a')
//      When found → pop both 'b' and 'a'.
//   4. Any deviation makes string invalid.
//
//   If entire string processes correctly and stack becomes empty,
//   it is guaranteed that the string is a valid combination of "abc" blocks.
//
// Time Complexity:  O(n)
// Space Complexity: O(n)
// =======================================================================
bool isValid(string s) {

    // -------------------------------
    // Quick invalid cases:
    // -------------------------------
    if (s.size() == 0) return false;     // Empty string cannot produce "abc"
    if (s[0] != 'a') return false;       // Valid string must always start with 'a'

    stack<char> st;                      // Stack to track progressive formation

    // -------------------------------
    // Process every character
    // -------------------------------
    for (char ch : s) {

        // -----------------------------------------------------
        // Case 1: 'a'
        // Always valid. 'a' begins a new "abc" pattern.
        // -----------------------------------------------------
        if (ch == 'a') {
            st.push('a');
        }

        // -----------------------------------------------------
        // Case 2: 'b'
        // 'b' is valid ONLY when it immediately follows 'a'.
        // -----------------------------------------------------
        else if (ch == 'b') {

            // Check if stack top has a matching 'a'
            if (!st.empty() && st.top() == 'a') {
                st.push('b');           // Continue forming "ab"
            } 
            else {
                return false;           // No 'a' before 'b' → invalid
            }
        }

        // -----------------------------------------------------
        // Case 3: 'c'
        // 'c' completes the pattern: must match top "b" and below "a"
        // -----------------------------------------------------
        else if (ch == 'c') {

            // Verify stack top is 'b'
            if (!st.empty() && st.top() == 'b') {

                st.pop();               // Remove 'b'

                // Now stack must contain an 'a' beneath
                if (!st.empty() && st.top() == 'a') {
                    st.pop();           // Remove 'a' → complete "abc"
                }
                else {
                    return false;       // 'c' found but no matching 'a'
                }
            }
            else {
                return false;           // Wrong order for 'c'
            }
        }

        // -----------------------------------------------------
        // Case 4: Invalid character
        // -----------------------------------------------------
        else {
            return false;
        }
    }

    // -----------------------------------------------------
    // FINAL CHECK:
    // After processing, stack must be empty.
    //
    // Why?
    //   A valid string must be completely reducible into "abc"
    //   blocks, each fully removed during processing.
    // -----------------------------------------------------
    return st.empty();
}

// =======================================================================
// MAIN FUNCTION — Testing isValid() with multiple inputs
// =======================================================================
int main() {
    string tests[] = {
        "abc",
        "aabcbc",
        "abcabc",
        "aabcabcc",
        "ac",
        "abcc",
        "aabbcc",
        "",
        "bac",
        "ab",
        "cab"
    };

    for (string s : tests) {
        cout << "Input: " << s
             << " --> " << (isValid(s) ? "Valid" : "Invalid")
             << endl;
    }

    return 0;
}
