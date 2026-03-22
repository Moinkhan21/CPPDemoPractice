#include <iostream>
#include <map>
#include <queue>
using namespace std;

// ======================================================================
// CLASS: Node
// ----------------------------------------------------------------------
// Represents a node in a Binary Tree.
//
// Each node contains:
//   • data  → integer value stored in the node
//   • left  → pointer to left child
//   • right → pointer to right child
//
// The constructor initializes the node value
// and sets both children to NULL.
// ======================================================================
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

// ======================================================================
// FUNCTION: buildTree()
// ----------------------------------------------------------------------
// PURPOSE:
//   Builds a binary tree using recursive PREORDER input.
//
// INPUT RULE:
//   • Enter value for node
//   • Enter -1 → represents NULL node
//
// PROCESS:
//   Node → Left → Right
//
// TIME COMPLEXITY: O(N)
// SPACE COMPLEXITY: O(H)
// ======================================================================
Node* buildTree() {

    int data;
    cout << "Enter the data: ";
    cin >> data;

    // Base case
    if (data == -1)
        return NULL;

    // Create node
    Node* root = new Node(data);

    // Build left subtree
    cout << "Enter data for left of " << data << endl;
    root->left = buildTree();

    // Build right subtree
    cout << "Enter data for right of " << data << endl;
    root->right = buildTree();

    return root;
}

// ======================================================================
// FUNCTION: levelOrderTraversal()
// ----------------------------------------------------------------------
// PURPOSE:
//   Prints the binary tree level by level (BFS traversal).
//
// APPROACH:
//   • Use queue for BFS
//   • Use NULL marker to separate levels
//
// PROCESS:
//   1. Push root and NULL
//   2. Traverse until queue is empty
//   3. When NULL encountered → new level
//
// TIME COMPLEXITY: O(N)
// SPACE COMPLEXITY: O(N)
// ======================================================================
void levelOrderTraversal(Node* root) {

    if (!root)
        return;

    queue<Node*> q;

    // Start with root
    q.push(root);
    q.push(NULL);   // Level separator

    while (!q.empty()) {

        Node* temp = q.front();
        q.pop();

        // --------------------------------------------------
        // End of current level
        // --------------------------------------------------
        if (temp == NULL) {
            cout << endl;

            // Add marker for next level
            if (!q.empty())
                q.push(NULL);
        }
        else {

            // Print current node
            cout << temp->data << " ";

            // Push left child
            if (temp->left)
                q.push(temp->left);

            // Push right child
            if (temp->right)
                q.push(temp->right);
        }
    }
}

// ======================================================================
// FUNCTION: printTopView()
// ----------------------------------------------------------------------
// PURPOSE:
//   Prints the TOP VIEW of a Binary Tree.
//
// WHAT IS TOP VIEW?
//   Nodes visible when tree is viewed from above.
//
// RULE:
//   For each horizontal distance (HD),
//   only the FIRST node is visible.
//
// HORIZONTAL DISTANCE:
//
//   Root → 0
//   Left → -1
//   Right → +1
//
// APPROACH:
//
//   • Use BFS traversal
//   • Maintain HD for each node
//   • Store first occurrence of each HD
//
// DATA STRUCTURES:
//
//   map<int,int> → stores HD → node value
//   queue<pair<Node*, int>> → BFS with HD
//
// TIME COMPLEXITY: O(N log N)
// SPACE COMPLEXITY: O(N)
// ======================================================================
void printTopView(Node* root) {

    if (root == NULL)
        return;

    // Map: HD → first node value
    map<int, int> topNode;

    // Queue: {node, horizontal distance}
    queue<pair<Node*, int>> q;

    // Start from root
    q.push({root, 0});

    while (!q.empty()) {

        auto temp = q.front();
        q.pop();

        Node* curr = temp.first;
        int hd = temp.second;

        // --------------------------------------------------
        // Store only first node at each HD
        // --------------------------------------------------
        if (topNode.find(hd) == topNode.end()) {
            topNode[hd] = curr->data;
        }

        // Process left child
        if (curr->left)
            q.push({curr->left, hd - 1});

        // Process right child
        if (curr->right)
            q.push({curr->right, hd + 1});
    }

    // --------------------------------------------------
    // Print result (sorted by HD)
    // --------------------------------------------------
    cout << "Top View:\n";

    for (auto &it : topNode) {
        cout << it.second << " ";
    }

    cout << endl;
}

// ======================================================================
// MAIN FUNCTION
// ----------------------------------------------------------------------
// Builds the binary tree, prints level order traversal,
// and prints top view.
//
// SAMPLE TREE:
//
//            1
//           / \
//          2   3
//           \   \
//            4   5
//
// LEVEL ORDER:
//
//   1
//   2 3
//   4 5
//
// TOP VIEW:
//
//   2 1 3 5
// ======================================================================
int main() {

    // Build tree
    Node* root = buildTree();

    // Print level order traversal
    cout << "\nLevel Order Traversal:\n";
    levelOrderTraversal(root);

    // Print top view
    cout << "\n";
    printTopView(root);

    return 0;
}