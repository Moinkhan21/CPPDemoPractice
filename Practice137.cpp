#include <iostream>
#include <vector>
#include <string>
using namespace std;

void solve(vector<string> &ans, int n, int open, int close, string output){
    //Base case
    if(open == 0 && close == 0) {
        ans.push_back(output);
        return;
    }

    //Include open bracket
    if(open > 0) {
        output.push_back('(');
        solve(ans, n, open - 1, close, output);
        //Backtrack
        output.pop_back();
    }

    //Include close bracket
    if(close > open) {
        output.push_back(')');
        solve(ans, n, open, close - 1, output);
        //Backtrack
        output.pop_back();
    }
} 

vector<string> generateParenthesis(int n){
    vector<string> ans;
    int open = n;
    int close = n;
    string output = "";
    solve(ans, n, open, close, output);
    return ans;
}

int main() {
    int n;
    cout << "Enter number of pairs of parentheses: ";
    cin >> n;
    vector<string> result = generateParenthesis(n);
    for(const string &s : result) {
        cout << s << endl;
    }
    return 0;
}