#include <iostream>
using namespace std;

/*
    Function: checkKey
    ------------------
    Recursively checks if a given character (key) exists in the string.

    Parameters:
    - str : the string to search in
    - i   : current index being checked
    - n   : length of the string
    - key : the character to search for

    Returns:
    - true  if the key is found in the string
    - false if the key is not present
*/
bool checkKey(string& str, int& i, int& n, char& key) {
    // ✅ Base case: if we reach the end of the string, key not found
    if(i >= n) {
        return false;
    }

    // ✅ Solve only one case:
    // If the current character matches the key, return true
    if(str[i] == key)
        return true;

    // ✅ Recursive case:
    // Otherwise, move to the next index and search
    int newi = i + 1;  // make a new index to avoid modifying i directly
    bool ans = checkKey(str, newi, n, key);

    // Return the result from recursion
    return ans;
}

int main() {
    string str = "lovebabbar"; // Example string
    int n = str.length();      // Length of string

    char key = 'r';  // Character to search for in the string

    int i = 0;  // Start index
    bool ans = checkKey(str, i, n, key); // Call recursive function

    // Print result (1 = true, 0 = false)
    cout << "Answer is: " << ans << endl;

    return 0;
}
