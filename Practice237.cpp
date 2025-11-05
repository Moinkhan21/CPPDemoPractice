#include <iostream>
#include <stack>
using namespace std;

int main() {
    // -------------------------------------------
    // ✅ Step 1: Initialize a string
    // The string to be reversed using a stack
    // -------------------------------------------
    string str = "babbar";

    // -------------------------------------------
    // ✅ Step 2: Create a stack of characters
    // Stack will store each character temporarily
    // -------------------------------------------
    stack<char> s;

    // -------------------------------------------
    // ✅ Step 3: Push each character of the string into the stack
    // Loop runs through every character in the string
    // Since stack follows LIFO (Last In First Out),
    // the last inserted character will come out first.
    // -------------------------------------------
    for(int i = 0; i < str.length(); i++) {
        s.push(str[i]);   // Insert character into stack
    }

    // -------------------------------------------
    // ✅ Step 4: Pop characters from stack and print them
    // As we pop, elements come out in reverse order,
    // effectively reversing the original string.
    // -------------------------------------------
    while(!s.empty()) {
        cout << s.top() << " ";  // Access topmost character
        s.pop();                 // Remove the character
    }

    // -------------------------------------------
    // ✅ Step 5: Print a newline for clean output formatting
    // -------------------------------------------
    cout << endl;
    
    // -------------------------------------------
    // ✅ Step 6: End of program
    // -------------------------------------------
    return 0;
}
