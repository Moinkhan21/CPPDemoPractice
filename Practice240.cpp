#include <iostream>
#include <stack>
using namespace std;

// ================================================================
// ✅ Function: insertAtBottom()
// Purpose: Insert a given element (target) at the *bottom* of a stack
// ------------------------------------------------
// 🔹 How it works:
// - If the stack is empty → simply push the target element (base case).
// - Otherwise:
//      1️⃣ Pop the top element and store it temporarily.
//      2️⃣ Recursively call the function to insert target deeper.
//      3️⃣ Push the temporarily removed element back (backtracking).
// This effectively moves the target to the very bottom.
// ================================================================
void insertAtBottom(stack<int> &s, int target) {
    // --------------------------------------------
    // 🧩 Base Case:
    // When stack becomes empty, we push the target element.
    // That ensures it gets placed at the bottom of the stack.
    // --------------------------------------------
    if(s.empty()) {
        s.push(target);
        return;
    }

    // --------------------------------------------
    // Step 1: Pop the top element and store it temporarily
    // --------------------------------------------
    int topElement = s.top();
    s.pop();

    // --------------------------------------------
    // Step 2: Recursive call — keep removing until stack is empty
    // --------------------------------------------
    insertAtBottom(s, target);

    // --------------------------------------------
    // Step 3: Backtrack — restore the popped elements back on top
    // After recursion, the target is already at the bottom.
    // --------------------------------------------
    s.push(topElement);
}

// ================================================================
// ✅ MAIN FUNCTION — Demonstration
// ------------------------------------------------
// Example:
// Input stack (top→bottom): [50, 40, 30, 20, 10]
// After inserting top element (50) at bottom → [40, 30, 20, 10, 50]
// ================================================================
int main() {
    stack<int> s;

    // Step 1: Push elements into the stack
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);

    // Step 2: Check if stack is empty before processing
    if(s.empty()) {
        cout << "Stack is empty, can not insert at bottom" << endl;
        return 0;
    }

    // Step 3: Choose the target element (topmost one)
    int target = s.top();  // Store top element as target
    s.pop();               // Remove it temporarily

    // Step 4: Insert the target element at bottom recursively
    insertAtBottom(s, target);

    // Step 5: Print final stack after insertion
    cout << "Printing Stack (top to bottom):" << endl;
    while(!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;

    return 0;
}
