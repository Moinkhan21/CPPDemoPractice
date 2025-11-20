#include <iostream>
#include <stack>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

// =====================================================================================================
// FUNCTION: decodeString
// -----------------------------------------------------------------------------------------------------
// PURPOSE:
//   Decode encoded strings of the form:
//       k[encoded_string]
//   Where the encoded_string inside the square brackets is repeated k times.
//
//   Examples:
//       "3[a]"          → "aaa"
//       "3[a2[c]]"      → "accaccacc"
//       "2[abc]3[cd]ef" → "abcabccdcdcdef"
//
// APPROACH (Using a Stack):
//   We scan the string character-by-character.
//
//   • Push characters (digits, letters, '[') onto a stack as strings.
//   • When we encounter ']', we perform decoding:
//         1. Pop until '[' → this builds the substring to repeat.
//         2. Pop digits before '[' → this gives the repetition count.
//         3. Repeat substring count times.
//         4. Push the decoded substring back onto the stack.
//
//   • At the end, stack contains pieces of final decoded string.
//     Concatenate all to get the result.
//
// WHY THIS WORKS:
//   Nested structures (e.g., 3[a2[c]]) are naturally handled by stack because the inner-most
//   pattern is always decoded first, then pushed back for outer processing.
//
// Time Complexity:  O(n * k)   (k is repetition factor)
// Space Complexity: O(n)
// =====================================================================================================
string decodeString(string s) {
    stack<string> st;   // Stack stores digits, "[", and partial decoded substrings

    for (char ch : s) {

        // -----------------------------------------------------------
        // CASE 1: Found closing bracket ']'
        //         → time to decode the pattern inside [... ]
        // -----------------------------------------------------------
        if (ch == ']') {

            // -------------------------------------------
            // STEP 1: Extract the substring inside brackets
            //         Example: if stack has ["a", "[", "c", "c"]
            //         We pop until we reach "[".
            // -------------------------------------------
            string stringToRepeat = "";
            while (!st.empty() && st.top() != "[") {
                stringToRepeat = st.top() + stringToRepeat;  
                st.pop();
            }

            // Pop the '['
            if (!st.empty()) st.pop();

            // -------------------------------------------
            // STEP 2: Extract the number before '['
            //         This number may contain multiple digits.
            //         Example: "12[abc]" → numericTimes = "12"
            // -------------------------------------------
            string numericTimes = "";
            while (!st.empty() && isdigit(st.top()[0])) {
                numericTimes = st.top() + numericTimes;
                st.pop();
            }

            int n = stoi(numericTimes);  // convert to integer

            // -------------------------------------------
            // STEP 3: Construct the decoded string
            // -------------------------------------------
            string decoded = "";
            while (n--) decoded += stringToRepeat;

            // Push back the entire decoded chunk to stack
            st.push(decoded);
        }

        // -----------------------------------------------------------
        // CASE 2: Regular character, digit, or '['
        //         → push it onto the stack as string
        // -----------------------------------------------------------
        else {
            string temp(1, ch);
            st.push(temp);
        }
    }

    // =====================================================================
    // FINAL STEP:
    // The stack now contains the decoded pieces in correct order.
    // Just concatenate them to form the final answer.
    // =====================================================================
    string ans = "";
    while (!st.empty()) {
        ans = st.top() + ans;   // build from left to right
        st.pop();
    }

    return ans;
}

// =====================================================================================================
// MAIN FUNCTION — Testing decodeString()
// =====================================================================================================
int main() {
    vector<string> tests = {
        "3[a]",
        "3[a2[c]]",
        "2[abc]3[cd]ef",
        "10[a]",
        "3[z]2[2[y]pq4[2[jk]e1[f]]]ef"
    };

    for (string t : tests) {
        cout << "Input:   " << t << endl;
        cout << "Decoded: " << decodeString(t) << endl;
        cout << "------------------------------------------------------\n";
    }

    return 0;
}
