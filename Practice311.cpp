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
// Returns {height, maxSum}
// ===============================
pair<int, int> height(Node* root) {
    if (!root) return {0, 0};

    auto lh = height(root->left);
    auto rh = height(root->right);

    int sum = root->data;

    if (lh.first == rh.first) {
        sum += max(lh.second, rh.second);
    }
    else if (lh.first > rh.first) {
        sum += lh.second;
    }
    else {
        sum += rh.second;
    }

    return {max(lh.first, rh.first) + 1, sum};
}

// ===============================
// Main Function
// ===============================
int sumOfLongRootToLeafPath(Node* root) {
    auto h = height(root);
    return h.second;
}

// ===============================
// MAIN (Test Case)
// ===============================
int main() {

    /*
            4
           / \
          2   5
         / \   \
        7   1   2
           /
          6

    Longest root-to-leaf path:
    4 → 2 → 1 → 6
    Sum = 13
    */

    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(5);
    root->left->left = new Node(7);
    root->left->right = new Node(1);
    root->left->right->left = new Node(6);
    root->right->right = new Node(2);

    cout << "Sum of longest root-to-leaf path = "
         << sumOfLongRootToLeafPath(root) << endl;

    return 0;
}
