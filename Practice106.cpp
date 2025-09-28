#include <iostream>
using namespace std;

/*
    Function: checkKey
    ------------------
    Recursively searches for the first occurrence of a character (key) in a string.
    
    Parameters:
    - str : the string to search in
    - i   : current index being checked
    - n   : length of the string
    - key : the character to search for
    
    Returns:
    - index (int) of the first occurrence of 'key'
    - -1 if the key is not found
*/
int checkKey(string& str, int i, int& n, char& key) {
    // ✅ Base case:
    // If index goes out of bounds (>= n), then key is not found
    if(i >= n) {
        return -1;  
    }

    // ✅ Solve only one case:
    // If the character at current index matches the key,
    // return this index (first occurrence found)
    if(str[i] == key)
        return i;

    // ✅ Recursive case:
    // Otherwise, move to the next index and search further
    return checkKey(str, i + 1, n, key);
}

int main() {
    string str = "lovebabbar";  // Input string
    int n = str.length();       // Length of string

    char key = 'r';             // Character to search for

    int i = 0;                  // Start index
    int ans = checkKey(str, i, n, key);  // Call recursive function

    // ✅ Print result:
    // If key is found, print its index; otherwise print -1
    cout << "Answer is: " << ans << endl;

    return 0;
}
