#include <iostream>
#include <cmath>
using namespace std;

// ===============================
// TreeNode definition
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

bool isbalanced = true;

int height(TreeNode* root) {
    if(!root) return 0;

    int lh = height(root -> left);
    int rh = height(root -> right);

    //Check for current node, is it balanced?
    if(isbalanced && abs(lh - rh) > 1) {
        isbalanced = false;
    }

    return max(lh, rh) + 1;

}

bool isBalanced(TreeNode* root) {
    height(root);
    return isbalanced;
}

// ===============================
// MAIN FUNCTION (Test Example)
// ===============================
int main() {

    /*
            1
           / \
          2   3
         /
        4
       /
      5
    This tree is NOT balanced
    */

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->left->left = new TreeNode(5);

    if (isBalanced(root))
        cout << "Tree is Balanced\n";
    else
        cout << "Tree is NOT Balanced\n";

    return 0;
}