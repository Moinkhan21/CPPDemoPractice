#include <iostream>
#include <queue>
#include <stack>
using namespace std;

// =====================================================================================
// FUNCTION: reverseKElements
// PURPOSE:
//   Reverse the first K elements of a queue while keeping the remaining elements
//   in the same order.
//
// EXAMPLE:
//   Input Queue  : 3 6 9 2 8
//   K = 3
//   Output Queue : 9 6 3 2 8
//
// APPROACH:
//   Step A → Move first K elements from queue → stack
//   Step B → Pop stack (reverses order) → push back into queue
//   Step C → Move remaining (n - k) elements from front → back to maintain order
// =====================================================================================
void reverseKElements(queue<int> &q, int k) {

    // Stack for reversing
    stack<int> s;
    int count = 0;
    int n = q.size();   // Total number of elements

    // If k is invalid (negative, zero, or > size) → do nothing
    if(k <= 0 || k > n)
        return;

    // -----------------------------------------------------------------
    // STEP A: Move first K elements from queue to stack
    //         This reverses their order when popped
    // -----------------------------------------------------------------
    while(!q.empty()) {
        int temp = q.front();
        q.pop();
        s.push(temp);   // push into stack
        count++;

        if(count == k)
            break;      // stop after K elements
    }

    // -----------------------------------------------------------------
    // STEP B: Pop stack elements and push back to queue
    //         (This puts reversed K elements at front of queue)
    // -----------------------------------------------------------------
    while(!s.empty()){
        int temp = s.top();
        s.pop();
        q.push(temp);
    }

    // -----------------------------------------------------------------
    // STEP C: Move remaining (n - k) elements from front → back
    //         to maintain their original order after reversed block
    // -----------------------------------------------------------------
    count = 0;
    while(!q.empty() && n - k != 0) {
        int temp = q.front();
        q.pop();
        q.push(temp);   // rotate element to back
        count++;

        if(count == n - k)
            break;
    }

}

// =====================================================================================
// MAIN — Testing reverseKElements()
// =====================================================================================
int main() {
    queue<int> q;
    q.push(3);
    q.push(6);
    q.push(9);
    q.push(2);
    q.push(8);

    reverseKElements(q, 3);

    cout << "Printing Queue with reverse K elements: " << endl;
    while(!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    return 0;
}
