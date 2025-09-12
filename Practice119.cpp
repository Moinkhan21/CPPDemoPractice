#include <iostream>   // For input/output (cin, cout)
#include <string>     // For using std::string
using namespace std;

/*
 Function: reverse
 -----------------
 This function reverses a string recursively.

 Parameters:
 - s     : reference to the string to be reversed
 - start : current starting index
 - end   : current ending index

 Steps:
 1. Base case: if start >= end, stop recursion (string fully reversed).
 2. Swap the characters at 'start' and 'end'.
 3. Recursive call: move inward (start+1, end-1).
*/
void reverse(string& s, int start, int end){
    // ✅ Base case: stop recursion when pointers cross or meet
    if(start >= end){
        return;
    }

    // ✅ Solve one case: swap characters at 'start' and 'end'
    swap(s[start], s[end]);

    // ✅ Recursive call: process the remaining middle part of the string
    reverse(s, start + 1, end - 1);
}

int main() {
    string s;

    // Take input string
    cout << "Enter string: ";
    cin >> s;

    int start = 0;              // Start index (first character)
    int end = s.size() - 1;     // End index (last character)

    // Call recursive reverse function
    reverse(s, start, end);

    // Print the reversed string
    cout << "Reversed string is: " << s << endl;

    return 0;
}
