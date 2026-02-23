#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// =====================================================
// FUNCTION: getSubsequences
// -----------------------------------------------------
// PURPOSE:
//   Generates all possible subsequences of a given string
//   using Bit Manipulation.
//
// WHAT IS A SUBSEQUENCE?
//   A subsequence is a sequence derived from a string
//   by deleting some or no characters WITHOUT changing order.
//
//   Example:
//     str = "abc"
//     Subsequences:
//     "", "a", "b", "c", "ab", "ac", "bc", "abc"
//
// TOTAL SUBSEQUENCES:
//   For string of length n → 2^n subsequences
//
// APPROACH (BIT MASKING):
//   1️⃣ Each number from 0 to (2^n - 1) represents a subset
//   2️⃣ Binary representation tells which characters to include
//   3️⃣ If ith bit is set → include str[i]
//   4️⃣ Generate all combinations
//
// WHY THIS WORKS?
//   • Each bit acts like a "take or not take" decision
//
// TIME COMPLEXITY:
//   • O(2^n * n)
//
// SPACE COMPLEXITY:
//   • O(2^n * n)
// =====================================================
void getSubsequences(string str) {

    vector<string> ans;   // Stores all subsequences
    int n = str.length(); // Length of input string

    // -------------------------------------------------
    // LOOP: Iterate from 0 to 2^n - 1
    // Each number represents a subsequence
    // -------------------------------------------------
    for (int num = 0; num < (1 << n); num++) {

        string temp = ""; // Temporary string to build subsequence

        // -------------------------------------------------
        // INNER LOOP: Check each bit position
        // -------------------------------------------------
        for (int i = 0; i < n; i++) {

            char ch = str[i]; // Current character

            // -------------------------------------------------
            // CHECK: Is ith bit set in num?
            // -------------------------------------------------
            if (num & (1 << i)) {
                // If bit is 1 → include character
                temp.push_back(ch);
            }
        }

        // -------------------------------------------------
        // STORE subsequence
        // -------------------------------------------------
        // NOTE: This condition is always true (>= 0)
        // So it includes empty string also
        if (temp.length() >= 0) {
            ans.push_back(temp);
        }
    }

    // -------------------------------------------------
    // SORT subsequences lexicographically
    // -------------------------------------------------
    sort(ans.begin(), ans.end());

    // -------------------------------------------------
    // OUTPUT results
    // -------------------------------------------------
    cout << "Count of subsequences " << ans.size() << endl;
    cout << "Printing the subsequences" << endl;

    for (auto i : ans) {
        cout << i << endl;
    }
}

// =====================================================
// MAIN FUNCTION
// -----------------------------------------------------
// PURPOSE:
//   Entry point of program
//
// WORKING:
//   • Calls getSubsequences()
//   • Prints all subsequences of string
// =====================================================
int main() {

    string str = "abc";

    getSubsequences(str);

    return 0;
}