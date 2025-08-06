#include <iostream>     // For standard I/O operations (cin, cout)
#include <string>      // For using C++ strings
using namespace std;

bool isAnagram(string s, string t){
    int freqTable[265] = {0}; // Frequency table for characters
    for(int i = 0; i < s.size(); i++){
        freqTable[s[i]]++; // Increment frequency for characters in s
    }

    for(int i = 0; i < t.size(); i++){
        freqTable[t[i]]--; // Decrement frequency for characters in t
    }

    for(int i = 0; i < 265; i++){
        if(freqTable[i] != 0) return false; // If any frequency is not zero, not an anagram
    }
    return true; // All frequencies are zero, so they are anagrams
}

int main() {
    string s, t;
    cout << "Enter first string: ";
    cin >> s; // Input first string
    cout << "Enter second string: ";
    cin >> t; // Input second string

    if(isAnagram(s, t)) {
        cout << "Yes, they are anagrams." << endl; // Output if they are anagrams
    } else {
        cout << "No, they are not anagrams." << endl; // Output if they are not anagrams
    }

    return 0; // Return success
}