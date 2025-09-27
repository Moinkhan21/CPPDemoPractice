#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
    Recursive function to generate all valid parentheses combinations.

    Parameters:
    - ans: Reference to vector<string> that stores all valid combinations.
    - n: Total number of pairs of parentheses.
    - used_open: Number of '(' brackets already used so far.
    - used_close: Number of ')' brackets already used so far.
    - rem_open: Number of '(' brackets still available to place.
    - rem_close: Number of ')' brackets still available to place.
    - output: Current string being built during recursion.
*/
void solve(vector<string> &ans, int n, int used_open, int used_close, int rem_open, int rem_close, string output) {

    // ✅ Base case: If no open and close brackets remain,
    //    it means we have formed a valid combination.
    if(rem_open == 0 && rem_close == 0) {
        ans.push_back(output);   // Store the valid string in the answer vector
        return;
    }

    // ✅ Choice 1: Include an open bracket '(' if we still have some left.
    if(rem_open > 0) {
        output.push_back('(');   // Add '(' to the current string
        solve(ans, n, used_open + 1, used_close, rem_open - 1, rem_close, output);
        // Backtrack: Remove last character to try other possibilities
        output.pop_back();
    }

    // ✅ Choice 2: Include a close bracket ')' only if
    //    there are more used '(' than ')' (to keep the string valid).
    if(used_open > used_close){
        output.push_back(')');   // Add ')' to the current string
        solve(ans, n, used_open, used_close + 1, rem_open, rem_close - 1, output);
        // Backtrack: Remove last character to try other possibilities
        output.pop_back();
    }
}

/*
    Function to generate all valid parentheses combinations for given n.
    - Initializes helper variables and calls the recursive solve() function.
*/
vector<string> generateParenthesis(int n) {
    vector<string> ans;     // To store final results
    int used_open = 0;      // Count of '(' already used
    int used_close = 0;     // Count of ')' already used
    int rem_open = n;       // Remaining '(' brackets available
    int rem_close = n;      // Remaining ')' brackets available
    string output = "";     // Start with an empty string

    // Call recursive function
    solve(ans, n, used_open, used_close, rem_open, rem_close, output);

    return ans;
}

int main() {
    int n;
    cout << "Enter number of pairs of parentheses: ";
    cin >> n;

    // Generate all combinations
    vector<string> result = generateParenthesis(n);

    // Print all valid parentheses combinations
    cout << "All valid combinations of " << n << " pairs of parentheses are:\n";
    for(const string &s : result) {
        cout << s << endl;
    }

    return 0;
}
