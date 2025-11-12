#include <iostream>
#include <stack>
#include <vector>
#include <climits>
using namespace std;

// ==========================================================
// ✅ CLASS: MinStack
// ----------------------------------------------------------
// A special stack implementation that supports the following:
//   1️⃣ push(x): Inserts an element into the stack.
//   2️⃣ pop(): Removes the top element.
//   3️⃣ top(): Returns the top element.
//   4️⃣ getMin(): Returns the minimum element in O(1) time.
// ----------------------------------------------------------
// Approach:
// Each element in the internal stack (vector) is stored as a pair:
//   { value, minimum_value_till_this_point }
// So, for every push, we store both the number and the smallest value
// up to that point — ensuring we can get the minimum instantly.
// ==========================================================
class MinStack {
public:
    vector<pair<int, int>> st;  // Pair: {value, current_minimum}

    // ----------------------------------------------------------
    // ✅ Function: push(int val)
    // Inserts a new element and updates the minimum value at that level.
    // ----------------------------------------------------------
    void push(int val) {
        if (st.empty()) {
            // First element — the value itself is the minimum.
            st.push_back({val, val});
        } else {
            // Compare new value with the current minimum and store the smaller one.
            int currentMin = min(val, st.back().second);
            st.push_back({val, currentMin});
        }
    }

    // ----------------------------------------------------------
    // ✅ Function: pop()
    // Removes the top element from the stack if it exists.
    // ----------------------------------------------------------
    void pop() {
        if (!st.empty()) {
            st.pop_back();
        } else {
            cout << "⚠️ Stack Underflow! Cannot pop from empty stack.\n";
        }
    }

    // ----------------------------------------------------------
    // ✅ Function: top()
    // Returns the top element of the stack.
    // ----------------------------------------------------------
    int top() {
        if (!st.empty())
            return st.back().first;
        cout << "⚠️ Stack is empty! No top element.\n";
        return INT_MIN; // Sentinel value for empty stack
    }

    // ----------------------------------------------------------
    // ✅ Function: getMin()
    // Returns the minimum element in O(1) time.
    // ----------------------------------------------------------
    int getMin() {
        if (!st.empty())
            return st.back().second;
        cout << "⚠️ Stack is empty! No minimum value.\n";
        return INT_MIN; // Sentinel value for empty stack
    }

    // ----------------------------------------------------------
    // ✅ Function: printStack()
    // Prints the entire stack (for debugging purposes).
    // Each element is shown as (value, current_min).
    // ----------------------------------------------------------
    void printStack() {
        cout << "\nStack state (value, min): ";
        for (auto &p : st) {
            cout << "(" << p.first << ", " << p.second << ") ";
        }
        cout << endl;
    }
};

// ==========================================================
// ✅ MAIN FUNCTION — Demonstrates the MinStack functionality.
// ==========================================================
int main() {
    MinStack ms; // Create an object of MinStack

    cout << "Pushing elements into stack:\n";
    ms.push(5);
    ms.push(2);
    ms.push(8);
    ms.push(1);
    ms.push(3);

    // Display the state of the stack after multiple pushes
    ms.printStack();

    cout << "\nTop element: " << ms.top() << endl;
    cout << "Current minimum: " << ms.getMin() << endl;

    cout << "\nPopping two elements...\n";
    ms.pop();
    ms.pop();

    ms.printStack();

    cout << "Top element: " << ms.top() << endl;
    cout << "Current minimum: " << ms.getMin() << endl;

    return 0;
}
