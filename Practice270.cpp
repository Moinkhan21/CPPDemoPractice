#include <iostream>
#include <queue>
#include <stack>
using namespace std;

// ======================================================================================
// FUNCTION: interLeaveQueue
// PURPOSE:
//   Interleave the elements of a queue such that:
//       Input : 1 2 3 4 5 6 7
//       Output: 1 5 2 6 3 7 4    (if odd count, last element stays at the end)
//
// APPROACH:
//   1. Split the queue into two halves → first half stored in q2, second half remains in q.
//   2. Interleave by alternatively pushing elements from q2 and q.
//   3. If queue size is odd, last unpaired element is placed at the end.
// ======================================================================================
void interLeaveQueue(queue<int> &q) {
    
    // If queue is empty → nothing to interleave
    int n = q.size();
    if(q.empty())
        return;

    // Calculate half size
    int k = n / 2;
    int count = 0;

    // Temporary queue to store the first half
    queue<int> q2;

    // -----------------------------------------------------------------------------
    // STEP A: Divide the queue into two halves
    // -----------------------------------------------------------------------------
    while(!q.empty()) {
        int temp = q.front();
        q.pop();
        q2.push(temp);   // Push element into first half
        count++;

        if(count == k)
            break;       // Stop after first half is extracted
    }

    // -----------------------------------------------------------------------------
    // STEP B: Interleave elements from first half (q2) and second half (q)
    // -----------------------------------------------------------------------------
    while(!q.empty() && !q2.empty()) {

        // Take from first half
        int first = q2.front();
        q2.pop();
        q.push(first);

        // Take from second half
        int second = q.front();
        q.pop();
        q.push(second);
    }

    // -----------------------------------------------------------------------------
    // STEP C: Handle odd number of elements
    // If size n was odd, the last element of the second half remains unpaired.
    // Push it back to end of queue.
    // -----------------------------------------------------------------------------
    if(n & 1) {   // Check odd
        int element = q.front();
        q.pop();
        q.push(element);
    }
}

// ======================================================================================
// MAIN — Testing interLeaveQueue()
// ======================================================================================
int main() {
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    q.push(7);

    interLeaveQueue(q);

    cout << "Printing Queue: " << endl;
    while(!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    return 0;
}
