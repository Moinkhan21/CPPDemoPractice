#include <iostream>
#include <stack>   // Stack library for using stack data structure
using namespace std;

// ==========================================
// ✅ Helper Function: insertAtBottom()
// ------------------------------------------
// Inserts a given element at the bottom of the stack recursively.
// Logic:
// - If the stack is empty, simply push the target element.
// - Otherwise, remove the top element and call the function again.
// - Once base case is reached, push the removed elements back
//   during backtracking to restore the order.
// ==========================================
void insertAtBottom(stack<int> &s, int target) {
    // Base case — if stack is empty, directly push target
    if(s.empty()) {
        s.push(target);
        return;
    }

    // Remove top element temporarily
    int topElement = s.top();
    s.pop();

    // Recursive call — go deeper until stack becomes empty
    insertAtBottom(s, target);

    // Backtrack — push stored element back after insertion
    s.push(topElement);
}

// ==========================================
// ✅ Function: reverseStack()
// ------------------------------------------
// Reverses a stack using recursion and the insertAtBottom() function.
// Logic:
// - Remove the top element of the stack.
// - Recursively reverse the rest of the stack.
// - Insert the removed element at the bottom (so it becomes the last).
// ==========================================
void reverseStack(stack<int> &s) {
    // Base case — when stack becomes empty, stop recursion
    if(s.empty()) {
        return;
    }

    // Step 1: Remove top element
    int target = s.top();
    s.pop();

    // Step 2: Recursively reverse remaining stack
    reverseStack(s);

    // Step 3: Insert the removed element at bottom
    insertAtBottom(s, target);
}

// ==========================================
// ✅ Helper Function: printStack()
// ------------------------------------------
// Prints the stack contents from top to bottom without modifying the original stack.
// We pass the stack by value so a copy is created and popped for printing.
// ==========================================
void printStack(stack<int> s) {
    cout << "[Top -> Bottom] ";
    while(!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

// ==========================================
// ✅ Main Function
// ------------------------------------------
// Demonstrates the stack reversal using recursion.
// ==========================================
int main() {
    stack<int> s;

    // Push elements into the stack (top element = 50)
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);

    // Display the original stack
    cout << "Original stack: ";
    printStack(s);

    // Reverse the stack recursively
    reverseStack(s);

    // Display the reversed stack
    cout << "Reversed stack: ";
    printStack(s);

    // Explanation of expected result:
    // Original: Top->Bottom = 50 40 30 20 10
    // Reversed: Top->Bottom = 10 20 30 40 50
    return 0;
}
