#include <iostream>
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
// Find Inorder Successor in BST
// ===============================
Node* inOrderSuccessor(Node* root, Node* x) {

    if (!root || !x) return NULL;

    Node* succ = NULL;
    Node* curr = root;

    while (curr) {
        if (curr->data > x->data) {
            succ = curr;
            curr = curr->left;
        }
        else {
            curr = curr->right;
        }
    }
    return succ;
}

// ===============================
// MAIN (Test Case)
// ===============================
int main() {

    /*
            20
           /  \
         10    30
        /  \
       5   15
            \
             18

    Inorder: 5 10 15 18 20 30
    Successor of 15 → 18
    Successor of 18 → 20
    */

    Node* root = new Node(20);
    root->left = new Node(10);
    root->right = new Node(30);
    root->left->left = new Node(5);
    root->left->right = new Node(15);
    root->left->right->right = new Node(18);

    Node* x = root->left->right;  // 15
    Node* succ = inOrderSuccessor(root, x);

    if (succ)
        cout << "Successor of " << x->data << " is " << succ->data << endl;
    else
        cout << "No successor exists\n";

    x = root->left->right->right; // 18
    succ = inOrderSuccessor(root, x);

    if (succ)
        cout << "Successor of " << x->data << " is " << succ->data << endl;
    else
        cout << "No successor exists\n";

    return 0;
}
