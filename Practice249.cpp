#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

// =========================================
// ✅ Function: removeDuplicates
// Removes all adjacent duplicate characters
// Example: "abbaca" → "ca"
// =========================================
string removeDuplicates(string s) {
    stack<char> st; // Stack to store characters

    // Traverse each character in the string
    for (auto ch : s) {
        // If top of stack equals current char → remove duplicate
        if (!st.empty() && st.top() == ch) {
            st.pop(); // Remove adjacent duplicate pair
        } 
        else {
            st.push(ch); // Otherwise, push character
        }
    }

    // Rebuild the final string from stack (in reverse order)
    string ans;
    while (!st.empty()) {
        ans += st.top();
        st.pop();
    }

    // Stack gives reversed order → reverse the result
    reverse(ans.begin(), ans.end());
    return ans;
}

// =========================================
// ✅ Main Function: Test removeDuplicates()
// =========================================
int main() {
    // Test cases
    string s1 = "abbaca";
    string s2 = "azxxzy";
    string s3 = "aabccba";
    string s4 = "aaaa";      // All duplicates removed → ""
    string s5 = "abc";       // No duplicates → "abc"

    cout << "Original: " << s1 << " -> After Removing Duplicates: " << removeDuplicates(s1) << endl;
    cout << "Original: " << s2 << " -> After Removing Duplicates: " << removeDuplicates(s2) << endl;
    cout << "Original: " << s3 << " -> After Removing Duplicates: " << removeDuplicates(s3) << endl;
    cout << "Original: " << s4 << " -> After Removing Duplicates: " << removeDuplicates(s4) << endl;
    cout << "Original: " << s5 << " -> After Removing Duplicates: " << removeDuplicates(s5) << endl;

    return 0;
}
