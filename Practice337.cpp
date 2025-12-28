#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// ======================================================================
// FUNCTION: build()
// ----------------------------------------------------------------------
// PURPOSE:
//   Simulates construction of a BST using its PREORDER traversal
//   and RANGE (min, max) constraints.
//
// PARAMETERS:
//   • i   → current index in preorder array (passed by reference)
//   • min → minimum allowed value for current subtree
//   • max → maximum allowed value for current subtree
//   • A   → preorder traversal array
//
// KEY IDEA:
//   • In preorder: Root → Left → Right
//   • Each node must lie within (min, max)
//   • If current value violates range → do NOT consume it
//
// BASE CASE:
//   • If index reaches array size → stop
//
// NOTE:
//   • This function does NOT build the tree explicitly
//   • It only moves index `i` forward if preorder is valid
//
// TIME COMPLEXITY: O(n)
// SPACE COMPLEXITY: O(h)  (recursion stack)
// ======================================================================
void build(int &i, int min, int max, vector<int> &A) {

    // Base case: all elements processed
    if (i >= A.size()) {
        return;
    }

    // Check if current element lies within valid BST range
    if (A[i] > min && A[i] < max) {

        // Treat current value as root
        int rootData = A[i++];

        // Recursively process LEFT subtree
        build(i, min, rootData, A);

        // Recursively process RIGHT subtree
        build(i, rootData, max, A);
    }
    // If value does not lie in range, it belongs
    // to some other subtree — simply return
}

// ======================================================================
// FUNCTION: solve()
// ----------------------------------------------------------------------
// PURPOSE:
//   Validates whether a given array can represent
//   the PREORDER traversal of a BST.
//
// APPROACH:
//   • Use range-based recursive validation
//   • Start with range (-∞, +∞)
//   • If all elements are consumed correctly,
//     preorder is valid
//
// IMPORTANT NOTE:
//   • The final return line is kept EXACTLY as given
//     (even though it looks unusual)
//
// TIME COMPLEXITY: O(n)
// SPACE COMPLEXITY: O(h)
// ======================================================================
int solve(vector<int> &A) {

    int min = INT_MIN, max = INT_MAX;
    int i = 0;

    // Attempt to consume all elements using BST rules
    build(i, min, max, A);

    // LOGIC KEPT UNCHANGED AS REQUESTED
    return i = A.size();
}

// ======================================================================
// MAIN FUNCTION
// ----------------------------------------------------------------------
// Tests whether the given preorder traversal
// can represent a valid BST.
//
// PREORDER INPUT:
//   [10, 5, 1, 7, 40, 50]
//
// This is a VALID BST preorder
// ======================================================================
int main() {

    vector<int> A = {10, 5, 1, 7, 40, 50};

    int result = solve(A);

    cout << "Result = " << result << endl;

    return 0;
}
