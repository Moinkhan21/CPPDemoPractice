#include <iostream>
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

// Build tree recursively. Use -1 to indicate NULL.
Node* buildTree() {
    int data;
    cout << "Enter data (-1 for NULL): ";
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

// Find pointer to node with given value (returns first match in tree)
Node* findNode(Node* root, int val) {
    if (root == NULL) return NULL;
    if (root->data == val) return root;

    Node* left = findNode(root->left, val);
    if (left) return left;
    return findNode(root->right, val);
}

// Lowest Common Ancestor (binary tree version)
// Returns pointer to LCA node, or NULL if neither node is present in subtree.
Node* lowestCommonAncestor(Node* root, Node* p, Node* q) {
    // Base case
    if (root == NULL) return NULL;

    // If current node is p or q, return it
    if (root == p || root == q) return root;

    // Search left and right subtrees
    Node* leftAns = lowestCommonAncestor(root->left, p, q);
    Node* rightAns = lowestCommonAncestor(root->right, p, q);

    // If both sides return non-NULL, current root is LCA
    if (leftAns != NULL && rightAns != NULL)
        return root;

    // Otherwise return the non-NULL child (if any), or NULL
    return (leftAns != NULL) ? leftAns : rightAns;
}

int main() {
    // Build tree
    Node* root = buildTree();

    // Read values for which LCA is required
    int val1, val2;
    cout << "Enter value of first node: ";
    cin >> val1;
    cout << "Enter value of second node: ";
    cin >> val2;

    // Find node pointers (by value)
    Node* p = findNode(root, val1);
    Node* q = findNode(root, val2);

    if (!p || !q) {
        if (!p) cout << "Node with value " << val1 << " not found in tree." << endl;
        if (!q) cout << "Node with value " << val2 << " not found in tree." << endl;
        return 0;
    }

    Node* lca = lowestCommonAncestor(root, p, q);
    if (lca)
        cout << "Lowest Common Ancestor of " << val1 << " and " << val2 << " is: " << lca->data << endl;
    else
        cout << "Lowest Common Ancestor not found." << endl;

    return 0;
}
