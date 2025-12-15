#include <iostream>
#include <unordered_map>
#include <queue>
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
// Step 1: Parent mapping + find target node
// ===============================
Node* makeNodetoParentMappingAndFindTargetNode(
    Node* root,
    unordered_map<Node*, Node*>& parentMap,
    int target
) {
    queue<Node*> q;
    Node* targetNode = NULL;

    q.push(root);
    parentMap[root] = NULL;

    while (!q.empty()) {
        Node* front = q.front();
        q.pop();

        if (front->data == target) {
            targetNode = front;
        }

        if (front->left) {
            q.push(front->left);
            parentMap[front->left] = front;
        }

        if (front->right) {
            q.push(front->right);
            parentMap[front->right] = front;
        }
    }
    return targetNode;
}

// ===============================
// Step 2: Burn the tree
// ===============================
int burnTheTree(
    Node* targetNode,
    unordered_map<Node*, Node*>& parentMap
) {
    unordered_map<Node*, bool> isBurnt;
    queue<Node*> q;

    int T = 0;
    q.push(targetNode);
    isBurnt[targetNode] = true;

    while (!q.empty()) {
        int size = q.size();
        bool isFireSpreaded = false;

        for (int i = 0; i < size; i++) {
            Node* front = q.front();
            q.pop();

            if (front->left && !isBurnt[front->left]) {
                q.push(front->left);
                isBurnt[front->left] = true;
                isFireSpreaded = true;
            }

            if (front->right && !isBurnt[front->right]) {
                q.push(front->right);
                isBurnt[front->right] = true;
                isFireSpreaded = true;
            }

            if (parentMap[front] && !isBurnt[parentMap[front]]) {
                q.push(parentMap[front]);
                isBurnt[parentMap[front]] = true;
                isFireSpreaded = true;
            }
        }

        if (isFireSpreaded)
            ++T;
    }
    return T;
}

// ===============================
// Main Function
// ===============================
int minTime(Node* root, int target) {
    unordered_map<Node*, Node*> parentMap;

    Node* targetNode =
        makeNodetoParentMappingAndFindTargetNode(root, parentMap, target);

    return burnTheTree(targetNode, parentMap);
}

// ===============================
// MAIN (Test Case)
// ===============================
int main() {

    /*
            1
           / \
          2   3
         / \
        4   5

    Target = 2
    Burning Time = 2
    */

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << "Minimum time to burn the tree = "
         << minTime(root, 2) << endl;

    return 0;
}
