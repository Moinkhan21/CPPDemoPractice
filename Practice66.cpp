#include <iostream>
#include <string>
#include <vector>
using namespace std;

int expandAroundIndex(string s, int i, int j) {
    int count = 0;

    //Jab tak match karega, tab tak count increment kardo and i piche and j aage badhao
    while(i >= 0 && j < s.length() && s[i] == s[j]) {
        count++;
        i--;
        j++;
    }
    return count;
}

int countSubstrings(string s) {
    int count = 0;
    int n = s.length();

    for(int i = 0; i < n; i++) {
        //Odd
        int oddKaAns = expandAroundIndex(s, i, i);
        count += oddKaAns;

        //Even
        int evenKaAns = expandAroundIndex(s, i, i + 1);
        count += evenKaAns;
    }
    return count;
}

int main() {
    // Your code here

    string s = "abcba";
    int result = countSubstrings(s);
    cout << "Total Palindromic Substrings: " << result << endl;
    // Output: Total Palindromic Substrings: 7
    
    return 0;
}