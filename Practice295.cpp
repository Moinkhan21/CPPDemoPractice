#include <iostream>
#include <map>
#include <queue>
using namespace std;

// ======================================================================
// CLASS: Node
// ----------------------------------------------------------------------
// Represents a single node of a binary tree.
// Each node contains:
//     • data  → integer value
//     • left  → pointer to left subtree
//     • right → pointer to right subtree
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
// PURPOSE: Builds a binary tree recursively using PREORDER input.
// INPUT RULE: Enter -1 when there is no child (NULL).
//
// PROCESS:
//     1. Read data
//     2. If data = -1, return NULL (no node)
//     3. Create current node
//     4. Recursively build left subtree
//     5. Recursively build right subtree
// ======================================================================
Node* buildTree() {
    int data;
    cout << "Enter data: ";
    cin >> data;

    // Base case
    if (data == -1)
        return NULL;

    // Create node
    Node* root = new Node(data);

    // Build left child
    cout << "Enter LEFT child of " << data << endl;
    root->left = buildTree();

    // Build right child
    cout << "Enter RIGHT child of " << data << endl;
    root->right = buildTree();

    return root;
}

// ======================================================================
// FUNCTION: printTopView()
// ----------------------------------------------------------------------
// PURPOSE:
//     Prints the TOP VIEW of a binary tree.
//
// TOP VIEW DEFINITION:
//     When viewing the tree from above, only the first node encountered
//     at each horizontal distance (HD) is visible.
//
// TECHNIQUE: BFS + Horizontal Distance
//
// HORIZONTAL DISTANCE (HD) RULES:
//     • Root has HD = 0
//     • Left child  → HD - 1
//     • Right child → HD + 1
//
// DATA STRUCTURES USED:
//     map<int, int> topNode;
//         - Stores {HD → Node Value}
//         - map is sorted by key → ensures printing from left to right
//
//     queue<pair<Node*, int>> q;
//         - For BFS traversal, storing node along with its HD
//
// ALGORITHM:
//     1. Start BFS from root at HD = 0
//     2. For every node, if its HD is NOT already in map,
//        store it (first node at that HD → visible from top)
//     3. Push its left child with HD - 1
//     4. Push its right child with HD + 1
//     5. Finally print map values in sorted HD order
// ======================================================================
void printTopView(Node* root) {
    if (root == NULL)
        return;

    // Stores first node for each horizontal distance
    map<int, int> topNode;

    // Queue for BFS → stores {node, HD}
    queue<pair<Node*, int>> q;
    q.push({root, 0});

    while (!q.empty()) {

        auto temp = q.front();
        q.pop();

        Node* frontNode = temp.first;
        int hd = temp.second;   // horizontal distance

        // Only store value if HD is encountered first time
        if (topNode.find(hd) == topNode.end()) {
            topNode[hd] = frontNode->data;
        }

        // Left child: HD - 1
        if (frontNode->left) {
            q.push({frontNode->left, hd - 1});
        }

        // Right child: HD + 1
        if (frontNode->right) {
            q.push({frontNode->right, hd + 1});
        }
    }

    // Print top-view by iterating map in sorted HD order
    cout << "\nTop View of Tree:\n";
    for (auto &i : topNode) {
        cout << i.second << " ";
    }
    cout << endl;
}

// ======================================================================
// MAIN FUNCTION
// ----------------------------------------------------------------------
// Builds the tree and prints its top view.
// ======================================================================
int main() {
    cout << "Build Binary Tree (-1 for NULL):\n";
    Node* root = buildTree();

    printTopView(root);

    return 0;
}
