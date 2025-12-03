#include <iostream>
#include <vector>
using namespace std;

// =============================
// Node structure
// =============================
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

// =============================
// Build Tree (input -1 for NULL)
// =============================
Node* buildTree() {
    int data;
    cin >> data;

    if (data == -1)
        return NULL;

    Node* root = new Node(data);
    root->left = buildTree();
    root->right = buildTree();

    return root;
}

// =============================
// Helper function (DFS)
// =============================
void solve(Node* root, int targetSum, int &currSum,
           vector<int> &path, vector<vector<int>> &ans) {

    if (root == NULL)
        return;

    // Include current node
    currSum += root->data;
    path.push_back(root->data);

    // Leaf node
    if (root->left == NULL && root->right == NULL) {
        if (currSum == targetSum)
            ans.push_back(path);

        // Backtrack
        currSum -= root->data;
        path.pop_back();
        return;
    }

    // Recursive DFS
    solve(root->left, targetSum, currSum, path, ans);
    solve(root->right, targetSum, currSum, path, ans);

    // Backtrack
    currSum -= root->data;
    path.pop_back();
}

// =============================
// Main function to return all paths
// =============================
vector<vector<int>> pathSum(Node* root, int targetSum) {
    vector<vector<int>> ans;
    vector<int> path;
    int currSum = 0;

    solve(root, targetSum, currSum, path, ans);
    return ans;
}

// =============================
// Driver Code
// =============================
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
