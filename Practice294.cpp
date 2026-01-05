#include <iostream>
#include <map>
#include <queue>
using namespace std;

// ======================================================================
// CLASS: Node
// ----------------------------------------------------------------------
// Represents a node of a Binary Tree.
//
// Each node contains:
//   • data  → value stored in the node
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
        this->left = NULL;
        this->right = NULL;
    }
};

// ======================================================================
// FUNCTION: buildTree()
// ----------------------------------------------------------------------
// PURPOSE:
//   Builds a binary tree using recursive input.
//
// INPUT RULE:
//   • Enter -1 to represent NULL node
//
// APPROACH:
//   • Take input for current node
//   • Recursively build left subtree
//   • Recursively build right subtree
//
// TIME COMPLEXITY: O(n)
// SPACE COMPLEXITY: O(h)  (recursion stack)
// ======================================================================
Node* buildTree() {

    int data;
    cout << "Enter the data: " << endl;
    cin >> data;

    // Base case: NULL node
    if (data == -1) {
        return NULL;
    }

    // Create current node
    Node* root = new Node(data);

    // Build left subtree
    cout << "Enter data for left part of " << data << " node " << endl;
    root->left = buildTree();

    // Build right subtree
    cout << "Enter data for right part of " << data << " node " << endl;
    root->right = buildTree();

    return root;
}

// ======================================================================
// FUNCTION: levelOrderTraversal()
// ----------------------------------------------------------------------
// PURPOSE:
//   Prints the tree level by level (Breadth First Search).
//
// APPROACH:
//   • Use a queue
//   • NULL marker is used to separate levels
//
// TIME COMPLEXITY: O(n)
// SPACE COMPLEXITY: O(n)
// ======================================================================
void levelOrderTraversal(Node* root) {

    if (!root) return;

    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty()) {

        Node* temp = q.front();
        q.pop();

        // End of one level
        if (temp == NULL) {
            cout << endl;
            if (!q.empty())
                q.push(NULL);
        }
        else {
            cout << temp->data << " ";

            if (temp->left)
                q.push(temp->left);

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
//   • Nodes visible when tree is viewed from the top
//   • For each horizontal distance (HD), only the
//     FIRST node encountered is considered
//
// APPROACH:
//   • Perform level order traversal (BFS)
//   • Track horizontal distance (HD)
//       - root → HD = 0
//       - left → HD - 1
//       - right → HD + 1
//   • Use map to store first node for each HD
//
// DATA STRUCTURES USED:
//   • map<int, int> → stores HD → node data
//   • queue<pair<Node*, int>> → BFS with HD
//
// TIME COMPLEXITY: O(n log n)
// SPACE COMPLEXITY: O(n)
// ======================================================================
void printTopView(Node* root) {

    if (root == NULL)
        return;

    // Map to store first node at each horizontal distance
    // HD → node data
    map<int, int> topNode;

    // Queue stores {node, horizontal distance}
    queue<pair<Node*, int>> q;
    q.push(make_pair(root, 0));

    while (!q.empty()) {

        pair<Node*, int> temp = q.front();
        q.pop();

        Node* frontNode = temp.first;
        int hd = temp.second;

        // Store node only if this HD is seen for the first time
        if (topNode.find(hd) == topNode.end()) {
            topNode[hd] = frontNode->data;
        }

        // Move left
        if (frontNode->left) {
            q.push(make_pair(frontNode->left, hd - 1));
        }

        // Move right
        if (frontNode->right) {
            q.push(make_pair(frontNode->right, hd + 1));
        }
    }

    // Print top view from leftmost HD to rightmost HD
    cout << "Printing the Top View: " << endl;
    for (auto i : topNode) {
        cout << i.second << " ";
    }
    cout << endl;
}

// ======================================================================
// MAIN FUNCTION
// ======================================================================
int main() {

    Node* root = buildTree();

    cout << "\nLevel Order Traversal:\n";
    levelOrderTraversal(root);

    cout << "\nTop View:\n";
    printTopView(root);

    return 0;
}
