#include <iostream>
#include <string>
#include <unordered_map>
#include <climits>
using namespace std;

string smallestWindow(string s, string p) {

    int len1 = s.length();
    int len2 = p.length();

    int start = 0;
    int ansIndex = -1;
    int ansLen = INT_MAX;

    if (len1 < len2) {
        return "-1";
    }

    unordered_map<char, int> strMap;
    unordered_map<char, int> patMap;

    // Store pattern frequencies
    for (int i = 0; i < p.length(); i++) {
        char ch = p[i];
        patMap[ch]++;
    }

    int count = 0;

    for (int i = 0; i < s.length(); i++) {

        char ch = s[i];
        strMap[ch]++;

        // Valid character
        if (strMap[ch] <= patMap[ch]) {
            count++;
        }

        // All characters matched
        if (count == len2) {

            // Minimize window
            while (strMap[s[start]] > patMap[s[start]] || patMap[s[start]] == 0) {

                if (strMap[s[start]] > patMap[s[start]])
                    strMap[s[start]]--;

                start++;
            }

            // Update answer
            int lengthOfWindow = i - start + 1;
            if (lengthOfWindow < ansLen) {
                ansLen = lengthOfWindow;
                ansIndex = start;
            }
        }
    }

    if (ansIndex == -1)
        return "-1";
    else
        return s.substr(ansIndex, ansLen);
}

// ===============================
// MAIN FUNCTION
// ===============================
int main() {

    string s = "timetopractice";
    string p = "toc";

    string result = smallestWindow(s, p);

    cout << "Smallest window: " << result << endl;

    return 0;
}
