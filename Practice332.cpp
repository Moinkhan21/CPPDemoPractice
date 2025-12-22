#include <iostream>
using namespace std;

// ===============================
// Node Definition
// ===============================
struct Node {
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
// Count Nodes using Morris Traversal
// ===============================
int findNodeCount(Node* root) {
    int count = 0;
    Node* curr = root;

    while (curr) {

        if (curr->left == nullptr) {
            count++;
            curr = curr->right;
        }
        else {
            Node* pred = curr->left;
            while (pred->right != curr && pred->right) {
                pred = pred->right;
            }

            if (pred->right == nullptr) {
                pred->right = curr;
                curr = curr->left;
            }
            else {
                pred->right = nullptr;
                count++;
                curr = curr->right;
            }
        }
    }
    return count;
}

// ===============================
// Find Actual Median Value
// ===============================
float findActualMedian(Node* root, int n) {

    int i = 0;
    int odd1 = (n + 1) / 2, oddVal = -1;
    int even1 = n / 2, even1Val = -1;
    int even2 = n / 2 + 1, even2Val = -1;

    Node* curr = root;

    while (curr) {

        if (curr->left == nullptr) {
            i++;

            if (i == odd1) oddVal = curr->data;
            if (i == even1) even1Val = curr->data;
            if (i == even2) even2Val = curr->data;

            curr = curr->right;
        }
        else {
            Node* pred = curr->left;
            while (pred->right != curr && pred->right) {
                pred = pred->right;
            }

            if (pred->right == nullptr) {
                pred->right = curr;
                curr = curr->left;
            }
            else {
                pred->right = nullptr;
                i++;

                if (i == odd1) oddVal = curr->data;
                if (i == even1) even1Val = curr->data;
                if (i == even2) even2Val = curr->data;

                curr = curr->right;
            }
        }
    }

    if ((n & 1) == 0) {
        return (even1Val + even2Val) / 2.0;
    }
    else {
        return oddVal;
    }
}

// ===============================
// Wrapper Function
// ===============================
float findMedian(Node* root) {
    int n = findNodeCount(root);
    return findActualMedian(root, n);
}

// ===============================
// MAIN (Test Case)
// ===============================
int main() {

    /*
            6
           / \
          3   8
         / \   \
        1   4   9

    Inorder: 1 3 4 6 8 9
    Median = (4 + 6) / 2 = 5
    */

    Node* root = new Node(6);
    root->left = new Node(3);
    root->right = new Node(8);
    root->left->left = new Node(1);
    root->left->right = new Node(4);
    root->right->right = new Node(9);

    cout << "Median of BST = " << findMedian(root) << endl;

    return 0;
}
