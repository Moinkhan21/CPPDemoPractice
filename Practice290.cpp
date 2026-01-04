#include <iostream>
#include <vector>
using namespace std;

// ======================================================================
// CLASS: Node
// ----------------------------------------------------------------------
// Represents a node in a Binary Tree.
//
// Each node contains:
//   • data  → value of the node
//   • left  → pointer to left child
//   • right → pointer to right child
// ======================================================================
class Node {
public:
    int data;
    Node* left;
    Node* right;

    // Constructor initializes node with given value
    Node(int data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

// ======================================================================
// FUNCTION: buildTree()
// ----------------------------------------------------------------------
// PURPOSE:
//   Builds a binary tree using PREORDER input.
//
// INPUT RULE:
//   • Enter -1 to indicate NULL node
//
// ORDER:
//   Node → Left → Right
//
// TIME COMPLEXITY: O(n)
// SPACE COMPLEXITY: O(h)
// ======================================================================
Node* buildTree() {

    int data;
    cin >> data;

    // Base case: NULL node
    if (data == -1)
        return NULL;

    // Create current node
    Node* root = new Node(data);

    // Recursively build left and right subtrees
    root->left = buildTree();
    root->right = buildTree();

    return root;
}

// ======================================================================
// FUNCTION: solve()
// ----------------------------------------------------------------------
// PURPOSE:
//   Performs DFS to find ALL root-to-leaf paths
//   whose sum equals targetSum.
//
// PARAMETERS:
//   • root       → current node
//   • targetSum → required sum
//   • currSum   → sum of current path (passed by reference)
//   • path      → stores current root-to-node path
//   • ans       → stores all valid paths
//
// CORE IDEA:
//   • Include current node in path
//   • If leaf node → check sum
//   • Backtrack after exploring both subtrees
//
// TECHNIQUE USED:
//   ✔ DFS
//   ✔ Backtracking
//
// TIME COMPLEXITY: O(n)
// SPACE COMPLEXITY: O(h)
// ======================================================================
void solve(Node* root, int targetSum, int &currSum,
           vector<int> &path, vector<vector<int>> &ans) {

    // Base case
    if (root == NULL)
        return;

    // Include current node in path
    currSum += root->data;
    path.push_back(root->data);

    // If leaf node, check sum
    if (root->left == NULL && root->right == NULL) {

        if (currSum == targetSum)
            ans.push_back(path);

        // Backtrack
        currSum -= root->data;
        path.pop_back();
        return;
    }

    // Explore left and right subtrees
    solve(root->left, targetSum, currSum, path, ans);
    solve(root->right, targetSum, currSum, path, ans);

    // Backtrack after recursion
    currSum -= root->data;
    path.pop_back();
}

// ======================================================================
// FUNCTION: pathSum()
// ----------------------------------------------------------------------
// PURPOSE:
//   Returns all root-to-leaf paths
//   whose sum equals targetSum.
//
// APPROACH:
//   • Initializes helper variables
//   • Calls DFS helper function
//
// TIME COMPLEXITY: O(n)
// SPACE COMPLEXITY: O(h)
// ======================================================================
vector<vector<int>> pathSum(Node* root, int targetSum) {

    vector<vector<int>> ans;   // Stores all valid paths
    vector<int> path;          // Current path
    int currSum = 0;

    solve(root, targetSum, currSum, path, ans);
    return ans;
}

// ======================================================================
// MAIN FUNCTION
// ======================================================================
int main() {

    cout << "Enter tree nodes in preorder (-1 for NULL):" << endl;
    Node* root = buildTree();

    int targetSum;
    cout << "Enter target sum: ";
    cin >> targetSum;

    vector<vector<int>> result = pathSum(root, targetSum);

    cout << "\nPaths with sum " << targetSum << ":" << endl;
    for (auto &path : result) {
        for (int x : path) {
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}
