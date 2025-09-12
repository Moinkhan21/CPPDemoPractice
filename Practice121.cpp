#include <iostream>   // For input/output operations (cin, cout)
#include <string>     // For using C++ strings
using namespace std;

// Function to check if a string is a palindrome using recursion
bool isPalindrome(string &s, int start, int end) {
    // ✅ Base case:
    // If start index crosses or meets end index, we have checked the whole string
    // That means it's a palindrome
    if(start >= end){
        return true;
    }

    // ✅ Solve one case:
    // If characters at start and end don't match → not a palindrome
    if(s[start] != s[end]){
        return false;
    }

    // ✅ Recursive call:
    // Move towards the center by checking next pair
    return isPalindrome(s, start + 1, end - 1);
}

int main() {
    string s;

    // Input string from user
    cout << "Enter string: ";
    cin >> s;

    // Call the recursive function
    // Start checking from index 0 to last index (s.size()-1)
    cout << "Is Palindrome: "
         << (isPalindrome(s, 0, s.size() - 1) ? "true" : "false")
         << endl;

    return 0; // Successful program execution
}
