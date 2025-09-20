#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Use a global constant map (vector of pairs) in descending order
const vector<pair<int, string>> mp = {
    {1000000000, "Billion"}, {1000000, "Million"}, {1000, "Thousand"},
    {100, "Hundred"}, {90, "Ninety"}, {80, "Eighty"}, {70, "Seventy"},
    {60, "Sixty"}, {50, "Fifty"}, {40, "Forty"}, {30, "Thirty"},
    {20, "Twenty"}, {19, "Nineteen"}, {18, "Eighteen"}, {17, "Seventeen"},
    {16, "Sixteen"}, {15, "Fifteen"}, {14, "Fourteen"}, {13, "Thirteen"},
    {12, "Twelve"}, {11, "Eleven"}, {10, "Ten"}, {9, "Nine"}, {8, "Eight"},
    {7, "Seven"}, {6, "Six"}, {5, "Five"}, {4, "Four"}, {3, "Three"},
    {2, "Two"}, {1, "One"}
};

string numberToWords(int num) {
    if (num == 0) return "Zero";

    // Iterate over the map in descending order
    for (const auto &p : mp) {
        int val = p.first;
        const string &word = p.second;

        if (num >= val) {
            string result;

            // For big units (>= 100), handle prefix like "Twelve Thousand"
            if (val >= 100) {
                result += numberToWords(num / val) + " " + word;
            } else {
                // For values < 100 (like 90, 20, 19, ...) just place the word
                result += word;
            }

            int rem = num % val;
            if (rem != 0) {
                result += " " + numberToWords(rem);
            }
            return result;
        }
    }

    return ""; // should never reach here for num > 0
}

int main() {
    // tests
    vector<int> tests = {0, 5, 13, 20, 25, 58, 100, 123, 12345, 1000000, 1000000000, 1234567890};

    for (int t : tests) {
        cout << t << " -> " << numberToWords(t) << '\n';
    }

    return 0;
}
