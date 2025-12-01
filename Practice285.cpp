#include <iostream>
#include <queue>
using namespace std;

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

// =======================================
// Build Tree (Recursive)
// =======================================
Node* buildTree() {
    int data;
    cout << "Enter data: ";
    cin >> data;

    if (data == -1) {
        return NULL;   // No node
    }

    Node* root = new Node(data);

    cout << "Enter left child of " << data << endl;
    root->left = buildTree();

    cout << "Enter right child of " << data << endl;
    root->right = buildTree();

    return root;
}

// =======================================
// Height of Tree
// =======================================
int height(Node* root) {
    if (root == NULL)
        return 0;

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    return max(leftHeight, rightHeight) + 1;
}

// =======================================
// Diameter of Tree (O(n²) version)
// =======================================
int diameterOfBinaryTree(Node* root) {
    if (root == NULL)
        return 0;

    int op1 = diameterOfBinaryTree(root->left);
    int op2 = diameterOfBinaryTree(root->right);
    int op3 = height(root->left) + height(root->right);

    return max(op1, max(op2, op3));
}

// =======================================
// Main Function
// =======================================
int main() {
    Node* root = buildTree();

    cout << "\nHeight of the tree = " << height(root) << endl;
    cout << "Diameter of the tree = " << diameterOfBinaryTree(root) << endl;

    return 0;
}
