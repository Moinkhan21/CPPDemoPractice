#include <iostream>
#include <stack>
#include <string>
using namespace std;

// =====================================================
// ✅ Function: longestValidParentheses()
// -----------------------------------------------------
// Purpose:
//   Finds the **length of the longest valid (well-formed)**
//   substring of parentheses in the given string.
//
// Approach (Stack-Based):
//   🔹 Use a stack to store **indices** of characters.
//   🔹 Push -1 initially to handle edge cases like "()".
//   🔹 For each '(' → push its index.
//   🔹 For each ')' → pop an index (matching '(').
//   🔹 If stack becomes empty → push current index as new base.
//   🔹 Otherwise → calculate valid substring length using:
//          current_index - stack.top()
//
// Time Complexity:  O(n)
// Space Complexity: O(n)
// =====================================================
int longestValidParentheses(string s) {
    stack<int> st;       // Stack to store indices of '(' characters
    st.push(-1);         // Base index to handle first valid substring case
    int maxLen = 0;      // Stores maximum valid length found

    // Traverse each character in string
    for (int i = 0; i < s.length(); i++) {
        char ch = s[i];

        if (ch == '(') {
            // 🟢 Case 1: Opening bracket '(' — push its index onto stack
            st.push(i);
        }
        else {
            // 🔴 Case 2: Closing bracket ')'
            st.pop(); // Try to match it with the last '('

            // If stack becomes empty, there’s no valid base left
            if (st.empty()) {
                // Push current index as a new invalid base
                st.push(i);
            }
            else {
                // Valid substring found → calculate its length
                int len = i - st.top(); // distance from last unmatched index
                maxLen = max(maxLen, len);
            }
        }
    }

    return maxLen;
}

// =====================================================
// ✅ Main Function — Testing longestValidParentheses()
// =====================================================
int main() {
    // Different test cases to validate algorithm
    string s1 = "(()";        // Only "()" is valid → length = 2
    string s2 = ")()())";     // Longest valid substring = "()()" → length = 4
    string s3 = "((()))";     // Entire string is valid → length = 6
    string s4 = "())(())";    // Longest valid = "(())" → length = 4
    string s5 = "(()())";     // Entire string is valid → length = 6

    cout << "Input: " << s1 << " -> Longest Valid Parentheses Length = " << longestValidParentheses(s1) << endl;
    cout << "Input: " << s2 << " -> Longest Valid Parentheses Length = " << longestValidParentheses(s2) << endl;
    cout << "Input: " << s3 << " -> Longest Valid Parentheses Length = " << longestValidParentheses(s3) << endl;
    cout << "Input: " << s4 << " -> Longest Valid Parentheses Length = " << longestValidParentheses(s4) << endl;
    cout << "Input: " << s5 << " -> Longest Valid Parentheses Length = " << longestValidParentheses(s5) << endl;

    return 0;
}
