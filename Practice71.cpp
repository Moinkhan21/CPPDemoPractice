#include <iostream>     // For standard I/O operations (cin, cout)
#include <string>       // For using strings
#include <vector>       // For using vector
using namespace std;

// Function to find the longest common prefix among a list of strings
string longestCommonPrefix(vector<string>& strs) {
    string ans;
    int i = 0;

    // Edge case: If input is empty
    if (strs.empty()) return "";

    while (true) {
        char curr_ch = 0;

        for (const auto& str : strs) {
            if (i >= str.size()) {
                // Out of bounds: One of the strings is shorter
                curr_ch = 0;
                break;
            }

            if (curr_ch == 0) {
                curr_ch = str[i]; // Set the first character to compare
            } else if (curr_ch != str[i]) {
                // Mismatch found
                curr_ch = 0;
                break;
            }
        }

        if (curr_ch == 0) break; // Exit loop if no common character at index i

        ans.push_back(curr_ch); // Append the matched character to answer
        i++; // Move to next character position
    }

    return ans;
}

int main() {
    vector<string> strs;
    int n;

    cout << "Enter number of strings: ";
    cin >> n;
    cin.ignore(); // Ignore trailing newline

    cout << "Enter the strings:" << endl;
    for (int i = 0; i < n; i++) {
        string str;
        getline(cin, str);
        strs.push_back(str);
    }

    string result = longestCommonPrefix(strs);
    cout << "Longest common prefix: " << (result.empty() ? "None" : result) << endl;

    return 0;
}
