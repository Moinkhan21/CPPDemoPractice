#include <iostream>
#include <deque>
using namespace std;

// ============================================================================================
// FUNCTION: solve
// PURPOSE:
//   For each sliding window of size k in the array, print the FIRST NEGATIVE INTEGER present.
//   If a window has no negative number, print 0.
//
// EXAMPLE:
//   arr = {12, -1, -7, 8, -15, 30, 16, 28}, k = 3
//   Windows:
//     [12, -1, -7]  → -1
//     [-1, -7, 8]   → -1
//     [-7, 8, -15]  → -7
//     [8, -15, 30]  → -15
//     [-15, 30, 16] → -15
//     [30, 16, 28]  → 0 (no negative number)
//
// LOGIC:
//   - Use deque to store ONLY THE INDICES of negative numbers for efficient window tracking.
//   - Maintain the deque such that:
//       • Front → index of first negative element in the current window
//       • Remove indices that go out of the current window
// ============================================================================================
void solve(int arr[], int n, int k) {

    deque<int> q;  // will store indices of negative numbers

    // ----------------------------------------------------------------------------------------
    // STEP 1: Process the FIRST window (i = 0 to k-1)
    // ----------------------------------------------------------------------------------------
    for (int i = 0; i < k; i++) {
        if (arr[i] < 0) {
            q.push_back(i);  // store index of negative element
        }
    }

    // ----------------------------------------------------------------------------------------
    // STEP 2: Process the REMAINING windows
    // Window range = [i-k+1 ... i]
    // ----------------------------------------------------------------------------------------
    for (int i = k; i < n; i++) {

        // Print the result for the PREVIOUS window
        if (q.empty()) {
            cout << 0 << " ";               // no negative number
        } else {
            cout << arr[q.front()] << " ";  // first negative number in the window
        }

        // ------------------------------------------------------------------------------------
        // Remove elements that are OUT OF CURRENT WINDOW
        // Condition: index difference ≥ k → element has moved out
        // ------------------------------------------------------------------------------------
        while (!q.empty() && (i - q.front() >= k)) {
            q.pop_front();
        }

        // ------------------------------------------------------------------------------------
        // Add the CURRENT element if it is negative
        // ------------------------------------------------------------------------------------
        if (arr[i] < 0) {
            q.push_back(i);
        }
    }

    // ----------------------------------------------------------------------------------------
    // STEP 3: Print result for the LAST window
    // ----------------------------------------------------------------------------------------
    if (q.empty()) {
        cout << 0 << " ";
    } else {
        cout << arr[q.front()] << " ";
    }
}

// ============================================================================================
// MAIN — Testing solve()
// ============================================================================================
int main() {

    int arr[] = {12, -1, -7, 8, -15, 30, 16, 28};
    int size = 8;
    int k = 3;

    solve(arr, size, k);

    return 0;
}
