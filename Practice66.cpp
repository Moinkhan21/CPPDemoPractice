#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Function to count palindromic substrings centered around index `i` and `j`
int expandAroundIndex(string s, int i, int j) {
    int count = 0;

    // Expand outward as long as characters at i and j are equal and within bounds
    while(i >= 0 && j < s.length() && s[i] == s[j]) {
        count++;    // A valid palindromic substring is found
        i--;        // Move left pointer
        j++;        // Move right pointer
    }

    return count;   // Return total palindromic substrings found from this center
}

// Function to count total palindromic substrings in the string `s`
int countSubstrings(string s) {
    int count = 0;          // Initialize counter for total palindromic substrings
    int n = s.length();     // Store the length of the input string

    // Traverse the string and consider each character as the center
    for(int i = 0; i < n; i++) {
        // Check for odd-length palindromes (centered at a single character)
        int oddKaAns = expandAroundIndex(s, i, i);
        count += oddKaAns;  // Add the count of odd palindromic substrings

        // Check for even-length palindromes (centered between two characters)
        int evenKaAns = expandAroundIndex(s, i, i + 1);
        count += evenKaAns; // Add the count of even palindromic substrings
    }

    return count;   // Return the total count of palindromic substrings
}

int main() {
    // Example input string
    string s = "abcba";

    // Call the function and store the result
    int result = countSubstrings(s);

    // Output the total number of palindromic substrings
    cout << "Total Palindromic Substrings: " << result << endl;
    // Output: Total Palindromic Substrings: 7
    // Explanation: The palindromic substrings are: "a", "b", "c", "bcb", "abcba", "b", "a"

    return 0;   // Return 0 to indicate successful execution
}
