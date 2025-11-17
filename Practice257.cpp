#include <iostream>
#include <stack>
using namespace std;

// =========================================================
// FUNCTION: isValid
// Validates if string is formed by repeatedly adding "abc"
// =========================================================
bool isValid(string s) {

    if (s.size() == 0) return false;  
    if (s[0] != 'a') return false;    // Valid string must start with 'a'

    stack<char> st;

    for (char ch : s) {

        if (ch == 'a') {
            st.push('a');
        }

        else if (ch == 'b') {
            // 'b' must come after 'a'
            if (!st.empty() && st.top() == 'a') {
                st.push('b');
            } else {
                return false;
            }
        }

        else if (ch == 'c') {
            // To form "abc", we need "ab" on stack
            if (!st.empty() && st.top() == 'b') {
                st.pop(); // pop 'b'

                if (!st.empty() && st.top() == 'a')
                    st.pop();  // pop 'a'
                else
                    return false;
            }
            else {
                return false;
            }
        }

        else {
            // invalid character
            return false;
        }
    }

    // stack must be empty if valid "abc" sequence
    return st.empty();
}

// =========================================================
// MAIN FUNCTION — Test isValid()
// =========================================================
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
