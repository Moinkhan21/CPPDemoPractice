#include <iostream>
#include <vector>
#include <string>
using namespace std;

void solve(vector<string> &ans, int n, int used_open, int used_close, int rem_open, int rem_close, string output) {

    //Base case
    if(rem_open == 0 && rem_close == 0) {
        ans.push_back(output);
        return;
    }

    //Include open bracket
    if(rem_open > 0) {
        output.push_back('(');
        solve(ans, n, used_open + 1, used_close, rem_open - 1, rem_close, output);
        //Backtrack
        output.pop_back();
    }

    //Include close bracket
    if(used_open > used_close){
        output.push_back(')');
        solve(ans, n, used_open, used_close + 1, rem_open, rem_close - 1, output);
        //Backtrack
        output.pop_back();
    }
}

vector<string> generateParenthesis(int n) {
    vector<string> ans;
    int used_open = 0;
    int used_close = 0;
    int rem_open = n;
    int rem_close = n;
    string output = "";

    solve(ans, n, used_open, used_close, rem_open, rem_close, output);
    return ans;
}

int main() {
    int n;
    cout << "Enter number of pairs of parentheses: ";
    cin >> n;

    vector<string> result = generateParenthesis(n);
    cout << "All valid combinations of " << n << " pairs of parentheses are:\n";
    for(const string &s : result) {
        cout << s << endl;
    }

    return 0;
}