#include <iostream>
using namespace std;

// ===============================
// Node Structure
// ===============================
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

// ===============================
// FUNCTION: sum()
// Converts binary tree to Sum Tree
// Returns: total sum of original subtree
// ===============================
int sum(Node* root) {
    if (!root) return 0;

    // Leaf node: replace with 0 and return original data
    if (!root->left && !root->right) {
        int temp = root->data;
        root->data = 0;
        return temp;
    }

    // Recursively get left & right subtree sums
    int lSum = sum(root->left);
    int rSum = sum(root->right);

    // Store original value
    int temp = root->data;

    // Convert current node to sum of children
    root->data = lSum + rSum;

    // Return total sum of subtree (new value + old value)
    return root->data + temp;
}

// ===============================
// FUNCTION: toSumTree()
// Wrapper function
// ===============================
void toSumtree(Node* node) {
    sum(node);
}

// ===============================
// Helper function: Print Tree (Inorder)
// ===============================
void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// ===============================
// MAIN FUNCTION (Test Case)
// ===============================
int main() {

    /*
            10
           /  \
          -2   6
         / \   / \
        8  -4 7   5

    After Sum Tree Conversion:
            12
           /  \
          4    12
         / \   / \
        0   0 0   0
    */

    Node* root = new Node(10);
    root->left = new Node(-2);
    root->right = new Node(6);
    root->left->left = new Node(8);
    root->left->right = new Node(-4);
    root->right->left = new Node(7);
    root->right->right = new Node(5);

    toSumtree(root);

    cout << "Inorder Traversal of Sum Tree:\n";
    inorder(root);
    cout << endl;

    return 0;
}
