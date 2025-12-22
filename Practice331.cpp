#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// ===============================
// TreeNode Definition
// ===============================
class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) {
        this->val = val;
        left = NULL;
        right = NULL;
    }
};

// ===============================
// Store Inorder Traversal
// ===============================
void inorder(TreeNode* root, vector<int> &in) {
    if (!root) return;

    inorder(root->left, in);
    in.push_back(root->val);
    inorder(root->right, in);
}

// ===============================
// Build Balanced BST from Inorder
// ===============================
TreeNode* buildTree(vector<int> &in, int start, int end) {
    if (start > end) return NULL;

    int mid = (start + end) >> 1;
    TreeNode* root = new TreeNode(in[mid]);

    root->left = buildTree(in, start, mid - 1);
    root->right = buildTree(in, mid + 1, end);

    return root;
}

// ===============================
// Balance BST
// ===============================
TreeNode* balanceBST(TreeNode* root) {
    vector<int> in;
    inorder(root, in);

    // Build balanced BST using inorder traversal
    return buildTree(in, 0, in.size() - 1);
}

// ===============================
// Level Order Traversal (Verification)
// ===============================
void levelOrderTraversal(TreeNode* root) {
    if (!root) return;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* temp = q.front();
        q.pop();

        cout << temp->val << " ";

        if (temp->left) q.push(temp->left);
        if (temp->right) q.push(temp->right);
    }
    cout << endl;
}

// ===============================
// MAIN (Test Case)
// ===============================
int main() {

    /*
        Unbalanced BST:
            1
             \
              2
               \
                3
                 \
                  4

        Balanced BST:
                2
               / \
              1   3
                   \
                    4
    */

    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->right = new TreeNode(3);
    root->right->right->right = new TreeNode(4);

    cout << "Original BST (Level Order):\n";
    levelOrderTraversal(root);

    TreeNode* balancedRoot = balanceBST(root);

    cout << "Balanced BST (Level Order):\n";
    levelOrderTraversal(balancedRoot);

    return 0;
}
