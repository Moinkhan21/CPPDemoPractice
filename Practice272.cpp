#include <iostream>
#include <queue>
using namespace std;

// =====================================================================
// FUNCTION: solve
// PURPOSE:
//   Given a stream of lowercase characters (string),
//   return a new string where for each character processed,
//   we append the FIRST non-repeating character seen so far.
//   If no such character exists, append '#'.
//
//   Example:  str = "aabc"
//     Step 1 → 'a'   → first non-repeating = 'a'
//     Step 2 → "aa"  → no non-repeating   = '#'
//     Step 3 → "aab" → first non-repeating = 'b'
//     Step 4 → "aabc"→ first non-repeating = 'b'
//
// METHOD:
//   - Maintain a frequency array of 26 chars.
//   - Maintain a queue to track character order.
//   - For each char:
//       • Increment frequency
//       • Push into queue
//       • Pop from queue until front becomes non-repeating
// =====================================================================
string solve(string str) {

    int freq[26] = {0};   // Frequency map for 'a' to 'z'
    queue<char> q;        // Queue to maintain order of characters
    string ans = "";      // Final answer string

    // ---------------------------------------------------------------
    // Process each character from the stream
    // ---------------------------------------------------------------
    for (int i = 0; i < str.length(); i++) {

        char ch = str[i];

        // Step 1: Increment frequency of current character
        freq[ch - 'a']++;

        // Step 2: Push current character into queue
        q.push(ch);

        // -----------------------------------------------------------
        // Step 3: Remove repeating characters from the front
        //         Keep popping until front of queue becomes
        //         a character with frequency 1 (non-repeating)
        // -----------------------------------------------------------
        while (!q.empty()) {

            // If front character repeats, remove it
            if (freq[q.front() - 'a'] > 1) {
                q.pop();
            }
            else {
                // First non-repeating character found
                ans.push_back(q.front());
                break;
            }
        }

        // -----------------------------------------------------------
        // Step 4: If queue becomes empty → no non-repeating character
        // -----------------------------------------------------------
        if (q.empty()) {
            ans.push_back('#');
        }
    }

    return ans;
}

// =====================================================================
// MAIN — Test solve()
// =====================================================================
int main() {

    string str = "aabc";

    cout << "Final Ans: " << solve(str) << endl;

    return 0;
}
