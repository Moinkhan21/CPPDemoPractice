#include <iostream>
#include <unordered_map>
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
// Helper Function
// ===============================
void fun(Node* root, unordered_map<int, bool>& visited, bool &ans) {
    if (root == 0) return;

    // Visit the node
    visited[root->data] = 1;

    // Leaf node check
    if (root->left == 0 && root->right == 0) {

        int xp1 = root->data + 1;
        int xm1 = root->data - 1 == 0 ? root->data : root->data - 1;

        if (visited.find(xp1) != visited.end() &&
            visited.find(xm1) != visited.end()) {
            ans = true;
            return;
        }
    }

    fun(root->left, visited, ans);
    fun(root->right, visited, ans);
}

// ===============================
// Dead End Detection
// ===============================
bool isDeadEnd(Node* root) {
    bool ans = false;
    unordered_map<int, bool> visited;
    fun(root, visited, ans);
    return ans;
}

// ===============================
// MAIN (Test Case)
// ===============================
int main() {

    /*
            8
           / \
          5   11
         / \
        2   7
         \
          3
           \
            4

    Dead End at node 4
    */

    Node* root = new Node(8);
    root->left = new Node(5);
    root->right = new Node(11);
    root->left->left = new Node(2);
    root->left->right = new Node(7);
    root->left->left->right = new Node(3);
    root->left->left->right->right = new Node(4);

    if (isDeadEnd(root))
        cout << "Dead End exists in BST\n";
    else
        cout << "No Dead End in BST\n";

    return 0;
}
