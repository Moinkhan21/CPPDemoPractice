#include <iostream>
#include <queue>
using namespace std;

string solve(string str) {
    int freq[26] = {0};
    queue<char> q;

    string ans = "";

    for(int i = 0; i < str.length(); i++) {
        char ch = str[i];

        //Increment frequency
        freq[ch - 'a']++;

        //Push in queue
        q.push(ch);

        while(!q.empty()) {
            if(freq[q.front() - 'a'] > 1) {
                q.pop();
            }
            else {
                ans.push_back(q.front());
                break;
            }
        }

        if(q.empty()) {
            ans.push_back('#');
        }
    }
    return ans;
}

int main() {
    string str = "aabc";
    
    cout << "Final Ans: " << solve(str) << endl;
}