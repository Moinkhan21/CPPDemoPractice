#include <iostream>     // For standard I/O operations (cin, cout)
#include <string>      // For using strings
using namespace std;

string reverseOnlyLetters(string s){
    int l = 0, h = s.size() - 1; // Initialize two pointers

    while(l < h){
        if(isalpha(s[l]) && isalpha(s[h])){ // Check if both characters are letters
            swap(s[l], s[h]); // Swap the letters
            l++; // Move left pointer forward
            h--; // Move right pointer backward
        } else if(!isalpha(s[l])) {
            l++; // Move left pointer forward if not a letter
        } else {
            h--; // Move right pointer backward if not a letter
        }
    }
    return s;
}

int main() {
    string s;
    cout << "Enter a string: ";
    getline(cin, s); // Input the string

    string result = reverseOnlyLetters(s); // Call the function to reverse letters
    cout << "Reversed string: " << result << endl; // Output the result

    return 0; // Return success
}