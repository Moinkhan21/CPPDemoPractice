#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// ======================================================================
// CLASS: TreeNode
// ----------------------------------------------------------------------
// Represents a node in a Binary Tree.
//
// Each node contains:
//   • val   → integer value stored in the node
//   • left  → pointer to left child
//   • right → pointer to right child
//
// The constructor initializes the node value
// and sets both children to NULL.
// ======================================================================
class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    // Constructor
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
//   Performs ZIGZAG (Spiral) Level Order Traversal of a Binary Tree.
//
// WHAT IS ZIGZAG TRAVERSAL?
//   Instead of traversing every level from left → right,
//   the direction alternates for each level.
//
//   Example:
//
//   Level 0 → Left to Right
//   Level 1 → Right to Left
//   Level 2 → Left to Right
//   Level 3 → Right to Left
//
// APPROACH USED:
//   Breadth First Search (BFS) with direction toggling.
//
// CORE IDEA:
//
//   1️⃣ Use a queue to perform level order traversal.
//
//   2️⃣ For each level:
//       • determine number of nodes (width)
//
//   3️⃣ Use a vector to store nodes of current level.
//
//   4️⃣ Insert values depending on direction:
//
//       If Left → Right
//           index = i
//
//       If Right → Left
//           index = width - i - 1
//
//   5️⃣ Toggle direction after each level.
//
// DATA STRUCTURES USED:
//
//   • queue<TreeNode*> → BFS traversal
//   • vector<vector<int>> → final result
//
// TIME COMPLEXITY: O(N)
//   Each node is visited exactly once.
//
// SPACE COMPLEXITY: O(N)
//   Queue + result vector.
// ======================================================================
vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

    // Final result storing all levels
    vector<vector<int>> ans;

    // Edge Case: Empty Tree
    if (!root)
        return ans;

    // Queue used for BFS traversal
    queue<TreeNode*> q;

    // Start traversal from root
    q.push(root);

    // Direction flag
    // true  → Left to Right
    // false → Right to Left
    bool LtoRdir = true;

    // Continue until queue becomes empty
    while (!q.empty()) {

        // Number of nodes at current level
        int width = q.size();

        // Temporary vector to store current level values
        vector<int> oneLevel(width);

        // Process each node of the level
        for (int i = 0; i < width; i++) {

            // Extract front node
            TreeNode* front = q.front();
            q.pop();

            // --------------------------------------------------
            // Determine correct index based on direction
            // --------------------------------------------------
            int index;

            if (LtoRdir)
                index = i;                 // Left → Right
            else
                index = width - i - 1;     // Right → Left

            oneLevel[index] = front->val;

            // --------------------------------------------------
            // Push children for next level
            // --------------------------------------------------
            if (front->left)
                q.push(front->left);

            if (front->right)
                q.push(front->right);
        }

        // Store current level into result
        ans.push_back(oneLevel);

        // Toggle direction for next level
        LtoRdir = !LtoRdir;
    }

    return ans;
}

// ======================================================================
// MAIN FUNCTION (Test Case)
// ----------------------------------------------------------------------
// Builds a sample binary tree and prints its Zigzag Level Order.
//
// TREE STRUCTURE:
//
//            1
//           / \
//          2   3
//         / \   \
//        4   5   6
//
// LEVEL ORDER:
//
// Level 0 → 1
// Level 1 → 2 3
// Level 2 → 4 5 6
//
// ZIGZAG OUTPUT:
//
// [
//   [1],
//   [3, 2],
//   [4, 5, 6]
// ]
// ======================================================================
int main() {

    // Constructing the binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);

    // Perform Zigzag Traversal
    vector<vector<int>> result = zigzagLevelOrder(root);

    // Print the result
    cout << "Zigzag Level Order Traversal:\n";

    for (auto &level : result) {
        for (int x : level)
            cout << x << " ";
        cout << "\n";
    }

    return 0;
}