#include <iostream>
#include <queue>
using namespace std;

class Node {
public:
    int data;        // stores value of the node
    Node* left;      // pointer to left child
    Node* right;     // pointer to right child

    // ------------------------------------------------------------
    // CONSTRUCTOR:
    // Creates a new node with given data and initializes children.
    // ------------------------------------------------------------
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
//   Builds a Binary Tree using user input in PREORDER format.
//   PREORDER = Node → Left → Right
//
// INPUT FORMAT:
//   Enter integer values.
//   Enter -1 to indicate NULL (i.e., no child).
//
// HOW IT WORKS:
//   1) Ask user for value.
//   2) If -1, return NULL → meaning no node here.
//   3) Otherwise create a new node.
//   4) Recursively build left subtree.
//   5) Recursively build right subtree.
//
// RETURNS:
//   Pointer to the root of the constructed binary tree.
// ======================================================================
Node* buildTree() {
    int data;
    cout << "Enter the data: " << endl;
    cin >> data;

    // BASE CASE: -1 means no node
    if (data == -1) {
        return NULL;
    }

    // STEP A: Create node
    Node* root = new Node(data);

    // STEP B: Build left subtree
    cout << "Enter data for left part of " << data << " node " << endl;
    root->left = buildTree();

    // STEP C: Build right subtree
    cout << "Enter data for right part of " << data << " node " << endl;
    root->right = buildTree();

    return root;
}

// ======================================================================
// FUNCTION: levelOrderTraversal(Node* root)
// ----------------------------------------------------------------------
// PURPOSE:
//   Prints the tree level by level (BFS), each level on a new line.
//
// APPROACH:
//   • Use a queue for BFS traversal.
//   • Push the root node.
//   • Push `NULL` as a LEVEL MARKER to indicate end of a level.
//   • While queue is not empty:
//         A) If element is NULL → print newline (end of level)
//            and push another NULL if more nodes remain.
//         B) Otherwise print its value and push children.
//
// WHY NULL MARKER?
//   It helps separate levels clearly without needing to store level sizes.
//
// EXAMPLE FORMAT:
//   For tree: 
//       1
//      / \
//     2   3
//   Output:
//       1
//       2 3
// ======================================================================
void levelOrderTraversal(Node* root) {
    queue<Node*> q;

    // Initially add root and level marker
    q.push(root);
    q.push(NULL);   // Marks end of first level

    while (!q.empty()) {

        // STEP A: Access front node
        Node* temp = q.front();

        // STEP B: Remove it from queue
        q.pop();

        // If marker encountered → level completed
        if (temp == NULL) {
            cout << endl;   // End of current level

            // If queue still has nodes, push another marker
            if (!q.empty()) {
                q.push(NULL);
            }
        }
        else {
            // STEP C: Print node's value
            cout << temp->data << " ";

            // STEP D: Push left and right children if present
            if (temp->left) {
                q.push(temp->left);
            }

            if (temp->right) {
                q.push(temp->right);
            }
        }
    }
}

int main() {
    Node* root = NULL;

    // Build Binary Tree using user input
    root = buildTree();

    // Print tree level-by-level
    levelOrderTraversal(root);

    return 0;
}
