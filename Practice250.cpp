#include <iostream>
#include <stack>
using namespace std;

// ===============================================================
// ✅ Function: countRec()
// ---------------------------------------------------------------
// Purpose:
//   Counts the minimum number of reversals needed to balance a 
//   string of curly braces '{' and '}'. 
//
// Key Observations:
//   - If string length is odd → it's impossible to balance, return -1.
//   - Use a stack to remove already balanced "{}" pairs.
//   - The remaining stack will only contain unbalanced brackets.
//   - Pair up remaining braces and calculate the number of reversals.
//
// Example:
//   Input  → "}{{}}{{{"
//   Output → 3  (Explanation below)
//
// Time Complexity:  O(n)
// Space Complexity: O(n)
// ===============================================================
int countRec(string s) {
    // ✅ Step 1: Check for impossible cases (odd length)
    if (s.size() & 1) return -1; // Odd-length string can never be balanced

    int ans = 0;           // To store minimum reversals required
    stack<char> st;        // Stack to hold unbalanced braces

    // ✅ Step 2: Remove balanced pairs "{}"
    for (char ch : s) {
        if (ch == '{') {
            // Opening brace → push into stack
            st.push(ch);
        } else {
            // Closing brace '}' encountered
            if (!st.empty() && st.top() == '{') {
                // Found a balanced pair "{}" → remove it
                st.pop();
            } else {
                // Unbalanced closing brace → push to stack
                st.push(ch);
            }
        }
    }

    // ✅ Step 3: Now, stack contains only unbalanced braces like "{{{{" or "}}}{{"
    // We'll count reversals to balance them
    while (!st.empty()) {
        char a = st.top(); st.pop(); // First unbalanced brace
        char b = st.top(); st.pop(); // Second unbalanced brace

        // If both braces are same (like "{{" or "}}"), only one reversal needed
        if (a == b)
            ans += 1;
        else
            // If they are different ("}{" → need 2 reversals)
            ans += 2;
    }

    return ans; // Return the minimum number of reversals needed
}

// ===============================================================
// ✅ Main Function — Testing countRec()
// ===============================================================
int main() {
    string s1 = "}{{}}{{{"; // → 3
    string s2 = "{{{{";     // → 2
    string s3 = "{{{{}}";   // → -1 (odd length, impossible to balance)
    string s4 = "{{{{}}}}"; // → 0 (already balanced)
    string s5 = "}{}{}{{";  // → 1

    cout << "Minimum reversals required to balance braces:\n";
    cout << "----------------------------------------------\n";
    cout << "Input: " << s1 << " -> Reversals needed: " << countRec(s1) << endl;
    cout << "Input: " << s2 << " -> Reversals needed: " << countRec(s2) << endl;
    cout << "Input: " << s3 << " -> Reversals needed: " << countRec(s3) << endl;
    cout << "Input: " << s4 << " -> Reversals needed: " << countRec(s4) << endl;
    cout << "Input: " << s5 << " -> Reversals needed: " << countRec(s5) << endl;

    return 0;
}
