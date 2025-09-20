#include <iostream>
#include <vector>
#include <string>
using namespace std;

// ---------------- GLOBAL CONSTANT MAP ----------------
// We use a vector of pairs where each pair consists of:
// (numeric value, corresponding English word)
// The list is sorted in descending order so we can greedily match
// the largest value first (like "Million" before "Thousand").
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

// ---------------- FUNCTION: numberToWords ----------------
// Converts an integer into its English words representation.
string numberToWords(int num) {
    // Special case: if the number is zero
    if (num == 0) return "Zero";

    // Loop through the map (from biggest to smallest unit)
    for (const auto &p : mp) {
        int val = p.first;         // numeric value (like 1000, 90, 7, etc.)
        const string &word = p.second; // English word (like "Thousand", "Ninety", "Seven")

        // If current number is greater than or equal to this value
        if (num >= val) {
            string result;

            // ---------------- BIG UNITS CASE (>= 100) ----------------
            // Example: num = 12345
            // val = 1000 ("Thousand")
            // → first compute numberToWords(12345 / 1000) = "Twelve"
            // → then add "Thousand"
            if (val >= 100) {
                result += numberToWords(num / val) + " " + word;
            } else {
                // ---------------- SMALL UNITS CASE (< 100) ----------------
                // Example: num = 90
                // Just append the word "Ninety" directly
                result += word;
            }

            // ---------------- HANDLE REMAINDER ----------------
            // Compute remainder after subtracting val
            int rem = num % val;
            if (rem != 0) {
                // If remainder exists, recursively convert it as well
                // Example: 12345 % 1000 = 345 → convert "Three Hundred Forty Five"
                result += " " + numberToWords(rem);
            }

            // Return the complete result string
            return result;
        }
    }

    // Should never reach here for num > 0 because all cases are handled
    return "";
}

// ---------------- MAIN FUNCTION ----------------
int main() {
    // Test numbers to convert into words
    vector<int> tests = {
        0, 5, 13, 20, 25, 58,
        100, 123, 12345,
        1000000, 1000000000, 1234567890
    };

    // Loop through test cases and print results
    for (int t : tests) {
        cout << t << " -> " << numberToWords(t) << '\n';
    }

    return 0;
}
