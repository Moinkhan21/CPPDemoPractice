#include <iostream>
#include <queue>
using namespace std;

class MyStack {
public:
    queue<int> q;  // Single queue used to simulate stack behavior (LIFO)

    // =======================================================================
    // FUNCTION: push(int x)
    // -----------------------------------------------------------------------
    // PURPOSE:
    //   Insert an element onto the stack (LIFO behavior) using only one queue.
    //
    // APPROACH:
    //   Normally, a queue follows FIFO (first in first out), but a stack
    //   requires LIFO (last in first out). To achieve this using one queue:
    //
    //   1. Push the new element into the queue.
    //   2. Rotate all previous elements behind the new element:
    //          e.g., push(10) → [10]
    //                push(20) → [10,20] → rotate → [20,10]
    //                push(30) → [20,10,30] → rotate → [30,20,10]
    //
    //   This ensures the *newly added element always becomes the front*,
    //   which acts as the "top" of the stack.
    //
    // TIME COMPLEXITY:
    //   O(n) per push (due to rotation)
    // =======================================================================
    void push(int x) {
        q.push(x);  // Step 1: Add new element at the back

        // Step 2: Rotate all previous elements behind the new one
        int rotations = q.size() - 1;
        while (rotations--) {
            q.push(q.front());  // Move the front element to the back
            q.pop();            // Remove the moved element from front
        }
    }

    // =======================================================================
    // FUNCTION: pop()
    // -----------------------------------------------------------------------
    // PURPOSE:
    //   Remove and return the top element of the stack.
    //
    // APPROACH:
    //   Since push() ensures the top element is always at the front of queue,
    //   popping is simply removing q.front().
    //
    // EDGE CASE:
    //   If queue is empty → stack is empty.
    //
    // TIME COMPLEXITY:
    //   O(1)
    // =======================================================================
    int pop() {
        if (q.empty()) {
            cout << "Stack is empty! Cannot pop.\n";
            return -1;
        }

        int topElement = q.front();  // Capture top element
        q.pop();                     // Remove it
        return topElement;
    }

    // =======================================================================
    // FUNCTION: top()
    // -----------------------------------------------------------------------
    // PURPOSE:
    //   Return the current top element without removing it.
    //
    // APPROACH:
    //   Because the queue is always rotated after every push(),
    //   the "top" of the stack is simply q.front().
    //
    // TIME COMPLEXITY:
    //   O(1)
    // =======================================================================
    int top() {
        if (q.empty()) {
            cout << "Stack is empty! No top element.\n";
            return -1;
        }
        return q.front();  // Front element is always the top
    }

    // =======================================================================
    // FUNCTION: empty()
    // -----------------------------------------------------------------------
    // PURPOSE:
    //   Check whether the stack is empty.
    //
    // APPROACH:
    //   A stack implemented with one queue is empty
    //   if and only if the queue itself is empty.
    //
    // TIME COMPLEXITY:
    //   O(1)
    // =======================================================================
    bool empty() {
        return q.empty();
    }
};

// ===========================================================================
// MAIN FUNCTION — Demonstrates and tests MyStack implementation
// ===========================================================================
int main() {

    MyStack st;

    // Push elements → stack top becomes last pushed element
    st.push(10);
    st.push(20);
    st.push(30);

    cout << "Top: " << st.top() << endl;      // Expected 30 (LIFO)

    cout << "Pop: " << st.pop() << endl;      // Expected 30
    cout << "Top: " << st.top() << endl;      // Expected 20

    st.push(40);                               // Now 40 is new top
    cout << "Top: " << st.top() << endl;      // Expected 40

    // Pop elements one by one
    cout << "Pop: " << st.pop() << endl;      // Expected 40
    cout << "Pop: " << st.pop() << endl;      // Expected 20
    cout << "Pop: " << st.pop() << endl;      // Expected 10

    // Stack now empty
    cout << "Is empty? "
         << (st.empty() ? "Yes" : "No") << endl;

    return 0;
}
