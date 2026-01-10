#include <iostream>
#include <queue>
#include <climits>
#include <utility>
using namespace std;

// =====================================================
// Node Definition
// -----------------------------------------------------
// Each node of the binary tree contains:
//   • data  → value stored in the node
//   • left  → pointer to left child
//   • right → pointer to right child
// =====================================================
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

// =====================================================
// FUNCTION: solve()
// -----------------------------------------------------
// PURPOSE:
//   Checks whether the given binary tree satisfies
//   the MAX-HEAP ORDER PROPERTY.
//
// WHAT IS MAX-HEAP ORDER PROPERTY?
//   • Parent node value > left child value
//   • Parent node value > right child value
//
// NOTE:
//   This function ONLY checks ORDER PROPERTY.
//   It does NOT check whether tree is COMPLETE.
//
// RETURN TYPE: pair<bool, int>
//   • first  → whether subtree is valid max-heap
//   • second → maximum value in the subtree
// =====================================================
pair<bool, int> solve(Node* root) {

    // -------------------------------------------------
    // BASE CASE 1: Empty tree
    // -------------------------------------------------
    // An empty tree is considered a valid heap.
    // We return:
    //   • true → heap property satisfied
    //   • INT_MIN → so parent comparison works correctly
    // -------------------------------------------------
    if (root == NULL) {
        pair<bool, int> p = make_pair(true, INT_MIN);
        return p;
    }

    // -------------------------------------------------
    // BASE CASE 2: Leaf node
    // -------------------------------------------------
    // A leaf node always satisfies heap order property
    // because it has no children.
    // -------------------------------------------------
    if (root->left == NULL && root->right == NULL) {
        pair<bool, int> p = make_pair(true, root->data);
        return p;
    }

    // -------------------------------------------------
    // RECURSIVE STEP:
    // Check left and right subtrees
    // -------------------------------------------------
    pair<bool, int> leftAns = solve(root->left);
    pair<bool, int> rightAns = solve(root->right);

    // -------------------------------------------------
    // CHECK MAX-HEAP ORDER PROPERTY
    // -------------------------------------------------
    // Conditions:
    // 1️⃣ Left subtree must be valid
    // 2️⃣ Right subtree must be valid
    // 3️⃣ Root value > max value of left subtree
    // 4️⃣ Root value > max value of right subtree
    // -------------------------------------------------
    if (leftAns.first == true &&
        rightAns.first == true &&
        root->data > leftAns.second &&
        root->data > rightAns.second) {

        // Current subtree is a valid max-heap
        pair<bool, int> p = make_pair(true, root->data);
        return p;
    }
    else {
        // Heap property violated
        pair<bool, int> p = make_pair(false, root->data);
        return p;
    }
}

// =====================================================
// MAIN FUNCTION (Test Case)
// =====================================================
int main() {

    /*
            10
           /  \
          9    8
         / \
        7   6

    ✔ This tree satisfies MAX-HEAP ORDER PROPERTY
    */

    // Constructing the binary tree
    Node* root = new Node(10);
    root->left = new Node(9);
    root->right = new Node(8);
    root->left->left = new Node(7);
    root->left->right = new Node(6);

    // Call solve function
    pair<bool, int> result = solve(root);

    // Output result
    if (result.first)
        cout << "Tree satisfies Max-Heap order property\n";
    else
        cout << "Tree does NOT satisfy Max-Heap order property\n";

    return 0;
}
