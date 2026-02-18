#include <iostream>
#include <string>
#include <unordered_map>
#include <climits>
using namespace std;

// =====================================================
// FUNCTION: smallestWindow
// -----------------------------------------------------
// PROBLEM:
//   Given a string 's' and a pattern 'p',
//   find the smallest substring in 's'
//   that contains all characters of 'p'.
//
//   If no such window exists, return "-1".
//
// EXAMPLE:
//   s = "timetopractice"
//   p = "toc"
//
//   Output: "toprac"
//
// APPROACH: SLIDING WINDOW (VARIABLE SIZE)
//
// IDEA:
//   1️⃣ Expand window (increase right pointer)
//   2️⃣ Track frequency of characters
//   3️⃣ When all characters are matched → shrink window
//   4️⃣ Update minimum window length
//
// WHY HASH MAP?
//   • To track frequency of characters in pattern and window
//
// TIME COMPLEXITY:
//   • O(N)
//
// SPACE COMPLEXITY:
//   • O(CHARSET)
// =====================================================
string smallestWindow(string s, string p) {

    int len1 = s.length();
    int len2 = p.length();

    int start = 0;        // Left pointer of window
    int ansIndex = -1;    // Starting index of answer
    int ansLen = INT_MAX; // Minimum window length

    // Edge case
    if (len1 < len2) {
        return "-1";
    }

    // -------------------------------------------------
    // Frequency maps
    // -------------------------------------------------
    unordered_map<char, int> strMap;  // current window
    unordered_map<char, int> patMap;  // pattern

    // -------------------------------------------------
    // STEP 1: Store pattern frequencies
    // -------------------------------------------------
    for (int i = 0; i < p.length(); i++) {
        char ch = p[i];
        patMap[ch]++;
    }

    int count = 0;  // number of matched characters

    // =================================================
    // STEP 2: Traverse string (expand window)
    // =================================================
    for (int i = 0; i < s.length(); i++) {

        char ch = s[i];

        // Add current character to window
        strMap[ch]++;

        // -------------------------------------------------
        // Check if current character is useful
        // -------------------------------------------------
        if (strMap[ch] <= patMap[ch]) {
            count++;
        }

        // -------------------------------------------------
        // STEP 3: When all characters matched
        // -------------------------------------------------
        if (count == len2) {

            // ---------------------------------------------
            // Shrink window to remove extra characters
            // ---------------------------------------------
            while (strMap[s[start]] > patMap[s[start]] ||
                   patMap[s[start]] == 0) {

                // Reduce frequency if extra
                if (strMap[s[start]] > patMap[s[start]])
                    strMap[s[start]]--;

                // Move left pointer
                start++;
            }

            // ---------------------------------------------
            // Update minimum window
            // ---------------------------------------------
            int lengthOfWindow = i - start + 1;

            if (lengthOfWindow < ansLen) {
                ansLen = lengthOfWindow;
                ansIndex = start;
            }
        }
    }

    // -------------------------------------------------
    // STEP 4: Return result
    // -------------------------------------------------
    if (ansIndex == -1)
        return "-1";
    else
        return s.substr(ansIndex, ansLen);
}

// =====================================================
// MAIN FUNCTION
// =====================================================
int main() {

    string s = "timetopractice";
    string p = "toc";

    string result = smallestWindow(s, p);

    cout << "Smallest window: " << result << endl;

    return 0;
}
