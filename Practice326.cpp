#include <iostream>
#include <queue>
#include <climits>
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
// Level Order Traversal
// ===============================
void levelOrderTraversal(Node* root) {
    if (!root) return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        cout << temp->data << " ";

        if (temp->left) q.push(temp->left);
        if (temp->right) q.push(temp->right);
    }
    cout << endl;
}

// ===============================
// NodeData Class
// ===============================
class NodeData {
public:
    int size;
    int minVal;
    int maxVal;
    bool validBST;

    NodeData() {}

    NodeData(int size, int maxVal, int minVal, bool valid) {
        this->size = size;
        this->minVal = minVal;
        this->maxVal = maxVal;
        this->validBST = valid;
    }
};

// ===============================
// Find Largest BST
// ===============================
NodeData findLargestBST(Node* root, int &ans) {

    // Base case
    if (root == NULL) {
        return NodeData(0, INT_MIN, INT_MAX, true);
    }

    NodeData leftKaAns = findLargestBST(root->left, ans);
    NodeData rightKaAns = findLargestBST(root->right, ans);

    NodeData currNodeKaAns;

    currNodeKaAns.size = leftKaAns.size + rightKaAns.size + 1;
    currNodeKaAns.maxVal = max(root->data, rightKaAns.maxVal);
    currNodeKaAns.minVal = min(root->data, leftKaAns.minVal);

    if (leftKaAns.validBST &&
        rightKaAns.validBST &&
        (root->data > leftKaAns.maxVal &&
         root->data < rightKaAns.minVal)) {

        currNodeKaAns.validBST = true;
    }
    else {
        currNodeKaAns.validBST = false;
    }

    if (currNodeKaAns.validBST) {
        ans = max(ans, currNodeKaAns.size);
    }

    return currNodeKaAns;
}

// ===============================
// MAIN
// ===============================
int main() {

    /*
            5
           /
          2
         / \
        1   3
             \
              4

    Largest BST size = 3 (subtree rooted at 2)
    */

    Node* root = new Node(5);
    Node* first = new Node(2);
    Node* second = new Node(4);
    Node* third = new Node(1);
    Node* fourth = new Node(3);

    root->left = first;
    first->left = third;
    first->right = fourth;
    fourth->right = second;

    cout << "Printing the tree:" << endl;
    levelOrderTraversal(root);

    int ans = 0;
    findLargestBST(root, ans);

    cout << "Largest BST ka size : " << ans << endl;

    return 0;
}
