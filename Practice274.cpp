#include <iostream>
#include <stack>
using namespace std;

// =====================================================================
// CLASS: MyQueue
// ---------------------------------------------------------------------
// PURPOSE:
//   Implement a queue (FIFO) using two stacks (LIFO).
//
//   We use:
//      • s1 → for pushing new elements
//      • s2 → for popping elements in queue order
//
// MECHANISM:
//   When popping or getting front:
//      If s2 is empty → Move all elements from s1 → s2,
//      reversing their order. Now the oldest element
//      (true queue front) appears on top of s2.
//
// COMPLEXITY:
//   push()   → O(1)
//   pop()    → Amortized O(1)   (transfer happens rarely)
//   front()  → Amortized O(1)
//   empty()  → O(1)
// =====================================================================
class MyQueue {
public:
    stack<int> s1, s2;   // Two stacks to simulate queue behavior

    // -----------------------------------------------------------
    // FUNCTION: push(int x)
    // -----------------------------------------------------------
    // PURPOSE:
    //   Insert an element into the queue.
    //
    // APPROACH:
    //   Always push into s1. This maintains insertion order.
    // -----------------------------------------------------------
    void push(int x) {
        s1.push(x);  // Directly push new element into stack 1
    }

    // -----------------------------------------------------------
    // FUNCTION: pop()
    // -----------------------------------------------------------
    // PURPOSE:
    //   Remove and return the FRONT element of the queue.
    //
    // APPROACH:
    //   • If both stacks are empty → queue is empty.
    //   • If s2 is empty, move all items from s1 → s2.
    //       This reversal brings the oldest inserted element
    //       to the top of s2 (correct queue front).
    //   • Pop from s2 and return.
    // -----------------------------------------------------------
    int pop() {
        if (empty()) {
            cout << "Queue is empty! Cannot pop.\n";
            return -1;  // Error value
        }

        // If s2 is empty, transfer all items from s1 → s2
        // This ensures the correct FIFO behavior
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());  // Move top of s1 → s2
                s1.pop();           // Remove from s1
            }
        }

        // Now s2.top() holds the queue front
        int val = s2.top();
        s2.pop();  // Remove the front element
        return val;
    }

    // -----------------------------------------------------------
    // FUNCTION: front()
    // -----------------------------------------------------------
    // PURPOSE:
    //   Return the FRONT element without removing it.
    //
    // APPROACH:
    //   • If queue is empty → display message.
    //   • If s2 is empty → move elements from s1 → s2.
    //   • Then the top of s2 is the queue front.
    // -----------------------------------------------------------
    int front() {
        if (empty()) {
            cout << "Queue is empty! No front element.\n";
            return -1;  // Error value
        }

        // Transfer elements only if s2 is empty
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }

        // Return the front element (top of s2)
        return s2.top();
    }

    // -----------------------------------------------------------
    // FUNCTION: empty()
    // -----------------------------------------------------------
    // PURPOSE:
    //   Check if BOTH stacks are empty.
    //
    // WHY BOTH?
    //   Because elements may exist in either stack at any time.
    // -----------------------------------------------------------
    bool empty() {
        return (s1.empty() && s2.empty());
    }
};

// =====================================================================
// MAIN FUNCTION — Testing the MyQueue implementation
// =====================================================================
int main() {

    MyQueue q;  // Create queue object

    // -------------------------------
    // Insert elements into the queue
    // -------------------------------
    q.push(10);
    q.push(20);
    q.push(30);

    // Expected: front = 10 (first pushed)
    cout << "Front: " << q.front() << endl;

    // Pop removes 10 (true front)
    cout << "Popped: " << q.pop() << endl;

    // Now 20 should be the new front
    cout << "Front: " << q.front() << endl;

    // Push new value 40
    q.push(40);

    // Pop results
    cout << "Popped: " << q.pop() << endl;  // Removes 20
    cout << "Popped: " << q.pop() << endl;  // Removes 30

    // Now only 40 remains
    cout << "Front: " << q.front() << endl;
    cout << "Popped: " << q.pop() << endl;

    // Queue is now empty
    cout << "Is queue empty? "
         << (q.empty() ? "Yes" : "No") << endl;

    return 0;
}
