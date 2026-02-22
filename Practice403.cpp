#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void getSubsequences(string str) {
    vector<string> ans;
    int n = str.length();

    for(int num = 0; num < (1 << n); num++) {
        string temp = "";

        //We will create subsequence string in this temp string
        for(int i = 0; i < n; i++) {
            char ch = str[i];
            if(num & (1 << i)) {
                //Non - zero value k liye, include current character
                temp.push_back(ch);
            }
        }

        if(temp.length() >= 0) {
            //Store in ans
            ans.push_back(temp);
        }
    }

    sort(ans.begin(), ans.end());
    cout << "Count of subsequences " << ans.size() << endl;
    cout << "Printing the subsequences" << endl;
    for(auto i : ans) {
        cout << i << endl;
    }
}

int main() {
    string str = "abc";
    getSubsequences(str);
    return 0;
}
