#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
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

// Global containers (as per your logic)
vector<TreeNode*> ans;
unordered_map<string, int> subTreeMap;

// ===============================
// Preorder Serialization
// ===============================
string preorder(TreeNode* root) {
    if (!root) return "N";

    string curr = to_string(root->val);
    string l = preorder(root->left);
    string r = preorder(root->right);

    string s = curr + "," + l + "," + r;

    if (subTreeMap.find(s) != subTreeMap.end()) {
        if (subTreeMap[s] == 1)
            ans.push_back(root);
        subTreeMap[s]++;
    }
    else {
        subTreeMap[s] = 1;
    }

    return s;
}

// ===============================
// Main Function
// ===============================
vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
    ans.clear();
    subTreeMap.clear();

    preorder(root);
    return ans;
}

// ===============================
// MAIN (Test Case)
// ===============================
int main() {

    /*
            1
           / \
          2   3
         /   / \
        4   2   4
           /
          4

    Duplicate Subtrees:
      - Subtree rooted at node 4
      - Subtree rooted at node 2 (with left child 4)
    */

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->right->left = new TreeNode(2);
    root->right->right = new TreeNode(4);
    root->right->left->left = new TreeNode(4);

    vector<TreeNode*> duplicates = findDuplicateSubtrees(root);

    cout << "Duplicate subtree roots: ";
    for (auto node : duplicates) {
        cout << node->val << " ";
    }
    cout << endl;

    return 0;
}
