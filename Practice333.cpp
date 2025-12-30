#include <iostream>
#include <unordered_map>
using namespace std;

// ======================================================================
// CLASS: Node
// ----------------------------------------------------------------------
// Represents a node in a Binary Search Tree (BST).
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
// FUNCTION: fun()
// ----------------------------------------------------------------------
// PURPOSE:
//   Helper function to detect a DEAD END in a BST.
//
// WHAT IS A DEAD END?
//   • A leaf node such that no further node can be inserted
//     at that position while maintaining BST properties.
//
// CONDITION FOR DEAD END:
//   For a leaf node with value X:
//     • (X - 1) and (X + 1) are already present in the BST
//
// PARAMETERS:
//   • root    → current node
//   • visited → hash map storing all visited node values
//   • ans     → flag indicating whether dead end is found
//
// APPROACH:
//   • Traverse the tree
//   • Mark every visited node
//   • At leaf nodes, check (value - 1) and (value + 1)
//
// TIME COMPLEXITY: O(n)
// SPACE COMPLEXITY: O(n)
// ======================================================================
void fun(Node* root, unordered_map<int, bool>& visited, bool &ans) {

    // Base case
    if (root == NULL) return;

    // Mark current node as visited
    visited[root->data] = true;

    // --------------------------------------------------
    // Leaf node check
    // --------------------------------------------------
    if (root->left == NULL && root->right == NULL) {

        int xp1 = root->data + 1;

        // Special handling for value = 1
        // (BST values are assumed to be positive)
        int xm1 = (root->data - 1 == 0) ? root->data : root->data - 1;

        // If both adjacent values exist, dead end found
        if (visited.find(xp1) != visited.end() &&
            visited.find(xm1) != visited.end()) {

            ans = true;
            return;
        }
    }

    // Traverse left and right subtrees
    fun(root->left, visited, ans);
    fun(root->right, visited, ans);
}

// ======================================================================
// FUNCTION: isDeadEnd()
// ----------------------------------------------------------------------
// PURPOSE:
//   Determines whether a BST contains a DEAD END.
//
// APPROACH:
//   • Use a hash map to track visited node values
//   • Call recursive helper function
//
// RETURNS:
//   • true  → dead end exists
//   • false → no dead end
// ======================================================================
bool isDeadEnd(Node* root) {

    bool ans = false;
    unordered_map<int, bool> visited;

    fun(root, visited, ans);
    return ans;
}

// ======================================================================
// MAIN FUNCTION
// ----------------------------------------------------------------------
// Builds a BST and checks whether it contains a dead end.
//
// TREE STRUCTURE:
//
//            8
//           / \
//          5   11
//         / \
//        2   7
//         \
//          3
//           \
//            4
//
// DEAD END:
//   Node 4 → no valid insertion possible
// ======================================================================
int main() {

    // Constructing the BST
    Node* root = new Node(8);
    root->left = new Node(5);
    root->right = new Node(11);
    root->left->left = new Node(2);
    root->left->right = new Node(7);
    root->left->left->right = new Node(3);
    root->left->left->right->right = new Node(4);

    // Check for dead end
    if (isDeadEnd(root))
        cout << "Dead End exists in BST\n";
    else
        cout << "No Dead End in BST\n";

    return 0;
}
