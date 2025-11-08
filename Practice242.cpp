#include <iostream>
#include <stack>
using namespace std;

// =====================================
// ✅ Function: isValid()
// Checks if all types of parentheses (), {}, [] are balanced.
// =====================================
bool isValid(string s) {
    stack<char> st; // stack to store opening brackets

    for (int i = 0; i < s.length(); i++) {
        char ch = s[i];

        // ✅ Case 1: Opening bracket — push to stack
        if (ch == '(' || ch == '{' || ch == '[') {
            st.push(ch);
        }
        else {
            // ✅ Case 2: Closing bracket
            if (!st.empty()) {
                char topCh = st.top();

                // ✅ Check if top of stack matches the closing bracket
                if ((ch == ')' && topCh == '(') ||
                    (ch == '}' && topCh == '{') ||
                    (ch == ']' && topCh == '[')) {
                    st.pop(); // Matching pair found — remove from stack
                }
                else {
                    // ❌ Mismatch found
                    return false;
                }
            }
            else {
                // ❌ Stack empty but closing bracket found — invalid
                return false;
            }
        }
    }

    // ✅ If stack is empty, all brackets matched correctly
    return st.empty();
}

// =====================================
// ✅ Main Function
// =====================================
int main() {
    string s1 = "{[()]}";   // Valid string
    string s2 = "{[(])}";   // Invalid string
    string s3 = "(({}[]))"; // Valid string
    string s4 = "({[})";    // Invalid string

    cout << "Testing valid/invalid parentheses:" << endl;

    cout << s1 << " → " << (isValid(s1) ? "Valid ✅" : "Invalid ❌") << endl;
    cout << s2 << " → " << (isValid(s2) ? "Valid ✅" : "Invalid ❌") << endl;
    cout << s3 << " → " << (isValid(s3) ? "Valid ✅" : "Invalid ❌") << endl;
    cout << s4 << " → " << (isValid(s4) ? "Valid ✅" : "Invalid ❌") << endl;

    return 0;
}
