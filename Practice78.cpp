#include <iostream>
#include <string>
using namespace std;

// Function to find the first occurrence of 'needle' in 'haystack'
int strStr(string haystack, string needle) {
    int n = haystack.size(); // Length of the main string (haystack)
    int m = needle.size();   // Length of the substring (needle)

    // Loop through haystack, but only until (n - m), because
    // if there are fewer than 'm' characters left, needle cannot fit
    for (int i = 0; i <= n - m; i++) {
        
        // For each position 'i', check if the substring starting at 'i' matches needle
        for (int j = 0; j < m; j++) {
            
            // Compare each character of needle with corresponding character in haystack
            if (needle[j] != haystack[i + j]) {
                // If any character does not match, break and move to next position of haystack
                break;
            }

            // If we reached the last character of needle (j == m - 1) 
            // and all previous characters matched, we found the needle
            if (j == m - 1) {
                return i; // Return the starting index where needle is found
            }
        }
    }

    // If no match is found after scanning entire haystack, return -1
    return -1;
}

int main() {
    string haystack = "hello";  // Main string
    string needle = "ll";       // Substring to search
    int result = strStr(haystack, needle); // Call the function

    cout << "Result: " << result << endl; // Output the result index
    return 0;
}
