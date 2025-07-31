#include <iostream>     // For input and output operations
#include <string>       // For using the string class and related functions
using namespace std;

/*
 * Function: removeDuplicates
 * ---------------------------
 * Removes adjacent duplicates from the given string.
 * For example: "abbaca" → "ca" (remove "bb", then "aa")
 *
 * Parameters:
 *   - s : the original input string from which adjacent duplicates will be removed
 *
 * Returns:
 *   - A new string with all adjacent duplicates removed.
 */
string removeDuplicates(string s){
    string ans = "";   // To store the final result string without adjacent duplicates
    int i = 0;         // Iterator to traverse the input string

    // Loop through each character in the input string
    while(i < s.length()){

        // If the result string is not empty
        if(ans.length() > 0){
            // Check if the last character in 'ans' is the same as the current character
            if(ans[ans.length() - 1] == s[i]) {
                // If it's a duplicate, remove the last character (i.e., pop the duplicate pair)
                ans.pop_back();
            }
            else {
                // If it's not a duplicate, add the current character to the result string
                ans.push_back(s[i]);
            }
        }
        else {
            // If 'ans' is empty, just add the first character
            ans.push_back(s[i]);
        }

        i++; // Move to the next character in the input string
    }

    // Return the result string after all duplicates are removed
    return ans;
}

int main() {
    // Declare a string variable to hold user input
    string str;
    cout << "Enter a string: ";
    cin >> str; // Take input from the user

    // Call the function to remove adjacent duplicates
    string result = removeDuplicates(str);

    // Output the resulting string after processing
    cout << "String after removing duplicates: " << result << endl;

    return 0; // Indicate successful program execution
}
