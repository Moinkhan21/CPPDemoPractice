#include <iostream>
#include <vector>
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
// Morris Inorder Traversal
// ===============================
vector<int> inorderTraversal(TreeNode* root) {
    vector<int> ans;
    TreeNode* curr = root;

    while (curr) {

        // Left node is NULL, then visit it and go right
        if (curr->left == nullptr) {
            ans.push_back(curr->val);
            curr = curr->right;
        }
        // Left node is NOT NULL
        else {
            // Find inorder predecessor
            TreeNode* pred = curr->left;
            while (pred->right != curr && pred->right) {
                pred = pred->right;
            }

            // Establish link from predecessor to current
            if (pred->right == nullptr) {
                pred->right = curr;
                curr = curr->left;
            }
            else {
                // Left subtree already visited, remove link
                pred->right = nullptr;
                ans.push_back(curr->val);
                curr = curr->right;
            }
        }
    }
    return ans;
}

// ===============================
// MAIN (Test Case)
// ===============================
int main() {

    /*
            4
           / \
          2   5
         / \
        1   3

    Inorder Traversal: 1 2 3 4 5
    */

    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    vector<int> result = inorderTraversal(root);

    cout << "Inorder Traversal: ";
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
