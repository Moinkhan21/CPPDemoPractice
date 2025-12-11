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
// Zigzag Level Order Function
// ===============================
vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    
    vector<vector<int>> ans;
    if (!root) return ans;

    queue<TreeNode*> q;
    q.push(root);

    bool LtoRdir = true;

    while (!q.empty()) {

        int width = q.size();
        vector<int> oneLevel(width);

        // Process one level
        for (int i = 0; i < width; i++) {

            TreeNode* front = q.front();
            q.pop();

            // Position index depending on direction
            int index = LtoRdir ? i : width - i - 1;
            oneLevel[index] = front->val;

            if (front->left)  q.push(front->left);
            if (front->right) q.push(front->right);
        }

        ans.push_back(oneLevel);

        // Toggle direction
        LtoRdir = !LtoRdir;
    }

    return ans;
}

// ===============================
// MAIN FUNCTION (Test) 
// ===============================
int main() {

    /*
            1
           / \
          2   3
         / \   \
        4   5   6

    Zigzag Output:
    [
        [1],
        [3,2],
        [4,5,6]
    ]
    */

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);

    vector<vector<int>> result = zigzagLevelOrder(root);

    cout << "Zigzag Level Order:\n";
    for (auto &level : result) {
        for (int x : level) cout << x << " ";
        cout << "\n";
    }

    return 0;
}
