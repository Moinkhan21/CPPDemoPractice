#include <iostream>
#include <vector>
using namespace std;

// ======================================================================
// CLASS: TreeNode
// ----------------------------------------------------------------------
// Represents a node in a Binary Tree.
//
// Each node contains:
//   • val   → value stored in the node
//   • left  → pointer to left child
//   • right → pointer to right child
//
// The constructor initializes the node value
// and sets both children to NULL.
// ======================================================================
class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) {
        this->val = val;
        left = NULL;
        right = NULL;
    }
};

// ======================================================================
// FUNCTION: inorderTraversal()
// ----------------------------------------------------------------------
// PURPOSE:
//   Performs Inorder Traversal of a Binary Tree using
//   Morris Traversal technique.
//
// INORDER ORDER:
//   Left → Root → Right
//
// SPECIAL FEATURE OF MORRIS TRAVERSAL:
//   • Traverses the tree WITHOUT recursion
//   • Traverses the tree WITHOUT stack
//   • Uses temporary threaded links
//
// CORE IDEA:
//   If a node has a left child:
//       → find its inorder predecessor
//       → create a temporary link back to the node
//       → move left
//
//   If the link already exists:
//       → remove the link
//       → visit the node
//       → move right
//
// TIME COMPLEXITY: O(N)
//   Each edge is visited at most twice.
//
// SPACE COMPLEXITY: O(1)
//   No recursion or stack used.
// ======================================================================
vector<int> inorderTraversal(TreeNode* root) {

    // Stores the final inorder traversal result
    vector<int> ans;

    // Start traversal from root
    TreeNode* curr = root;

    // Continue traversal until all nodes are processed
    while (curr) {

        // --------------------------------------------------
        // CASE 1: Left child does NOT exist
        // --------------------------------------------------
        // If there is no left subtree,
        // we can directly visit the current node
        // and move to the right child.
        if (curr->left == nullptr) {

            // Visit node
            ans.push_back(curr->val);

            // Move to right subtree
            curr = curr->right;
        }

        // --------------------------------------------------
        // CASE 2: Left child EXISTS
        // --------------------------------------------------
        else {

            // Find the inorder predecessor
            // (Rightmost node in left subtree)
            TreeNode* pred = curr->left;

            while (pred->right != curr && pred->right) {
                pred = pred->right;
            }

            // --------------------------------------------------
            // CASE 2A: Thread not yet created
            // --------------------------------------------------
            if (pred->right == nullptr) {

                // Create temporary thread to current node
                // This allows returning to the node later
                pred->right = curr;

                // Move to left subtree
                curr = curr->left;
            }

            // --------------------------------------------------
            // CASE 2B: Thread already exists
            // --------------------------------------------------
            else {

                // Remove temporary thread
                pred->right = nullptr;

                // Visit current node
                ans.push_back(curr->val);

                // Move to right subtree
                curr = curr->right;
            }
        }
    }

    // Return the inorder traversal result
    return ans;
}

// ======================================================================
// MAIN FUNCTION (Test Case)
// ======================================================================
int main() {

    /*
            4
           / \
          2   5
         / \
        1   3

    Inorder Traversal:
    Left → Root → Right

    Result:
    1 2 3 4 5
    */

    // Constructing the binary tree
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    // Perform Morris Inorder Traversal
    vector<int> result = inorderTraversal(root);

    // Print traversal result
    cout << "Inorder Traversal: ";
    for (int x : result) {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}