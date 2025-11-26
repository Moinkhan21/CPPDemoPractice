#include <iostream>
#include <queue>
#include <stack>
using namespace std;

// =======================================================================================
// FUNCTION: reverseQueueRecursion
// PURPOSE:
//   Recursively reverses a queue WITHOUT using any extra data structure (like stack).
// APPROACH:
//   1. Remove (pop) the front element of the queue.
//   2. Recursively reverse the remaining queue.
//   3. Push the removed element back at the rear.
// RESULT:
//   Elements are added back in reverse order as recursion unwinds.
// =======================================================================================
void reverseQueueRecursion(queue<int> & q) {

    // ------------------------
    // BASE CASE:
    // When queue becomes empty, simply return.
    // No further elements are left to reverse.
    // ------------------------
    if (q.empty())
        return;

    // ------------------------
    // STEP A:
    // Store and remove the front element.
    // This element will be placed at the BACK after recursion finishes.
    // ------------------------
    int temp = q.front();
    q.pop();

    // ------------------------
    // STEP B:
    // Recursively reverse the smaller queue (remaining elements).
    // ------------------------
    reverseQueueRecursion(q);

    // ------------------------
    // STEP C:
    // Insert the stored element at the BACK of the queue.
    // This ensures reversed order as recursion unwinds.
    // ------------------------
    q.push(temp);
}

// =======================================================================================
// MAIN FUNCTION — Test the queue reversal using recursion
// =======================================================================================
int main() {
    queue<int> q;

    // Initial queue: 3 6 9 2 8
    q.push(3);
    q.push(6);
    q.push(9);
    q.push(2);
    q.push(8);

    // Reverse queue using recursion
    reverseQueueRecursion(q);

    cout << "Printing Queue" << endl;

    // Output should be: 8 2 9 6 3
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    return 0;
}
