#include <iostream>
#include <cstring>    // For C-style string functions like strlen()
#include <algorithm>  // Not used here, but typically for STL algorithms
#include <cctype>     // For character manipulation (not used in this example)
using namespace std;

// Function to replace all spaces in a given sentence with '@'
void replaceSpaces(char sentence[]) {
    int i = 0;
    int n = strlen(sentence);  // Calculate the length of the string

    // Iterate over each character in the string
    for(int i = 0; i < n; i++) {
        // If the current character is a space, replace it with '@'
        if(sentence[i] == ' ') {
            sentence[i] = '@';
        }
    }
}

// Function to check whether a given word is a palindrome
bool checkPalindrome(char word[]) {
    int i = 0;              // Start pointer
    int n = strlen(word);   // Length of the string
    int j = n - 1;          // End pointer

    // Loop until both pointers meet or cross
    while(i <= j) {
        // If characters at both ends do not match, it's not a palindrome
        if(word[i] != word[j]) {
            return false;
        } else {
            // Move both pointers toward the center
            i++;
            j--;
        }
    }
    return true;  // All characters matched, it's a palindrome
}

// Function to convert all lowercase characters in a string to uppercase
void convertIntoUpperCase(char word1[]) {
    int n = strlen(word1);  // Calculate length of the string

    // Loop through each character in the string
    for(int i = 0; i < n; i++) {
        // Convert lowercase letter to uppercase by subtracting 'a' and adding 'A'
        word1[i] = word1[i] - 'a' + 'A';
    }
}

int main() {
    // Input: sentence from user
    char sentence[100];
    cout << "Enter a sentence: ";
    cin.getline(sentence, 100);  // Read entire line including spaces

    // Print the original sentence
    cout << "Original sentence: " << sentence << endl;

    // Replace spaces with '@' symbols
    replaceSpaces(sentence);
    cout << "Modified sentence: " << sentence << endl;

    // ---------- Palindrome Check ----------
    // Sample word to test palindrome
    char word[100] = "madam";
    cout << "Palindrome check: " << checkPalindrome(word) << endl;
    // Output will be 1 (true) or 0 (false)

    // ---------- Convert to Uppercase ----------
    // Sample word for uppercase conversion
    char word1[100] = "hello";
    cout << "Original word: " << word1 << endl;
    convertIntoUpperCase(word1);
    cout << "Converted to uppercase: " << word1 << endl;

    /*
        Time Complexity (T.C): O(n) — Each function iterates once over the string
        Space Complexity (S.C): O(1) — Constant extra space used, no dynamic allocation
    */

    return 0;
}
