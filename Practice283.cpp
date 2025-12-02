#include <iostream>
#include <queue>
using namespace std;

// ======================================================
// Node Class
// ======================================================
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

// ======================================================
// Build Tree Using Recursion
// Input: Enter -1 for NULL
// ======================================================
Node* buildTree() {
    int data;
    cout << "Enter data: ";
    cin >> data;

    // Base case for NULL node
    if (data == -1) {
        return NULL;
    }

    // Create node
    Node* root = new Node(data);

    cout << "Enter left child of " << data << endl;
    root->left = buildTree();

    cout << "Enter right child of " << data << endl;
    root->right = buildTree();

    return root;
}

// ======================================================
// Height of Binary Tree
// ======================================================
int height(Node* root) {
    if (root == NULL)
        return 0;

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    return max(leftHeight, rightHeight) + 1;
}

// ======================================================
// Diameter of Binary Tree (O(n²) version)
// ======================================================
int diameterOfBinaryTree(Node* root) {
    if (root == NULL)
        return 0;

    int op1 = diameterOfBinaryTree(root->left);
    int op2 = diameterOfBinaryTree(root->right);
    int op3 = height(root->left) + height(root->right);

    return max(op1, max(op2, op3));
}

// ======================================================
// Inorder Traversal (L N R)
// ======================================================
void inorderTraversal(Node* root) {
    if (root == NULL)
        return;

    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

// ======================================================
// Preorder Traversal (N L R)
// ======================================================
void preorderTraversal(Node* root) {
    if (root == NULL)
        return;

    cout << root->data << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

// ======================================================
// Postorder Traversal (L R N)
// ======================================================
void postorderTraversal(Node* root) {
    if (root == NULL)
        return;

    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout << root->data << " ";
}

// ======================================================
// Main Function
// ======================================================
int main() {
    Node* root = buildTree();

    cout << "\nInorder Traversal: ";
    inorderTraversal(root);

    cout << "\nPreorder Traversal: ";
    preorderTraversal(root);

    cout << "\nPostorder Traversal: ";
    postorderTraversal(root);

    cout << "\n\nHeight of Tree = " << height(root);
    cout << "\nDiameter of Tree = " << diameterOfBinaryTree(root) << endl;

    return 0;
}
