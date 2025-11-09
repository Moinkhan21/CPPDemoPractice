#include <iostream>
#include <stack>
#include <string>
using namespace std;

// =============================================
// ✅ Function: longestValidParentheses
// Returns the length of the longest valid substring
// of parentheses in a given string.
// =============================================
int longestValidParentheses(string s) {
    stack<int> st;       // Stack stores indices of '('
    st.push(-1);         // Initial base index
    int maxLen = 0;      // Stores max valid length found so far

    for (int i = 0; i < s.length(); i++) {
        char ch = s[i];

        if (ch == '(') {
            // Push index of '('
            st.push(i);
        }
        else {
            // Pop one matching '(' index
            st.pop();

            // If stack is empty, push current index as new base
            if (st.empty()) {
                st.push(i);
            }
            else {
                // Calculate current valid substring length
                int len = i - st.top();
                maxLen = max(maxLen, len);
            }
        }
    }

    return maxLen;
}

// =============================================
// ✅ Main Function — Test the Algorithm
// =============================================
int main() {
    // Test cases
    string s1 = "(()";
    string s2 = ")()())";
    string s3 = "((()))";
    string s4 = "())(())";
    string s5 = "(()())";

    cout << "Input: " << s1 << " → Longest Valid Parentheses Length = " << longestValidParentheses(s1) << endl;
    cout << "Input: " << s2 << " → Longest Valid Parentheses Length = " << longestValidParentheses(s2) << endl;
    cout << "Input: " << s3 << " → Longest Valid Parentheses Length = " << longestValidParentheses(s3) << endl;
    cout << "Input: " << s4 << " → Longest Valid Parentheses Length = " << longestValidParentheses(s4) << endl;
    cout << "Input: " << s5 << " → Longest Valid Parentheses Length = " << longestValidParentheses(s5) << endl;

    return 0;
}
