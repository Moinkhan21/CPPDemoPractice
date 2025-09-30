#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
    Function: solve
    ----------------
    Recursive helper function to generate all possible letter combinations 
    for a given string of digits.

    Parameters:
        ans     : vector to store all final combinations
        index   : current index of the digit being processed
        output  : temporary string storing the current combination
        digits  : input string of digits (e.g., "23")
        mapping : mapping of digits to corresponding letters (like phone keypad)

    Working:
        - At each digit, we loop through all possible characters (from mapping).
        - Append character to 'output', recurse to next digit, and backtrack.
*/
void solve(vector<string> &ans, int index, string output, string digits, vector<string> &mapping){
    // ✅ Base case:
    // If index has reached the length of digits → one valid combination is formed
    if(index >= digits.length()){
        ans.push_back(output);   // store the combination
        return;
    }

    // Convert the current digit (char) to int index
    int digit = digits[index] - '0'; 
    string value = mapping[digit];   // get mapped characters for this digit

    // Iterate over each character that current digit can represent
    for(int i = 0; i < value.length(); i++){
        char ch = value[i];

        // Step 1: Include this character in current combination
        output.push_back(ch);

        // Step 2: Recurse for next digit
        solve(ans, index + 1, output, digits, mapping);

        // Step 3: Backtrack → remove last character (restore state for next iteration)
        output.pop_back();
    }
}

/*
    Function: letterCombinations
    ----------------------------
    Generates all possible letter combinations for the given digits string.
    Uses a recursive backtracking approach.

    Parameters:
        digits : input string containing digits (2-9)

    Returns:
        A vector of all valid combinations.
*/
vector<string> letterCombinations(string digits) {
    vector<string> ans;

    // Edge case: empty input → no combinations
    if(digits.length() == 0) return ans;

    int index = 0;          // starting index
    string output = "";     // initially empty combination
    
    // Mapping digits to corresponding letters as on a phone keypad
    vector<string> mapping(10);
    mapping[2] = "abc";
    mapping[3] = "def";
    mapping[4] = "ghi";
    mapping[5] = "jkl";
    mapping[6] = "mno";
    mapping[7] = "pqrs";
    mapping[8] = "tuv";
    mapping[9] = "wxyz";

    // Call recursive helper
    solve(ans, index, output, digits, mapping);
    return ans;
}

int main() {
    string digits;

    // Take input digits
    cout << "Enter digits: ";
    cin >> digits;

    // Generate all combinations
    vector<string> result = letterCombinations(digits);

    // Print results
    cout << "Possible letter combinations are:\n";
    for(const string &combination : result) {
        cout << combination << " ";
    }
    cout << endl;

    return 0;
}
