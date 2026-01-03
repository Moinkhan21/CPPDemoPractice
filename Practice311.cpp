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
    // and sets left and right children to NULL
    Node(int data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

// ======================================================================
// FUNCTION: height()
// ----------------------------------------------------------------------
// PURPOSE:
//   For each node, computes two things together:
//     1️⃣ Height of the subtree rooted at this node
//     2️⃣ Maximum sum of the longest root-to-leaf path
//        starting from this node
//
// RETURNS:
//   pair<int, int>
//     • first  → height of subtree
//     • second → maximum sum of the longest path
//
// CORE IDEA:
//   • Recursively calculate left and right subtree results
//   • Compare heights:
//       - If heights are equal → pick larger sum
//       - Else → pick sum from deeper subtree
//
// TIME COMPLEXITY: O(n)
// SPACE COMPLEXITY: O(h)  (recursion stack)
// ======================================================================
pair<int, int> height(Node* root) {

    // Base case: empty tree
    // Height = 0, Sum = 0
    if (!root)
        return {0, 0};

    // Recursively compute left and right subtree info
    auto lh = height(root->left);   // {height, sum}
    auto rh = height(root->right);  // {height, sum}

    // Start sum with current node's value
    int sum = root->data;

    // Case 1: Both subtrees have equal height
    // → choose the path with maximum sum
    if (lh.first == rh.first) {
        sum += max(lh.second, rh.second);
    }
    // Case 2: Left subtree is deeper
    else if (lh.first > rh.first) {
        sum += lh.second;
    }
    // Case 3: Right subtree is deeper
    else {
        sum += rh.second;
    }

    // Return:
    //   • height = max(left height, right height) + 1
    //   • sum    = computed maximum sum
    return {max(lh.first, rh.first) + 1, sum};
}

// ======================================================================
// FUNCTION: sumOfLongRootToLeafPath()
// ----------------------------------------------------------------------
// PURPOSE:
//   Returns the sum of nodes on the LONGEST
//   root-to-leaf path.
//
// APPROACH:
//   • Calls height() helper
//   • Extracts only the sum part
//
// TIME COMPLEXITY: O(n)
// SPACE COMPLEXITY: O(h)
// ======================================================================
int sumOfLongRootToLeafPath(Node* root) {
    auto h = height(root);
    return h.second;
}

// ======================================================================
// MAIN FUNCTION (Test Case)
// ======================================================================
int main() {

    /*
            4
           / \
          2   5
         / \   \
        7   1   2
           /
          6

    Longest root-to-leaf path:
    4 → 2 → 1 → 6

    Sum = 4 + 2 + 1 + 6 = 13
    */

    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(5);
    root->left->left = new Node(7);
    root->left->right = new Node(1);
    root->left->right->left = new Node(6);
    root->right->right = new Node(2);

    cout << "Sum of longest root-to-leaf path = "
         << sumOfLongRootToLeafPath(root) << endl;

    return 0;
}
