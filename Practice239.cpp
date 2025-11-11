#include <iostream>
#include <stack>
using namespace std;

// ================================================================
// ⚙️ Note:
// s.top() → If stack is empty, DO NOT call this function.
// This function is only safe when there’s at least one element
// present inside the stack.
// ================================================================


// ================================================================
// ✅ Recursive Function: solve()
// Purpose: Inserts a given element (target) at the *bottom* of the stack.
// ------------------------------------------------
// Approach:
// - If stack is empty, directly push the target (base case).
// - Otherwise, pop top elements one by one recursively,
//   until stack becomes empty, push target,
//   and then push back all popped elements in reverse order
//   (this restores the stack state while keeping target at the bottom).
// ================================================================
void solve(stack<int> &s, int target) {
    // --------------------------------------------
    // 🧩 Base Case:
    // If stack is empty, simply push target element.
    // This ensures the target gets inserted at the bottom.
    // --------------------------------------------
    if(s.empty()) {
        s.push(target);
        return;
    }

    // --------------------------------------------
    // Step 1: Store and remove the top element
    // --------------------------------------------
    int topElement = s.top();
    s.pop();

    // --------------------------------------------
    // Step 2: Recursive call
    // This continues removing elements until stack becomes empty.
    // --------------------------------------------
    solve(s, target);

    // --------------------------------------------
    // Step 3: Backtracking step
    // Push previously popped element back onto stack,
    // restoring the order of other elements above target.
    // --------------------------------------------
    s.push(topElement);
}


// ================================================================
// ✅ Function: insertAtBottom()
// Purpose: Takes the top element of stack and inserts it at bottom.
// ------------------------------------------------
// It acts as a utility wrapper that extracts the top element
// and calls `solve()` to reinsert it at the bottom recursively.
// ================================================================
void insertAtBottom(stack<int> &s) {
    // --------------------------------------------
    // 🧩 Base Check:
    // If stack is empty, we cannot insert at bottom.
    // --------------------------------------------
    if(s.empty()) {
        cout << "Stack is empty, can not insert at bottom" << endl;
        return;
    }

    // --------------------------------------------
    // Step 1: Store the topmost element as target
    // --------------------------------------------
    int target = s.top();
    s.pop();

    // --------------------------------------------
    // Step 2: Use recursive helper to push target at bottom
    // --------------------------------------------
    solve(s, target);
}


// ================================================================
// ✅ MAIN FUNCTION — Demonstration
// ------------------------------------------------
// Example:
// Stack before:  [10, 20, 30, 40, 50] (50 on top)
// After insertAtBottom(): [50, 10, 20, 30, 40]
// ================================================================
int main() {
    stack<int> s;

    // Push elements into the stack
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);

    // Function call to insert top element at bottom
    insertAtBottom(s);

    // Display final stack contents
    cout << "Printing" << endl;
    while(!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;

    return 0;
}
