#include <iostream>
#include <map>
#include <vector>
#include <set>      // For multiset (handles duplicates and keeps sorted order)
#include <queue>
using namespace std;

// ======================================================================
// CLASS: TreeNode
// ----------------------------------------------------------------------
// Represents a node in a Binary Tree.
//
// Each node contains:
//   • val   → value stored in the node
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

    TreeNode(int val) {
        this->val = val;
        left = NULL;
        right = NULL;
    }
};

// ======================================================================
// FUNCTION: verticalTraversal()
// ----------------------------------------------------------------------
// PURPOSE:
//   Performs Vertical Order Traversal of a Binary Tree.
//
// WHAT IS VERTICAL TRAVERSAL?
//   Nodes are grouped based on their vertical column index.
//
// COORDINATE SYSTEM USED:
//   Root node        → (row = 0, col = 0)
//
//   For any node:
//     Left child     → (row + 1, col - 1)
//     Right child    → (row + 1, col + 1)
//
// DATA STRUCTURE USED:
//
//   map<col, map<row, multiset<values>>>
//
//   • Outer map → sorts columns from left to right
//   • Inner map → sorts nodes from top to bottom
//   • multiset  → sorts values if multiple nodes share same
//                 row and column
//
// ALGORITHM STEPS:
//   1. Use BFS traversal with a queue
//   2. Store each node with its (row, col) coordinate
//   3. Insert node value into the map structure
//   4. Finally collect results column by column
//
// TIME COMPLEXITY: O(N log N)
//   Due to ordered map and multiset insertions
//
// SPACE COMPLEXITY: O(N)
// ======================================================================
vector<vector<int>> verticalTraversal(TreeNode* root) {

    // Stores final vertical traversal result
    vector<vector<int>> ans;

    // If tree is empty, return empty result
    if (!root)
        return ans;

    // --------------------------------------------------
    // Queue for BFS traversal
    //
    // pair:
    //   • first  → TreeNode pointer
    //   • second → pair(row, col)
    // --------------------------------------------------
    queue<pair<TreeNode*, pair<int, int>>> q;

    // Start with root node
    q.push({root, {0, 0}});

    // --------------------------------------------------
    // Nested map structure
    //
    // col → row → multiset(values)
    //
    // Example structure:
    //   mp[-1][1] = {9}
    //   mp[0][0]  = {3}
    // --------------------------------------------------
    map<int, map<int, multiset<int>>> mp;

    // --------------------------------------------------
    // BFS traversal of the tree
    // --------------------------------------------------
    while (!q.empty()) {

        // Extract front element
        auto front = q.front();
        q.pop();

        TreeNode*& node = front.first;
        auto& coordinate = front.second;

        int& row = coordinate.first;
        int& col = coordinate.second;

        // Insert node value into the map
        mp[col][row].insert(node->val);

        // --------------------------------------------------
        // Push left child
        // --------------------------------------------------
        if (node->left)
            q.push({node->left, {row + 1, col - 1}});

        // --------------------------------------------------
        // Push right child
        // --------------------------------------------------
        if (node->right)
            q.push({node->right, {row + 1, col + 1}});
    }

    // --------------------------------------------------
    // Construct final result from map
    // --------------------------------------------------
    for (auto it : mp) {

        auto& colMap = it.second;

        // Stores nodes belonging to one vertical line
        vector<int> vLine;

        for (auto colMapIt : colMap) {

            auto& mset = colMapIt.second;

            // Insert all values in sorted order
            vLine.insert(vLine.end(), mset.begin(), mset.end());
        }

        // Add vertical line to result
        ans.push_back(vLine);
    }

    return ans;
}

// ======================================================================
// MAIN FUNCTION (Example Test)
// ======================================================================
int main() {

    /*
            3
           / \
          9   20
             /  \
            15   7

    Coordinates Representation:

            (0,0)
              3
           /      \
      (-1,1)     (1,1)
        9           20
                  /     \
             (0,2)     (2,2)
               15        7

    Vertical Order Traversal:

    Column -1 → [9]
    Column  0 → [3, 15]
    Column  1 → [20]
    Column  2 → [7]

    Result:
    [
        [9],
        [3, 15],
        [20],
        [7]
    ]
    */

    // Constructing the binary tree
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    // Perform vertical traversal
    vector<vector<int>> result = verticalTraversal(root);

    // Print result
    cout << "Vertical Traversal:\n";

    for (auto &col : result) {
        for (int x : col)
            cout << x << " ";
        cout << endl;
    }

    return 0;
}