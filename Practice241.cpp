#include <iostream>
#include <stack>   // ✅ corrected header (was written as <stacK>)
using namespace std;

// ==========================================
// ✅ Helper Function: Insert element at bottom of stack
// ==========================================
void insertAtBottom(stack<int> &s, int target) {
    // Base case — if stack is empty, push the element
    if(s.empty()) {
        s.push(target);
        return;
    }

    // Store top element temporarily
    int topElement = s.top();
    s.pop();

    // Recursive call — go deeper until stack becomes empty
    insertAtBottom(s, target);

    // Backtrack — push stored element back on top
    s.push(topElement);
}

// ==========================================
// ✅ Function: Reverse the stack using recursion
// ==========================================
void reverseStack(stack<int> &s) {
    // Base case
    if(s.empty()) {
        return;
    }

    // Remove top element
    int target = s.top();
    s.pop();

    // Recursive call — reverse remaining stack
    reverseStack(s);

    // Insert removed element at bottom
    insertAtBottom(s, target);
}

// ==========================================
// ✅ Helper function to print stack (non-destructive)
// ==========================================
void printStack(stack<int> s) { // Pass by value (copy), so original stack stays safe
    while(!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

// ==========================================
// ✅ Main Function
// ==========================================
int main() {
    stack<int> s;

    // Push elements into stack
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);

    cout << "Original stack (Top to Bottom): ";
    printStack(s);  // prints safely without modifying original stack

    // Reverse the stack
    reverseStack(s);

    cout << "Reversed stack (Top to Bottom): ";
    printStack(s);

    return 0;
}
