#include <iostream>
#include <climits>
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
// Helper Function
// ===============================
bool solve(TreeNode* root, long long int lb, long long int ub) {
    // Base case
    if (root == NULL)
        return true;

    if (root->val > lb && root->val < ub) {
        bool leftAns = solve(root->left, lb, root->val);
        bool rightAns = solve(root->right, root->val, ub);
        return leftAns && rightAns;
    }
    else {
        return false;
    }
}

// ===============================
// Main Validation Function
// ===============================
bool isValidBST(TreeNode* root) {
    long long int lowerBound = INT_MIN;
    long long int upperBound = INT_MAX;

    bool ans = solve(root, lowerBound, upperBound);
    return ans;
}

// ===============================
// MAIN (Test Cases)
// ===============================
int main() {

    /*
        Valid BST:
            5
           / \
          3   7
         / \   \
        2   4   8
    */

    TreeNode* root1 = new TreeNode(5);
    root1->left = new TreeNode(3);
    root1->right = new TreeNode(7);
    root1->left->left = new TreeNode(2);
    root1->left->right = new TreeNode(4);
    root1->right->right = new TreeNode(8);

    cout << "Tree 1 is BST: " << isValidBST(root1) << endl;

    /*
        Invalid BST:
            5
           / \
          3   7
             /
            4   ❌ violates BST rule
    */

    TreeNode* root2 = new TreeNode(5);
    root2->left = new TreeNode(3);
    root2->right = new TreeNode(7);
    root2->right->left = new TreeNode(4);

    cout << "Tree 2 is BST: " << isValidBST(root2) << endl;

    return 0;
}
