#include <iostream>
#include <queue>
#include <stack>
using namespace std;

// =====================================================================================
// FUNCTION: reversQueue
// PURPOSE:
//     Reverse a queue using an auxiliary stack.
// APPROACH:
//     1. Remove all elements from the queue and push them into a stack.
//        (This reverses order because stack is LIFO)
//     2. Pop all elements from the stack back into the queue.
//        (This maintains reversed order inside the queue)
// =====================================================================================
void reversQueue(queue<int> &q) {
    stack<int> s;   // Stack used to reverse order

    // ------------------------------------------------------------
    // STEP 1: Move all elements from queue → stack
    // ------------------------------------------------------------
    while (!q.empty()) {
        int element = q.front();  // Get front of queue
        q.pop();                  // Remove from queue
        s.push(element);          // Push into stack
        // Now stack stores elements in order of removal (reversed)
    }

    // ------------------------------------------------------------
    // STEP 2: Move all elements from stack → queue
    // ------------------------------------------------------------
    while (!s.empty()) {
        int element = s.top();  // Top of stack is last pushed element
        s.pop();                // Remove from stack
        q.push(element);        // Add back to queue
        // Queue receives elements in reversed order
    }
}

// =====================================================================================
// MAIN FUNCTION — Test queue reversal using a stack
// =====================================================================================
int main() {
    queue<int> q;

    // Initial queue: 3 → 6 → 9 → 2 → 8
    q.push(3);
    q.push(6);
    q.push(9);
    q.push(2);
    q.push(8);

    // Reverse queue using stack
    reversQueue(q);

    cout << "Printing Queue" << endl;

    // Expected output: 8 2 9 6 3
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    return 0;
}
