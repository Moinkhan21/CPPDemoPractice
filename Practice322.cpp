#include <iostream>
#include <queue>
using namespace std;

// ===============================
// Node Definition
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
// Build BST from Inorder Array
// ===============================
Node* bstUsingInorder(int inorder[], int s, int e) {

    // Base case
    if (s > e) {
        return NULL;
    }

    int mid = (s + e) / 2;
    int element = inorder[mid];
    Node* root = new Node(element);

    root->left = bstUsingInorder(inorder, s, mid - 1);
    root->right = bstUsingInorder(inorder, mid + 1, e);

    return root;
}

// ===============================
// Inorder Traversal (Verification)
// ===============================
void inorderTraversal(Node* root) {
    if (!root) return;
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

// ===============================
// Level Order Traversal (Tree Shape)
// ===============================
void levelOrderTraversal(Node* root) {
    if (!root) return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        cout << temp->data << " ";

        if (temp->left) q.push(temp->left);
        if (temp->right) q.push(temp->right);
    }
}

// ===============================
// MAIN (Test Case)
// ===============================
int main() {

    /*
        Sorted Inorder Array:
        1 2 3 4 5 6 7

        Constructed Balanced BST:
                4
              /   \
             2     6
            / \   / \
           1   3 5   7
    */

    int inorder[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(inorder) / sizeof(inorder[0]);

    Node* root = bstUsingInorder(inorder, 0, n - 1);

    cout << "Inorder Traversal of BST: ";
    inorderTraversal(root);
    cout << endl;

    cout << "Level Order Traversal of BST: ";
    levelOrderTraversal(root);
    cout << endl;

    return 0;
}
