#include <iostream>
#include <string>
using namespace std;

bool checkPalindrome(string s, int i, int j) {
    while(i <= j) {
        if(s[i] != s[j]) {
            return false;
        }
        i++;
        j--;
    }
    return true;
}

bool validPalindrome(string s){
    int i = 0;
    int j = s.size() - 1;

    while(i <= j) {
        if(s[i] != s[j]) {
            //Either remove i or j character
            return checkPalindrome(s, i + 1, j) || checkPalindrome(s, i, j - 1);
        }
        else {
            //s[i] == s[j]
            i++;
            j--;
        }
    }
    return true; // The string is a valid palindrome
}

int main () {
    string s;
    cout << "Enter a string: ";
    cin >> s;

    if(validPalindrome(s)) {
        cout << "The string can be a valid palindrome after removing at most one character." << endl;
    } else {
        cout << "The string cannot be a valid palindrome even after removing one character." << endl;
    }

    return 0; // Return 0 to indicate successful program execution
}