#include <iostream>
#include <stack>
using namespace std;

// ============================================================================
// FUNCTION: buildAns
// PURPOSE:
//    A recursive helper that rebuilds the simplified path string by popping
//    directory components from the stack in the correct (left-to-right) order.
//
// HOW IT WORKS:
//    • Recursively pop all elements from the stack until it becomes empty.
//    • During backtracking, append each stored path part to 'ans'.
//    • This ensures correct ordering because stack is LIFO but path must be FIFO.
// ============================================================================
void buildAns(stack<string> &s, string &ans) {
    if(s.empty()) {
        return;                 // Base case: no more components in stack
    }

    string minPath = s.top();   // Extract the topmost directory component
    s.pop();                    // Remove it before recursive call

    buildAns(s, ans);           // Recursive call to process remaining elements

    ans += minPath;             // Backtracking step: append component to final path
}

// ============================================================================
// FUNCTION: simplifyPath
// PURPOSE:
//    Simplifies a Unix-style absolute file path by removing redundant parts:
//    • "//"  → treat as a single "/"
//    • "/."  → current directory → ignore
//    • "/.." → parent directory → pop one element from stack (if exists)
//
// APPROACH:
//    • Parse the input string into segments between '/'.
//    • Push valid directory names onto the stack.
//    • Pop when encountering "/..".
//    • Rebuild final path from the stack using recursion (buildAns).
// ============================================================================
string simplifyPath(string path) {
    stack<string> s;
    int i = 0;

    // Iterate through the entire path string
    while(i < path.size()) {

        int start = i;          // Starting index of a segment
        int end = i + 1;        // Move 'end' until we hit next '/'

        while(end < path.size() && path[end] != '/') {
            ++end;
        }

        // Extract substring representing current directory component
        string minPath = path.substr(start, end - start);
        cout << minPath << endl;    // Debug output showing extracted component

        i = end;                   // Move pointer to next segment

        // Skip unnecessary components:
        if(minPath == "/" || minPath == "./") {
            continue;              // "/" or "/." have no effect on actual path
        }

        // If component is NOT "/.." → treat it as a valid directory, push into stack
        if(minPath != "/..") {
            s.push(minPath);
        }
        else if(!s.empty()) {
            // "/.." means go one directory up → pop last valid directory
            s.pop();
        }
    }

    // If stack becomes empty → simplified path = "/"
    string ans = s.empty() ? "/" : "";

    // Otherwise rebuild path in correct order
    buildAns(s, ans);

    return ans;
}

// ============================================================================
// MAIN FUNCTION — FULLY TESTING THE CODE
// ============================================================================
int main() {
    string paths[] = {
        "/home/",              // Normal path
        "/../",                // Going above root → result should be "/"
        "/home//foo/",         // Extra slashes should be ignored
        "/a/./b/../../c/",     // Mix of "." and ".."
        "/a/../../b/../c//.//" // Complex case with multiple redundant markers
    };

    for (string p : paths) {
        cout << "Input: " << p << endl;
        cout << "Simplified: " << simplifyPath(p) << endl;
        cout << "--------------------------------\n";
    }

    return 0;
}
