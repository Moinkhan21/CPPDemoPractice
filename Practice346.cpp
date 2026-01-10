#include <iostream>
#include <queue>
#include <climits>
#include <utility>
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
// Check Max-Heap Order Property
// ===============================
pair<bool, int> solve(Node* root) {

    // Base case
    if (root == NULL) {
        pair<bool, int> p = make_pair(true, INT_MIN);
        return p;
    }

    // Leaf node
    if (root->left == NULL && root->right == NULL) {
        pair<bool, int> p = make_pair(true, root->data);
        return p;
    }

    pair<bool, int> leftAns = solve(root->left);
    pair<bool, int> rightAns = solve(root->right);

    if (leftAns.first == true &&
        rightAns.first == true &&
        root->data > leftAns.second &&
        root->data > rightAns.second) {

        pair<bool, int> p = make_pair(true, root->data);
        return p;
    }
    else {
        pair<bool, int> p = make_pair(false, root->data);
        return p;
    }
}

// ===============================
// MAIN (Test Case)
// ===============================
int main() {

    /*
            10
           /  \
          9    8
         / \
        7   6

    Valid Max-Heap (order property)
    */

    Node* root = new Node(10);
    root->left = new Node(9);
    root->right = new Node(8);
    root->left->left = new Node(7);
    root->left->right = new Node(6);

    pair<bool, int> result = solve(root);

    if (result.first)
        cout << "Tree satisfies Max-Heap order property\n";
    else
        cout << "Tree does NOT satisfy Max-Heap order property\n";

    return 0;
}
