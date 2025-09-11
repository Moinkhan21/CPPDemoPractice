#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(string &s, int start, int end) {
    //Base case
    if(start >= end){
        return true;
    }

    //Solve 1 case only
    if(s[start] != s[end]){
        return false;
    }

    //Recursive call
    return isPalindrome(s, start + 1, end - 1);
}

int main() {
    string s;
    cout << "Enter string: ";
    cin >> s;

    cout << "Is Palindrome: " << (isPalindrome(s, 0, s.size() - 1) ? "true" : "false") << endl;
}