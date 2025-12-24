#include <iostream>
#include <vector>
#include <climits>
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
// Helper: Build BST from Preorder
// ===============================
TreeNode* build(int &i, int min, int max, vector<int> &preorder) {
    if (i >= preorder.size()) {
        return nullptr;
    }

    TreeNode* root = nullptr;

    if (preorder[i] > min && preorder[i] < max) {
        root = new TreeNode(preorder[i++]);
        root->left = build(i, min, root->val, preorder);
        root->right = build(i, root->val, max, preorder);
    }

    return root;
}

// ===============================
// Main Function
// ===============================
TreeNode* bstFromPreorder(vector<int> &preorder) {
    int min = INT_MIN;
    int max = INT_MAX;
    int i = 0;
    return build(i, min, max, preorder);
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
        Preorder:
        [8, 5, 1, 7, 10, 12]

        Constructed BST:
                8
               / \
              5   10
             / \    \
            1   7    12
    */

    vector<int> preorder = {8, 5, 1, 7, 10, 12};

    TreeNode* root = bstFromPreorder(preorder);

    cout << "Level Order Traversal of BST:\n";
    levelOrderTraversal(root); 

    return 0;
}
