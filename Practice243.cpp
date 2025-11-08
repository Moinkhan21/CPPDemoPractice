#include <iostream>
#include <stack>
using namespace std;

// ===============================================
// ✅ Helper Function: Insert element into sorted stack
// ===============================================
void insertSorted(stack<int>& s, int target) {
    // Base case — if stack is empty OR top element is smaller/equal to target
    if (s.empty() || s.top() <= target) {
        s.push(target);
        return;
    }

    // Otherwise, remove top and recurse
    int topElement = s.top();
    s.pop();

    insertSorted(s, target);

    // Backtrack — push back the removed element
    s.push(topElement);
}

// ===============================================
// ✅ Recursive Function: Sort the stack
// ===============================================
void sortStack(stack<int>& s) {
    // Base case — empty stack
    if (s.empty()) return;

    // Remove top element
    int topElement = s.top();
    s.pop();

    // Sort remaining stack recursively
    sortStack(s);

    // Insert the removed element in the sorted stack
    insertSorted(s, topElement);
}

// ===============================================
// ✅ Helper Function: Print stack (top → bottom)
// ===============================================
void printStack(stack<int> s) {  // Passed by value to preserve original
    cout << "Stack (top → bottom): ";
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

// ===============================================
// ✅ Main Function
// ===============================================
int main() {
    stack<int> s;

    // Push unsorted values
    s.push(7);
    s.push(11);
    s.push(3);
    s.push(5);
    s.push(9);

    cout << "Original ";
    printStack(s);

    // Sort the stack (ascending order)
    sortStack(s);

    cout << "Sorted ";
    printStack(s);

    return 0;
}
