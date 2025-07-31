#include <iostream>     // For input and output streams
#include <string>       // For using the string class and related functions
using namespace std;

/*
 * Function: removeOccurrences
 * ----------------------------
 * Removes all non-overlapping occurrences of the substring `part` from the input string `s`.
 * 
 * Parameters:
 *   - s    : the original string
 *   - part : the substring that needs to be removed from `s`
 * 
 * Returns:
 *   - A new string after removing all occurrences of `part` from `s`.
 */
string removeOccurrences(string s, string part){
    // Find the first occurrence of `part` in `s`
    int pos = s.find(part);

    // Continue removing `part` as long as it's found in `s`
    while(pos != string::npos){
        // Erase the `part` from position `pos` with length equal to `part.length()`
        s.erase(pos, part.length());

        // Search for the next occurrence of `part` in the modified string
        pos = s.find(part);
    }

    // Return the final modified string
    return s;
}

int main() {
    // Declare a string variable to hold the input string
    string str;
    cout << "Enter a string: ";
    cin >> str; // Take input for the string from the user

    // Declare a string variable to hold the part to remove
    string part;
    cout << "Enter the part to remove: ";
    cin >> part; // Take input for the substring to be removed

    // Call the function to remove all occurrences of `part` from `str`
    string result = removeOccurrences(str, part);

    // Output the final string after removing the substring
    cout << "String after removing occurrences of '" << part << "': " << result << endl;

    return 0; // Return 0 to indicate successful program execution
}
