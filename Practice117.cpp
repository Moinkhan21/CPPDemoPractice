#include <iostream>
using namespace std;

void lastOccLTR(string& s, char x, int i, int& ans) {

    //Base case
    if(i >= s.size()) {
        return;
    }

    //Ek case solution
    if(s[i] == x) {
        ans = i;
    }

    //Recursive call
    lastOccLTR(s, x, i + 1, ans);
}

int main() {
    string s;
    cout << "Enter string and character to find last occurrence from left: ";
    cin >> s;

    char x;
    cout << "Enter character: ";
    cin >> x; 

    int ans = -1;
    int i = 0;

    lastOccLTR(s, x, i, ans);
    cout << ans << endl;

    return 0;
}