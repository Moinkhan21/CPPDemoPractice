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
// Find Inorder Predecessor in BST
// ===============================
Node* findPredecessor(Node* root, Node* p) {

    // Safety check
    if (!root || !p) return NULL;

    Node* pred = NULL;
    Node* curr = root;

    while (curr) {
        if (curr->data < p->data) {
            pred = curr;
            curr = curr->right;
        }
        else {
            curr = curr->left;
        }
    }
    return pred;
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
    Predecessor of 20 → 18
    Predecessor of 15 → 10
    */

    Node* root = new Node(20);
    root->left = new Node(10);
    root->right = new Node(30);
    root->left->left = new Node(5);
    root->left->right = new Node(15);
    root->left->right->right = new Node(18);

    Node* p = root;  // 20
    Node* pred = findPredecessor(root, p);

    if (pred)
        cout << "Predecessor of " << p->data << " is " << pred->data << endl;
    else
        cout << "No predecessor exists\n";

    p = root->left->right; // 15
    pred = findPredecessor(root, p);

    if (pred)
        cout << "Predecessor of " << p->data << " is " << pred->data << endl;
    else
        cout << "No predecessor exists\n";

    return 0;
}
