#include <iostream>
#include <map>
#include <queue>
using namespace std;

// ======================================================================
// CLASS: Node
// ----------------------------------------------------------------------
// Represents a single node in a Binary Tree.
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
// PURPOSE:
//   Builds a binary tree recursively using PREORDER input.
//
// INPUT RULE:
//   Enter any integer for a node.
//   Enter -1 when the node is NULL.
//
// PROCESS:
//   1. Read value.
//   2. If -1 → return NULL.
//   3. Create a node.
//   4. Recursively build left subtree.
//   5. Recursively build right subtree.
//
// RETURN:
//   Pointer to the root of the constructed binary tree.
// ======================================================================
Node* buildTree() {
    int data;
    cout << "Enter data: ";
    cin >> data;

    if (data == -1)
        return NULL;

    Node* root = new Node(data);

    cout << "Enter LEFT child of " << data << endl;
    root->left = buildTree();

    cout << "Enter RIGHT child of " << data << endl;
    root->right = buildTree();

    return root;
}

// ======================================================================
// FUNCTION: printBottomView()
// ----------------------------------------------------------------------
// PURPOSE:
//   Prints the BOTTOM VIEW of the binary tree.
//
// BOTTOM VIEW DEFINITION:
//   When the tree is viewed from below, the bottom-most visible node
//   at each horizontal distance (HD) is printed.
//
// HORIZONTAL DISTANCE:
//     • Root has HD = 0
//     • Left child  → HD - 1
//     • Right child → HD + 1
//
// APPROACH: BFS + map
//   • Use queue to perform level-order traversal.
//   • For each (node, HD):
//        - Insert/update map[HD] = node->data
//        - This works because lower nodes overwrite upper ones.
//   • At the end, map stores the lowest visible node at each HD.
//
// DATA STRUCTURES:
//   map<int,int> → stores {HD → node value}, sorted by HD.
//   queue<pair<Node*,int>> → BFS queue storing node + horizontal distance.
//
// TIME COMPLEXITY: O(n log n)
//   (due to map operations)
//
// OUTPUT:
//   Prints bottom view from leftmost HD to rightmost.
// ======================================================================
void printBottomView(Node* root) {
    if (root == NULL)
        return;

    // Map storing the LATEST (bottom-most) node at each HD
    map<int, int> topNode;

    // BFS queue → stores node + horizontal distance
    queue<pair<Node*, int>> q;
    q.push({root, 0});   // Root at HD = 0

    while (!q.empty()) {

        auto temp = q.front();
        q.pop();

        Node* frontNode = temp.first;
        int hd = temp.second;

        // Update value for current HD (bottom-most overwrites)
        topNode[hd] = frontNode->data;

        // Left subtree: HD - 1
        if (frontNode->left) {
            q.push({frontNode->left, hd - 1});
        }

        // Right subtree: HD + 1
        if (frontNode->right) {
            q.push({frontNode->right, hd + 1});
        }
    }

    // Print in sorted HD order
    cout << "\nBottom View of Tree:\n";
    for (auto &i : topNode) {
        cout << i.second << " ";
    }
    cout << endl;
}

// ======================================================================
// MAIN FUNCTION
// ----------------------------------------------------------------------
// Builds a binary tree using user input and prints its bottom view.
// ======================================================================
int main() {
    cout << "Build Binary Tree (-1 for NULL):\n";
    Node* root = buildTree();

    printBottomView(root);

    return 0;
}
