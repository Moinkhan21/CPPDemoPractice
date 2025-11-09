#include <iostream>
#include <stack>
#include <vector>
#include <climits>
using namespace std;

// ==========================================
// ✅ Class: MinStack
// Implements a stack that can also return
// the minimum element in O(1) time.
// ==========================================
class MinStack {
public:
    vector<pair<int, int>> st;  
    // Each pair stores: {value, current_minimum}

    // ✅ Push operation
    void push(int val) {
        if (st.empty()) {
            // First element — both value and min are same
            st.push_back({val, val});
        } else {
            // Second of pair stores min between new val and previous min
            int currentMin = min(val, st.back().second);
            st.push_back({val, currentMin});
        }
    }

    // ✅ Pop operation
    void pop() {
        if (!st.empty()) {
            st.pop_back();
        } else {
            cout << "⚠️ Stack Underflow! Cannot pop from empty stack.\n";
        }
    }

    // ✅ Returns top element of stack
    int top() {
        if (!st.empty())
            return st.back().first;
        cout << "⚠️ Stack is empty! No top element.\n";
        return INT_MIN; // return sentinel value
    }

    // ✅ Returns current minimum element in stack
    int getMin() {
        if (!st.empty())
            return st.back().second;
        cout << "⚠️ Stack is empty! No minimum value.\n";
        return INT_MIN;
    }

    // ✅ Utility function to print stack (for debugging)
    void printStack() {
        cout << "\nStack state (value, min): ";
        for (auto &p : st) {
            cout << "(" << p.first << ", " << p.second << ") ";
        }
        cout << endl;
    }
};

// ==========================================
// ✅ Main Function — Testing the MinStack
// ==========================================
int main() {
    MinStack ms;

    cout << "Pushing elements into stack:\n";
    ms.push(5);
    ms.push(2);
    ms.push(8);
    ms.push(1);
    ms.push(3);

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
