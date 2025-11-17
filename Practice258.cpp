#include <iostream>
#include <stack>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

// ===============================================================
// FUNCTION: decodeString
// Decodes patterns like "3[a2[c]]" into "accaccacc"
// ===============================================================
string decodeString(string s) {
    stack<string> st;

    for (char ch : s) {

        // -----------------------------------------
        // CASE 1: Closing bracket ']' triggers decoding
        // -----------------------------------------
        if (ch == ']') {

            // 1️⃣ Extract substring to repeat
            string stringToRepeat = "";
            while (!st.empty() && st.top() != "[") {
                stringToRepeat = st.top() + stringToRepeat;  // FIX order
                st.pop();
            }

            // Pop the '['
            if (!st.empty()) st.pop();

            // 2️⃣ Extract number before '['
            string numericTimes = "";
            while (!st.empty() && isdigit(st.top()[0])) {
                numericTimes = st.top() + numericTimes;     // FIX order
                st.pop();
            }

            int n = stoi(numericTimes);

            // 3️⃣ Repeat the substring
            string decoded = "";
            while (n--) decoded += stringToRepeat;

            // Push back decoded chunk
            st.push(decoded);
        }
        else {
            // -----------------------------------------
            // CASE 2: Regular character or '[' or digit
            // Push as string
            // -----------------------------------------
            string temp(1, ch);
            st.push(temp);
        }
    }

    // Build final answer
    string ans = "";
    while (!st.empty()) {
        ans = st.top() + ans;  // FIX order
        st.pop();
    }

    return ans;
}

// ===============================================================
// MAIN FUNCTION — Testing decodeString()
// ===============================================================
int main() {
    vector<string> tests = {
        "3[a]",
        "3[a2[c]]",
        "2[abc]3[cd]ef",
        "10[a]",
        "3[z]2[2[y]pq4[2[jk]e1[f]]]ef"
    };

    for (string t : tests) {
        cout << "Input: " << t << endl;
        cout << "Decoded: " << decodeString(t) << endl;
        cout << "----------------------------------------\n";
    }

    return 0;
}
