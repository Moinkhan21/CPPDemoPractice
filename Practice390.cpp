#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;

// ===============================
// Node Definition
// ===============================
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

// ===============================
// Helper Function
// Returns {include, exclude}
// ===============================
pair<int, int> getMaxSum_helper(Node* root) {
    if (!root) return {0, 0};

    auto left = getMaxSum_helper(root->left);
    auto right = getMaxSum_helper(root->right);

    // Sum INCLUDING current node
    int a = root->data + left.second + right.second;

    // Sum EXCLUDING current node
    int b = max(left.first, left.second) +
            max(right.first, right.second);

    return {a, b};
}

// ===============================
// Main Function
// ===============================
int getMaxSum(Node* root) {
    auto ans = getMaxSum_helper(root);
    return max(ans.first, ans.second);
}

// ===============================
// MAIN (Test Case)
// ===============================
int main() {

    /*
            10
           /  \
          1    2
         / \    \
        3   4    5

    Maximum Non-Adjacent Sum:
    10 + 3 + 4 + 5 = 22
    */

    Node* root = new Node(10);
    root->left = new Node(1);
    root->right = new Node(2);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->right->right = new Node(5);

    cout << "Maximum sum of non-adjacent nodes = "
         << getMaxSum(root) << endl;

    return 0;
}
