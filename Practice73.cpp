 #include <iostream>     // For standard I/O operations (cin, cout)
 #include <vector>       // For dynamic arrays (vectors)
 using namespace std;

 bool isIsomorphic(string s, string t) {
    int hash[256] = {0}; // Mapping of each char of language 'ss to language 't'
    bool istCharMapped[256] = {0}; // Stores if t[i] char already mapped with s[i]

    for(int i = 0; i < s.size(); i++) {
        if(hash[s[i]] == 0 && istCharMapped[t[i]] == 0) {
            // If s[i] is not mapped and t[i] is not already mapped
            hash[s[i]] = t[i]; // Map s[i] to t[i]
            istCharMapped[t[i]] = true; // Mark t[i] as mapped
        } 
    }

    for(int i = 0; i < s.size(); i++) {
        if(hash[s[i]] != t[i]) {
            // If the mapping does not match
            return false; // Not isomorphic
        }
    }
    return true; // All characters match, strings are isomorphic
 }

 int main() {
    string s, t;
    cout << "Enter first string: ";
    getline(cin, s); // Input first string
    cout << "Enter second string: ";
    getline(cin, t); // Input second string

    if(s.size() != t.size()) {
        cout << "Strings are not isomorphic (different lengths)." << endl;
        return 0; // Exit if lengths differ
    }

    bool result = isIsomorphic(s, t); // Check if strings are isomorphic
    cout << "Strings are " << (result ? "" : "not ") << "isomorphic." << endl; // Output result

    return 0; // Return success
 }