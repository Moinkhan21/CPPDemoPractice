#include <iostream>  // For input/output operations
#include <string>    // For using the string data type
using namespace std;

/*
----------------------------------------------------------
Function: isPalindrome
Purpose : Checks if a given substring (from start to end index)
          is a palindrome (reads the same forwards and backwards).
Params  :
    - s     : The main string to check.
    - start : Starting index of the substring.
    - end   : Ending index of the substring.
Returns :
    - true  : If the substring is a palindrome.
    - false : If it is not a palindrome.
----------------------------------------------------------
*/
bool isPalindrome(string &s, int start, int end) {
    // Loop until the two pointers meet in the middle
    while (start < end) {
        // If characters at the two ends are not equal, it's not a palindrome
        if (s[start] != s[end]) {
            return false;
        }
        // Move start forward and end backward
        start++;
        end--;
    }
    return true; // If loop finishes, it's a palindrome
}

/*
----------------------------------------------------------
Function: longestPalindrome
Purpose : Finds the longest palindromic substring in a given string.
Logic   :
    - Use two nested loops to generate all possible substrings.
    - For each substring, check if it's a palindrome.
    - If it is and longer than the previously found palindrome,
      update the answer.
Params  :
    - s : The input string.
Returns:
    - The longest palindromic substring found.
----------------------------------------------------------
*/
string longestPalindrome(string s) {
    string ans = ""; // Stores the longest palindrome found

    // Outer loop: starting index of the substring
    for (int i = 0; i < s.size(); i++) {
        // Inner loop: ending index of the substring
        for (int j = i; j < s.size(); j++) {
            // Check if the current substring is a palindrome
            if (isPalindrome(s, i, j)) {
                // Extract the substring from i to j
                string t = s.substr(i, j - i + 1);
                // If the new substring is longer than the previous answer, update it
                ans = (t.size() > ans.size()) ? t : ans;
            }
        }
    }
    return ans; // Return the longest palindrome found
}

/*
----------------------------------------------------------
Function: main
Purpose : Main driver function to take user input and
          display the longest palindromic substring.
Steps   :
    1. Ask the user for input.
    2. Call longestPalindrome() to find the answer.
    3. Display the result.
----------------------------------------------------------
*/
int main() {
    string s;
    cout << "Enter a string: ";
    cin >> s; // Take input from the user

    // Get the longest palindromic substring
    string result = longestPalindrome(s);

    // Display the result
    cout << "Longest palindromic substring: " << result << endl;

    return 0; // Exit the program successfully
}
