#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// ===============================
// Count Nodes
// ===============================
int nodecount(Node* root) {
    if(!root) return 0;
    int l = nodecount(root->left);
    int r = nodecount(root->right);
    return 1 + l + r;
}

// ===============================
// Check Complete Binary Tree (CBT)
// ===============================
bool isCBT(Node* root, int i, int &n) {
    if(!root) return true;
    if(i > n) return false;
    return isCBT(root->left, 2*i, n) &&
           isCBT(root->right, 2*i + 1, n);
}

// ===============================
// Check Max-Heap Order Property
// ===============================
bool isMaxOrder(Node* root) {
    if(!root) return true;

    bool l = isMaxOrder(root->left);
    bool r = isMaxOrder(root->right);

    bool ans = false;

    if(!root->left && !root->right)
        ans = true;
    else if(root->left && !root->right) {
        ans = root->data > root->left->data;
    }
    else {
        ans = root->data > root->left->data &&
              root->data > root->right->data;
    }

    return ans && l && r;
}

// ===============================
// Solution Class
// ===============================
class Solution {
public:
    bool isHeap(Node* tree) {
        int n = nodecount(tree);
        int i = 1;
        return isCBT(tree, i, n) && isMaxOrder(tree);
    }
};

// ===============================
// MAIN FUNCTION
// ===============================
int main() {

    /*
            10
           /  \
          9    8
         / \
        7   6

        This is a valid Max Heap
    */

    Node* root = new Node(10);
    root->left = new Node(9);
    root->right = new Node(8);
    root->left->left = new Node(7);
    root->left->right = new Node(6);

    Solution sol;

    if(sol.isHeap(root))
        cout << "Tree is a Heap" << endl;
    else
        cout << "Tree is NOT a Heap" << endl;

    return 0;
}
