#include <iostream>
#include <stack>
using namespace std;

void buildAns(stack<string> &s, string &ans) {
    if(s.empty()) {
        return;
    }
    string minPath = s.top(); s.pop();
    buildAns(s, ans);
    ans += minPath;
}
string simplifyPath(string path) {
    stack<string> s;
    int i = 0;
    while(i < path.size()) {
        int start = i ;
        int end = i + 1;
        while(end < path.size() && path[end] != '/') {
            ++end;
        }
        string minPath = path.substr(start, end - start);
        cout << minPath << endl;
        i = end;
        if(minPath == "/" || minPath == "./") {
            continue;
        }
        if(minPath != "/..") {
            s.push(minPath);
        }
        else if(!s.empty()){
            s.pop();
        }
    }
    string ans = s.empty() ? "/" : "";
    buildAns(s, ans);
    return ans;
}

// ======================================================
// MAIN FUNCTION — FULLY TESTING THE CODE
// ======================================================
int main() {
    string paths[] = {
        "/home/",
        "/../",
        "/home//foo/",
        "/a/./b/../../c/",
        "/a/../../b/../c//.//"
    };

    for (string p : paths) {
        cout << "Input: " << p << endl;
        cout << "Simplified: " << simplifyPath(p) << endl;
        cout << "--------------------------------\n";
    }

    return 0;
}