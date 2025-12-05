#include <iostream>
#include <queue>
using namespace std;

class Node {
public:
    int data;       // stores the value of the node
    Node* left;     // pointer to left child
    Node* right;    // pointer to right child

    // --------------------------------------------------------------
    // CONSTRUCTOR:
    // Initializes a node with given data and sets both children to NULL.
    // --------------------------------------------------------------
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
//   Builds a binary tree using PREORDER input (Root → Left → Right).
//
// INPUT FORMAT:
//   User enters integer values. Enter `-1` to indicate "no node" (NULL).
//
// LOGIC:
//   1. Read the current node's value.
//   2. If value = -1 → return NULL.
//   3. Create a node with this value.
//   4. Recursively build the left subtree.
//   5. Recursively build the right subtree.
//
// RETURN:
//   Pointer to the root of the constructed binary tree.
// ======================================================================
Node* buildTree() {
    int data;
    cout << "Enter the data: " << endl;
    cin >> data;

    // BASE CASE: -1 means no node should be created here
    if (data == -1) {
        return NULL;
    }

    // STEP A: Create a new node with given value
    Node* root = new Node(data);

    // STEP B: Build LEFT subtree recursively
    cout << "Enter data for left part of " << data << " node " << endl;
    root->left = buildTree();

    // STEP C: Build RIGHT subtree recursively
    cout << "Enter data for right part of " << data << " node " << endl;
    root->right = buildTree();

    return root;
}

// ======================================================================
// FUNCTION: levelOrderTraversal(Node* root)
// ----------------------------------------------------------------------
// PURPOSE:
//   Print the Binary Tree in **Level Order Traversal** (Breadth-First Search).
//
// APPROACH:
//   Use a queue to process nodes level by level:
//       1. Push root into queue.
//       2. While queue is not empty:
//            A) Get the front node
//            B) Remove it from queue
//            C) Print its data
//            D) Push its left child (if exists)
//            E) Push its right child (if exists)
//
// QUEUE CONTENTS:
//   Queue stores pointers to nodes that are waiting to be processed.
//
// EXAMPLE OUTPUT FORMAT:
//   For tree: 1 2 3 4 5 → prints: 1 2 3 4 5
// ======================================================================
void levelOrderTraversal(Node* root) {
    queue<Node*> q;   // Queue stores nodes in BFS order

    // Initially push the root node (starting point)
    q.push(root);

    while (!q.empty()) {

        // STEP A: Access the front node of queue
        Node* temp = q.front();

        // STEP B: Remove that node from the queue
        q.pop();

        // STEP C: Print the current node's data
        cout << temp->data << " ";

        // STEP D: Push left child if it exists
        if (temp->left) {
            q.push(temp->left);
        }

        // Push right child if it exists
        if (temp->right) {
            q.push(temp->right);
        }
    }
}

int main() {
    Node* root = NULL;

    // Build binary tree using recursive user input
    root = buildTree();

    // Perform BFS level-order traversal
    levelOrderTraversal(root);

    return 0;
}
