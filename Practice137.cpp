#include <iostream>
#include <vector>
#include <string>
using namespace std;

// ---------------- FUNCTION: solve ----------------
// Purpose: Generate all valid combinations of n pairs of parentheses
// using backtracking and recursion.
//
// Parameters:
//   ans    -> vector to store all valid strings
//   n      -> total number of pairs of parentheses
//   open   -> number of '(' left to place
//   close  -> number of ')' left to place
//   output -> current string being built
void solve(vector<string> &ans, int n, int open, int close, string output){
    // ---------- BASE CASE ----------
    // If no open and no close brackets remain,
    // we have formed a valid string, so store it.
    if(open == 0 && close == 0) {
        ans.push_back(output);
        return;
    }

    // ---------- CHOICE 1: Add an OPEN bracket ----------
    // We can add '(' if we still have some left (open > 0).
    if(open > 0) {
        output.push_back('(');                 // Add '('
        solve(ans, n, open - 1, close, output); // Recurse with one less open
        output.pop_back();                     // Backtrack (undo the addition)
    }

    // ---------- CHOICE 2: Add a CLOSE bracket ----------
    // We can add ')' only if there are more ')' left than '('.
    // This ensures validity (no premature closing).
    if(close > open) {
        output.push_back(')');                   // Add ')'
        solve(ans, n, open, close - 1, output);  // Recurse with one less close
        output.pop_back();                       // Backtrack (undo the addition)
    }
} 

// ---------------- FUNCTION: generateParenthesis ----------------
// Purpose: Wrapper function that sets up initial parameters
// and returns all valid parentheses combinations for given n.
vector<string> generateParenthesis(int n){
    vector<string> ans;       // To store final results
    int open = n;             // Initially, n open brackets available
    int close = n;            // Initially, n close brackets available
    string output = "";       // Current string being built

    solve(ans, n, open, close, output); // Start recursive generation
    return ans;
}

int main() {
    int n;
    cout << "Enter number of pairs of parentheses: ";
    cin >> n;

    // Generate all valid parentheses strings
    vector<string> result = generateParenthesis(n);

    // Print all results
    for(const string &s : result) {
        cout << s << endl;
    }

    return 0;
}
