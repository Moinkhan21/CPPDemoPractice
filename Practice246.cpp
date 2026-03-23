#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// ======================================================================
// PROGRAM: Next Smaller Element (Right Side)
// ----------------------------------------------------------------------
// PURPOSE:
//   For each element in the array, find the NEXT SMALLER element
//   present on its RIGHT side.
//
// EXAMPLE:
//
//   Input:  [2, 1, 4, 3]
//   Output: [1, -1, 3, -1]
//
//   Explanation:
//     2 → next smaller → 1
//     1 → no smaller → -1
//     4 → next smaller → 3
//     3 → no smaller → -1
//
// APPROACH: Monotonic Stack
//
// CORE IDEA:
//
//   • Traverse from RIGHT to LEFT
//   • Maintain a stack of elements
//   • Stack stores potential "next smaller elements"
//
// RULE:
//
//   While stack.top() >= current element → pop
//   (because it cannot be the answer)
//
//   Then:
//     stack.top() → next smaller element
//
// TIME COMPLEXITY: O(N)
// SPACE COMPLEXITY: O(N)
// ======================================================================
int main() {

    // --------------------------------------------------
    // Input array
    // --------------------------------------------------
    vector<int> v;
    v.push_back(2);
    v.push_back(1);
    v.push_back(4);
    v.push_back(3);

    // --------------------------------------------------
    // Stack initialization
    // --------------------------------------------------
    // We push -1 as a sentinel value
    // meaning "no smaller element exists"
    stack<int> s;
    s.push(-1);

    // --------------------------------------------------
    // Result array
    // --------------------------------------------------
    vector<int> ans(v.size());

    // --------------------------------------------------
    // Traverse from RIGHT → LEFT
    // --------------------------------------------------
    for (int i = v.size() - 1; i >= 0; i--) {

        int curr = v[i];

        // --------------------------------------------------
        // Step 1: Remove all elements >= current
        // --------------------------------------------------
        // These cannot be "next smaller"
        while (s.top() >= curr) {
            s.pop();
        }

        // --------------------------------------------------
        // Step 2: Stack top is the answer
        // --------------------------------------------------
        ans[i] = s.top();

        // --------------------------------------------------
        // Step 3: Push current element
        // --------------------------------------------------
        // It may serve as answer for future elements
        s.push(curr);
    }

    // --------------------------------------------------
    // Print result
    // --------------------------------------------------
    cout << "Next Smaller Elements:\n";

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }

    return 0;
}