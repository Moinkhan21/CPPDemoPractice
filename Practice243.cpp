#include <iostream>
#include <stack>
using namespace std;

// ==========================================================
// ✅ Helper Function: insertSorted()
// ----------------------------------------------------------
// Inserts an element into its correct position in a sorted stack.
// Works recursively by removing elements greater than the target
// and placing them back after inserting the target.
// ==========================================================
void insertSorted(stack<int>& s, int target) {
    // 🟢 Base case: If stack is empty OR top element <= target → push target
    if (s.empty() || s.top() <= target) {
        s.push(target);
        return;
    }

    // 🔁 Recursive case:
    // Pop the top element temporarily if it's greater than target
    int topElement = s.top();
    s.pop();

    // Recursive call — go deeper until correct position is found
    insertSorted(s, target);

    // 🔙 Backtracking step: Push the popped element back into the stack
    s.push(topElement);
}

// ==========================================================
// ✅ Recursive Function: sortStack()
// ----------------------------------------------------------
// Sorts a given stack in ascending order using recursion.
// The approach is based on:
//   1️⃣ Remove the top element
//   2️⃣ Recursively sort the remaining stack
//   3️⃣ Insert the removed element into the sorted stack
// ==========================================================
void sortStack(stack<int>& s) {
    // 🟢 Base case: If stack is empty → nothing to sort
    if (s.empty()) return;

    // Step 1: Remove top element
    int topElement = s.top();
    s.pop();

    // Step 2: Recursively sort the smaller stack
    sortStack(s);

    // Step 3: Insert the removed element in its correct position
    insertSorted(s, topElement);
}

// ==========================================================
// ✅ Helper Function: printStack()
// ----------------------------------------------------------
// Prints the stack contents from top to bottom.
// The stack is passed **by value** to prevent altering the original stack.
// ==========================================================
void printStack(stack<int> s) {
    cout << "Stack (top → bottom): ";
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

// ==========================================================
// ✅ Main Function
// ----------------------------------------------------------
// Demonstrates recursive sorting of a stack using the above functions.
// ==========================================================
int main() {
    stack<int> s;

    // Push unsorted values into stack
    s.push(7);
    s.push(11);
    s.push(3);
    s.push(5);
    s.push(9);

    // 🔹 Display original unsorted stack
    cout << "Original ";
    printStack(s);

    // 🔹 Sort the stack (ascending order)
    sortStack(s);

    // 🔹 Display sorted stack
    cout << "Sorted ";
    printStack(s);

    return 0;
}
