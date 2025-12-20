#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// ======================================================================
// CLASS: TreeNode
// ----------------------------------------------------------------------
// Represents a node in a Binary Tree.
// Each node contains:
//   • val   → integer value stored in the node
//   • left  → pointer to left child
//   • right → pointer to right child
// ======================================================================
class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    // Constructor initializes node with value
    // and sets left & right children to NULL
    TreeNode(int val) {
        this->val = val;
        left = NULL;
        right = NULL;
    }
};

// ======================================================================
// FUNCTION: zigzagLevelOrder()
// ----------------------------------------------------------------------
// PURPOSE:
//   Performs ZIGZAG (SPIRAL) LEVEL ORDER TRAVERSAL of a binary tree.
//
// ZIGZAG TRAVERSAL RULE:
//   • Level 0 → Left to Right
//   • Level 1 → Right to Left
//   • Level 2 → Left to Right
//   • … and so on
//
// APPROACH: BFS (Level Order) + Direction Toggle
//
// CORE IDEA:
//   • Use a queue to process nodes level by level
//   • Use a boolean flag (LtoRdir) to track direction
//   • Store each level’s values in a temporary vector
//   • Insert values at correct index based on direction
//
// TIME COMPLEXITY: O(n)
//   Each node is visited once.
//
// SPACE COMPLEXITY: O(n)
//   Queue + result storage
// ======================================================================
vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    
    vector<vector<int>> ans;

    // Edge case: empty tree
    if (!root) return ans;

    queue<TreeNode*> q;
    q.push(root);    // Start BFS from root

    bool LtoRdir = true;  // Direction flag (Left to Right initially)

    while (!q.empty()) {

        int width = q.size();          // Number of nodes at current level
        vector<int> oneLevel(width);   // Stores current level values

        // Process all nodes at the current level
        for (int i = 0; i < width; i++) {

            TreeNode* front = q.front();
            q.pop();

            // Determine correct index based on direction
            int index = LtoRdir ? i : width - i - 1;
            oneLevel[index] = front->val;

            // Push children for next level
            if (front->left)
                q.push(front->left);

            if (front->right)
                q.push(front->right);
        }

        // Store current level result
        ans.push_back(oneLevel);

        // Toggle direction for next level
        LtoRdir = !LtoRdir;
    }

    return ans;
}

// ======================================================================
// MAIN FUNCTION
// ----------------------------------------------------------------------
// Builds a sample binary tree and prints its zigzag level order traversal.
//
// TREE STRUCTURE:
//
//            1
//           / \
//          2   3
//         / \   \
//        4   5   6
//
// ZIGZAG OUTPUT:
//   [ [1], [3, 2], [4, 5, 6] ]
// ======================================================================
int main() {

    // Construct the binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);

    // Perform zigzag level order traversal
    vector<vector<int>> result = zigzagLevelOrder(root);

    // Print the traversal result
    cout << "Zigzag Level Order:\n";
    for (auto &level : result) {
        for (int x : level)
            cout << x << " ";
        cout << "\n";
    }

    return 0;
}
