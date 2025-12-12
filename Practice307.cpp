#include <iostream>
#include <map>
#include <vector>
#include <set>      // for multiset
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
// verticalTraversal FUNCTION
// ===============================
vector<vector<int>> verticalTraversal(TreeNode* root) {
    vector<vector<int>> ans;
    if (!root) return ans;

    queue<pair<TreeNode*, pair<int, int>>> q; // Node, {row, col}
    q.push({root, {0, 0}});

    map<int, map<int, multiset<int>>> mp; // col → row → multiset of values

    while (!q.empty()) {
        auto front = q.front();
        q.pop();

        TreeNode*& node = front.first;
        auto& coordinate = front.second;

        int& row = coordinate.first;
        int& col = coordinate.second;

        mp[col][row].insert(node->val);

        if (node->left)
            q.push({node->left, {row + 1, col - 1}});
        if (node->right)
            q.push({node->right, {row + 1, col + 1}});
    }

    // Store final vertical order into ans vector
    for (auto it : mp) {
        auto& colMap = it.second;
        vector<int> vLine;

        for (auto colMapIt : colMap) {
            auto& mset = colMapIt.second;
            vLine.insert(vLine.end(), mset.begin(), mset.end());
        }
        ans.push_back(vLine);
    }

    return ans;
}

// ===============================
// MAIN (Example Test)
// ===============================
int main() {

    /*
            3
           / \
          9   20
             /  \
            15   7

    Expected Vertical Order:
    [
        [9],
        [3, 15],
        [20],
        [7]
    ]
    */

    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    vector<vector<int>> result = verticalTraversal(root);

    cout << "Vertical Traversal:\n";
    for (auto &col : result) {
        for (int x : col) cout << x << " ";
        cout << endl;
    }

    return 0;
}
