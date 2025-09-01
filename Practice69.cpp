#include <iostream>     // For standard input and output (cin, cout)
#include <string>       // For using the C++ string data type
using namespace std;

// Function to check if two strings are anagrams
// An anagram means both strings contain the same characters
// with the same frequency, just arranged differently.
bool isAnagram(string s, string t) {
    // Frequency table (array) to store how many times each character appears.
    // We use size 265 (a bit larger than ASCII range 256) for safety.
    int freqTable[265] = {0};  

    // Step 1: Count character frequency for first string 's'
    for (int i = 0; i < s.size(); i++) {
        freqTable[s[i]]++;  // Increment the count of the character
    }

    // Step 2: Subtract character frequency for second string 't'
    for (int i = 0; i < t.size(); i++) {
        freqTable[t[i]]--;  // Decrement the count of the character
    }

    // Step 3: Check if all counts are back to zero
    // If any index has a non-zero value, it means
    // one string has extra or missing characters → not an anagram.
    for (int i = 0; i < 265; i++) {
        if (freqTable[i] != 0) 
            return false;  // Mismatch found, not an anagram
    }

    // Step 4: If all values are zero, both strings are anagrams
    return true;
}

int main() {
    string s, t;

    // Ask user for input
    cout << "Enter first string: ";
    cin >> s;   // Take input for the first string

    cout << "Enter second string: ";
    cin >> t;   // Take input for the second string

    // Call function and display result
    if (isAnagram(s, t)) {
        cout << "Yes, they are anagrams." << endl;
    } else {
        cout << "No, they are not anagrams." << endl;
    }

    return 0; // Successful program execution
}
