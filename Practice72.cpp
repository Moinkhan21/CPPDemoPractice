#include <iostream>     // For standard I/O operations (cin, cout)
#include <string>      // For using strings
using namespace std;

// Function to check if a character is a vowel
bool isVowel(char ch) {
    ch = tolower(ch); // Convert to lowercase for uniformity
    return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
}

string reverseVowels(string s){
    int l = 0, h = s.size() - 1;

    while(l < h) {
        if(isVowel(s[l]) && isVowel(s[h])) {
            swap(s[l], s[h]); // Swap vowels
            l++; // Move left pointer forward
            h--; // Move right pointer backward
        } else if(!isVowel(s[l])) {
            l++; // Move left pointer forward if not a vowel
        } else {
            h--; // Move right pointer backward if not a vowel
        }
    }
    return s; // Return the modified string
}

int main() {
    string s;
    cout << "Enter a string: ";
    getline(cin, s); // Input the string

    string result = reverseVowels(s); // Call the function to reverse vowels
    cout << "String after reversing vowels: " << result << endl; // Output the result

    return 0; // Return success
}