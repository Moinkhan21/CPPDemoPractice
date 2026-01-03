#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;

// ======================================================================
// CLASS: Node
// ----------------------------------------------------------------------
// Represents a node in a Binary Tree.
//
// Each node contains:
//   • data  → value stored in the node
//   • left  → pointer to left child
//   • right → pointer to right child
// ======================================================================
class Node {
public:
    int data;
    Node* left;
    Node* right;

    // Constructor initializes node with given value
    // and sets both children to NULL
    Node(int data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

// ======================================================================
// FUNCTION: getMaxSum_helper()
// ----------------------------------------------------------------------
// PURPOSE:
//   Computes the maximum sum of NON-ADJACENT nodes for
//   the subtree rooted at the current node.
//
// RETURNS:
//   pair<int, int>
//     • first  → maximum sum INCLUDING current node
//     • second → maximum sum EXCLUDING current node
//
// CORE IDEA:
//   • If we INCLUDE current node → we CANNOT include its children
//   • If we EXCLUDE current node → we can choose max of
//     including or excluding each child
//
// TIME COMPLEXITY: O(n)
// SPACE COMPLEXITY: O(h) (recursion stack)
// ======================================================================
pair<int, int> getMaxSum_helper(Node* root) {

    // Base case: empty tree
    // Include = 0, Exclude = 0
    if (!root)
        return {0, 0};

    // Recursively solve left and right subtrees
    auto left = getMaxSum_helper(root->left);
    auto right = getMaxSum_helper(root->right);

    // --------------------------------------------------
    // Case 1: INCLUDE current node
    // --------------------------------------------------
    // If we include current node, we must exclude children
    int includeCurrent =
        root->data + left.second + right.second;

    // --------------------------------------------------
    // Case 2: EXCLUDE current node
    // --------------------------------------------------
    // If we exclude current node, we are free to choose
    // the maximum from each child
    int excludeCurrent =
        max(left.first, left.second) +
        max(right.first, right.second);

    return {includeCurrent, excludeCurrent};
}

// ======================================================================
// FUNCTION: getMaxSum()
// ----------------------------------------------------------------------
// PURPOSE:
//   Returns the maximum sum of NON-ADJACENT nodes in the tree.
//
// APPROACH:
//   • Uses helper function to get include/exclude values
//   • Returns the maximum of both
//
// TIME COMPLEXITY: O(n)
// SPACE COMPLEXITY: O(h)
// ======================================================================
int getMaxSum(Node* root) {
    auto ans = getMaxSum_helper(root);
    return max(ans.first, ans.second);
}

// ======================================================================
// MAIN FUNCTION (Test Case)
// ======================================================================
int main() {

    /*
            10
           /  \
          1    2
         / \    \
        3   4    5

    Valid non-adjacent nodes:
    10, 3, 4, 5

    Sum = 10 + 3 + 4 + 5 = 22
    */

    Node* root = new Node(10);
    root->left = new Node(1);
    root->right = new Node(2);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->right->right = new Node(5);

    cout << "Maximum sum of non-adjacent nodes = "
         << getMaxSum(root) << endl;

    return 0;
}
