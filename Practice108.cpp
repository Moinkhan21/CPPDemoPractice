#include <iostream>
#include <vector>
using namespace std;

// ---------------- FUNCTION: checkKey ----------------
// Purpose: Count how many times a given character `key` 
// appears in the string `str` using recursion.
//
// Parameters:
//   str   -> reference to the input string
//   i     -> current index in the string
//   n     -> length of the string
//   key   -> the character we want to search for
//   count -> reference variable to keep track of occurrences
void checkKey(string& str, int i, int& n, char& key, int& count){
    // ---------- BASE CASE ----------
    // If index goes out of bounds (we have traversed the string),
    // stop recursion.
    if(i >= n) {
        return;
    }

    // ---------- PROCESS ONE CHARACTER ----------
    // If current character matches the key,
    // increment the count.
    if(str[i] == key){
        count++;
    }

    // ---------- RECURSIVE CALL ----------
    // Move to the next character in the string
    checkKey(str, i+1, n, key, count);
}

int main() {
    // Input string
    string str = "lovebabbar";
    int n = str.length();   // Total length of the string

    char key = 'b';         // Character to search for

    int i = 0;              // Starting index
    int count = 0;          // Counter for occurrences

    // Call recursive function
    checkKey(str, i, n, key, count);

    // Print final result
    cout << "Printing counts: " << count << endl;
    
    return 0;
}
