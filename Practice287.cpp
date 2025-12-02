#include <iostream>
using namespace std;

// ======================================
// Node class for Binary Tree
// ======================================
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

// ======================================
// Build Tree Recursively using -1 as NULL
// ======================================
Node* buildTree() {
    int data;
    cout << "Enter data: ";
    cin >> data;

    if (data == -1)
        return NULL;

    Node* root = new Node(data);

    cout << "Enter left child of " << data << endl;
    root->left = buildTree();

    cout << "Enter right child of " << data << endl;
    root->right = buildTree();

    return root;
}

// ======================================
// Height of Binary Tree
// ======================================
int height(Node* root) {
    if (root == NULL)
        return 0;

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    return 1 + max(leftHeight, rightHeight);
}

// ======================================
// Check if Tree is Balanced (O(n²) version)
// ======================================
bool isBalanced(Node* root) {
    if (root == NULL)
        return true;

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    int diff = abs(leftHeight - rightHeight);
    bool ans1 = (diff <= 1);

    bool leftAns = isBalanced(root->left);
    bool rightAns = isBalanced(root->right);

    return (ans1 && leftAns && rightAns);
}

// ======================================
// MAIN FUNCTION
// ======================================
int main() {

    Node* root = buildTree();

    cout << "\nHeight of Tree: " << height(root) << endl;

    if (isBalanced(root))
        cout << "The tree is Balanced" << endl;
    else
        cout << "The tree is NOT Balanced" << endl;

    return 0;
}
