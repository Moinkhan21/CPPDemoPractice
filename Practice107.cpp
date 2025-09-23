#include <iostream>
#include <vector>
using namespace std;

// Recursive function to find all indexes of 'key' in the string
// Parameters:
// str  -> input string
// i    -> current index we are checking
// n    -> length of the string
// key  -> character to search for
// ans  -> vector storing all positions where 'key' is found
void checkKey(string& str, int i, int& n, char& key, vector<int>& ans){
    // Base case: if we have checked the entire string, stop recursion
    if(i >= n) {
        // Key not found at this level, return to previous calls
        return;
    }

    // --- Solve one case ---
    // If the current character matches the key, store its index
    if(str[i] == key){
        ans.push_back(i);   // Save the index where key is found
    }
        
    // --- Recursive call ---
    // Move to the next index in the string
    checkKey(str, i+1, n, key, ans);
}

int main() {
    // Input string
    string str = "lovebabbar";
    int n = str.length();  // Total length of the string

    char key = 'b';  // Character we want to search in the string

    int i = 0;  // Start index
    vector<int> ans;  // Stores all positions of 'key'

    // Call recursive function to search for 'key'
    checkKey(str, i, n, key, ans);

    // Print results
    cout << "Printing answers (indexes where '" << key << "' is found): " << endl;
    for(auto val: ans){
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
