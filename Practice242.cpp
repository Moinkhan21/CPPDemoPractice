#include <iostream>
#include <stack>
using namespace std;

// ======================================================
// ✅ Function: isValid()
// ------------------------------------------------------
// Purpose:
//   Checks whether a given string of parentheses, curly
//   braces, and square brackets is balanced or not.
// ------------------------------------------------------
// Logic:
//   1️⃣ Use a stack to store opening brackets.
//   2️⃣ When a closing bracket appears, check if it matches
//       the top of the stack (latest unclosed bracket).
//   3️⃣ If at the end the stack is empty → string is valid.
// ======================================================
bool isValid(string s) {
    stack<char> st; // Stack used for keeping track of opening brackets

    // ------------------------------------------
    // Loop through each character in the string
    // ------------------------------------------
    for (int i = 0; i < s.length(); i++) {
        char ch = s[i];

        // ------------------------------------------
        // Case 1️⃣: If it's an opening bracket, push it to stack
        // ------------------------------------------
        if (ch == '(' || ch == '{' || ch == '[') {
            st.push(ch);
        }
        // ------------------------------------------
        // Case 2️⃣: If it's a closing bracket, validate it
        // ------------------------------------------
        else {
            // If stack is not empty, we can check for a matching opening bracket
            if (!st.empty()) {
                char topCh = st.top(); // Look at the top of the stack

                // ✅ Check for a valid matching pair
                if ((ch == ')' && topCh == '(') ||
                    (ch == '}' && topCh == '{') ||
                    (ch == ']' && topCh == '[')) {
                    st.pop(); // Remove the matching opening bracket
                } else {
                    // ❌ Mismatch found — invalid string
                    return false;
                }
            } else {
                // ❌ Stack is empty but a closing bracket is found → invalid
                return false;
            }
        }
    }

    // ------------------------------------------
    // After processing all characters:
    // ✅ If stack is empty → all brackets matched correctly.
    // ❌ Otherwise → there are unmatched opening brackets.
    // ------------------------------------------
    return st.empty();
}

// ======================================================
// ✅ Main Function
// ------------------------------------------------------
// Tests the isValid() function with multiple examples.
// ======================================================
int main() {
    string s1 = "{[()]}";   // ✅ Balanced
    string s2 = "{[(])}";   // ❌ Not balanced
    string s3 = "(({}[]))"; // ✅ Balanced
    string s4 = "({[})";    // ❌ Not balanced

    cout << "Testing valid/invalid parentheses:" << endl;

    cout << s1 << " -> " << (isValid(s1) ? "Valid" : "Invalid") << endl;
    cout << s2 << " -> " << (isValid(s2) ? "Valid" : "Invalid") << endl;
    cout << s3 << " -> " << (isValid(s3) ? "Valid" : "Invalid") << endl;
    cout << s4 << " -> " << (isValid(s4) ? "Valid" : "Invalid") << endl;

    return 0;
}
