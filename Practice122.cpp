#include <iostream>
#include <string>

using namespace std;

// Recursive helper function to remove all occurrences of `part` from `s`
void removeOccure(string& s, string& part) {
    // Find the first occurrence of substring `part` in string `s`
    int found = s.find(part);

    // If `part` is found inside `s`
    if (found != string::npos) {
        // ---------------- SPLITTING THE STRING ----------------
        // left_part -> substring of `s` before the found index
        string left_part = s.substr(0, found);

        // right_part -> substring of `s` after removing `part`
        string right_part = s.substr(found + part.size(), s.size());

        // Update `s` by concatenating left and right parts (removing `part`)
        s = left_part + right_part;

        // ---------------- RECURSION STEP ----------------
        // Continue searching and removing more occurrences of `part`
        removeOccure(s, part);
    }
    else {
        // ---------------- BASE CASE ----------------
        // If no more occurrences of `part` are found in `s`
        // Stop recursion (all instances removed)
        return;
    }
}

// Main function to remove all occurrences of `part` from `s`
string removeOccurrences(string s, string part) {
    // Call helper function to recursively remove substrings
    removeOccure(s, part);

    // Return the modified string after removal
    return s;
}

int main() {
    string s, part;

    // Input the main string
    cout << "Enter string: ";
    cin >> s;

    // Input the substring to be removed
    cout << "Enter part string to be removed: ";
    cin >> part;

    // Call function and store result
    string ans = removeOccurrences(s, part);

    // Print final string after all occurrences are removed
    cout << "Final string after removal: " << ans << endl;

    return 0;
}
