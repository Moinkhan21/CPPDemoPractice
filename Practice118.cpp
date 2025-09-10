#include <iostream>
using namespace std;

void lastOccRTL(string& s, char x, int i, int& ans) {

    //Base case
    if(i < 0) {
        return;
    }

    //Ek case solution
    if(s[i] == x) {
        ans = i;
        return; // Once found, no need to continue searching
    }

    //Recursive call
    lastOccRTL(s, x, i - 1, ans);
}

int main() {
    string s;
    cout << "Enter string and character to find last occurrence (from right -> first occ is last occ for string): ";
    cin >> s;

    char x;
    cout << "Enter character: ";
    cin >> x; 

    int ans = -1;
    int i = 0;

    lastOccRTL(s, x, s.size() - 1, ans);
    cout << ans << endl;

    return 0;
}