#include <iostream>
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
// FUNCTION: isSameTree()
// ===============================
bool isSameTree(TreeNode* p, TreeNode* q) {

    // Case 1: Both NULL → same
    if (!p && !q)
        return true;

    // Case 2: One null and the other not → not same
    if (!p || !q)
        return false;

    // Case 3: Both exist → compare values + subtrees
    return (p->val == q->val)
        && isSameTree(p->left, q->left)
        && isSameTree(p->right, q->right);
}


// ===============================
// MAIN FUNCTION (Sample Test)
// ===============================
int main() {

    /* Tree 1
            1
           / \
          2   3
    */
    TreeNode* p = new TreeNode(1);
    p->left = new TreeNode(2);
    p->right = new TreeNode(3);

    /* Tree 2
            1
           / \
          2   3
    */
    TreeNode* q = new TreeNode(1);
    q->left = new TreeNode(2);
    q->right = new TreeNode(3);

    if (isSameTree(p, q))
        cout << "Trees are SAME\n";
    else
        cout << "Trees are NOT SAME\n";

    return 0;
}
