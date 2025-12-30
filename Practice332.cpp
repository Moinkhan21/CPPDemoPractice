#include <iostream>
using namespace std;

// ======================================================================
// STRUCT: Node
// ----------------------------------------------------------------------
// Represents a node in a Binary Search Tree (BST).
//
// Each node contains:
//   • data  → value stored in the node
//   • left  → pointer to left child
//   • right → pointer to right child
// ======================================================================
struct Node {
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
// FUNCTION: findNodeCount()
// ----------------------------------------------------------------------
// PURPOSE:
//   Counts the total number of nodes in a BST
//   using MORRIS INORDER TRAVERSAL.
//
// WHY MORRIS TRAVERSAL?
//   • No recursion
//   • No stack
//   • O(1) extra space
//
// IDEA:
//   • Temporarily create threads using inorder predecessor
//   • Visit each node exactly once
//
// TIME COMPLEXITY: O(n)
// SPACE COMPLEXITY: O(1)
// ======================================================================
int findNodeCount(Node* root) {

    int count = 0;
    Node* curr = root;

    while (curr) {

        // Case 1: No left child
        if (curr->left == nullptr) {
            count++;                  // Visit node
            curr = curr->right;       // Move right
        }
        else {
            // Find inorder predecessor
            Node* pred = curr->left;
            while (pred->right != curr && pred->right) {
                pred = pred->right;
            }

            // Create thread
            if (pred->right == nullptr) {
                pred->right = curr;
                curr = curr->left;
            }
            // Thread exists → revert & visit
            else {
                pred->right = nullptr;
                count++;              // Visit node
                curr = curr->right;
            }
        }
    }
    return count;
}

// ======================================================================
// FUNCTION: findActualMedian()
// ----------------------------------------------------------------------
// PURPOSE:
//   Finds the MEDIAN value of BST using Morris traversal
//   once total node count is known.
//
// LOGIC:
//   • Perform inorder traversal
//   • Track visit count
//   • Capture middle element(s)
//
// CASES:
//   • Odd number of nodes → single middle value
//   • Even number of nodes → average of two middle values
//
// TIME COMPLEXITY: O(n)
// SPACE COMPLEXITY: O(1)
// ======================================================================
float findActualMedian(Node* root, int n) {

    int i = 0;

    // Target indices
    int odd1 = (n + 1) / 2, oddVal = -1;
    int even1 = n / 2, even1Val = -1;
    int even2 = n / 2 + 1, even2Val = -1;

    Node* curr = root;

    while (curr) {

        // Case 1: No left child
        if (curr->left == nullptr) {
            i++;   // Visit count

            // Capture required positions
            if (i == odd1) oddVal = curr->data;
            if (i == even1) even1Val = curr->data;
            if (i == even2) even2Val = curr->data;

            curr = curr->right;
        }
        else {
            // Find inorder predecessor
            Node* pred = curr->left;
            while (pred->right != curr && pred->right) {
                pred = pred->right;
            }

            // Create thread
            if (pred->right == nullptr) {
                pred->right = curr;
                curr = curr->left;
            }
            // Thread exists → revert & visit
            else {
                pred->right = nullptr;
                i++;

                if (i == odd1) oddVal = curr->data;
                if (i == even1) even1Val = curr->data;
                if (i == even2) even2Val = curr->data;

                curr = curr->right;
            }
        }
    }

    // Even number of nodes
    if ((n & 1) == 0) {
        return (even1Val + even2Val) / 2.0;
    }
    // Odd number of nodes
    else {
        return oddVal;
    }
}

// ======================================================================
// FUNCTION: findMedian()
// ----------------------------------------------------------------------
// PURPOSE:
//   Wrapper function to compute median of BST.
//
// STEPS:
//   1️⃣ Count total nodes
//   2️⃣ Find median using Morris traversal
// ======================================================================
float findMedian(Node* root) {

    int n = findNodeCount(root);
    return findActualMedian(root, n);
}

// ======================================================================
// MAIN FUNCTION
// ----------------------------------------------------------------------
// Builds a BST and computes its median.
//
// TREE STRUCTURE:
//
//            6
//           / \
//          3   8
//         / \   \
//        1   4   9
//
// INORDER:
//   1 3 4 6 8 9
//
// MEDIAN:
//   (4 + 6) / 2 = 5
// ======================================================================
int main() {

    // Constructing BST
    Node* root = new Node(6);
    root->left = new Node(3);
    root->right = new Node(8);
    root->left->left = new Node(1);
    root->left->right = new Node(4);
    root->right->right = new Node(9);

    cout << "Median of BST = " << findMedian(root) << endl;

    return 0;
}
