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
//   Builds a binary tree using PREORDER input.
//
// INPUT RULE:
//   • Enter value for node
//   • Enter -1 → represents NULL node
//
// PROCESS:
//   Node → Left → Right
//
// RETURNS:
//   Pointer to root of constructed tree
//
// TIME COMPLEXITY: O(N)
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

    // Build left subtree
    cout << "Enter LEFT child of " << data << endl;
    root->left = buildTree();

    // Build right subtree
    cout << "Enter RIGHT child of " << data << endl;
    root->right = buildTree();

    return root;
}

// ======================================================================
// FUNCTION: printBottomView()
// ----------------------------------------------------------------------
// PURPOSE:
//   Prints the BOTTOM VIEW of a Binary Tree.
//
// WHAT IS BOTTOM VIEW?
//
//   Nodes visible when the tree is viewed from the BOTTOM.
//
// RULE:
//
//   For each horizontal distance (HD),
//   only the LOWEST (last encountered) node is visible.
//
// HORIZONTAL DISTANCE:
//
//   Root → HD = 0
//   Left child → HD - 1
//   Right child → HD + 1
//
// APPROACH USED:
//
//   BFS (Level Order Traversal) + Map
//
// CORE IDEA:
//
//   • Traverse tree level by level
//   • For each node:
//         store/update map[HD] = node value
//   • Since BFS goes top → bottom,
//     lower nodes overwrite upper nodes
//
// DATA STRUCTURES:
//
//   map<int,int>
//       → stores {HD → node value}
//       → automatically sorted by HD
//
//   queue<pair<Node*, int>>
//       → stores node + horizontal distance
//
// TIME COMPLEXITY: O(N log N)
//   (map insertion)
//
// SPACE COMPLEXITY: O(N)
// ======================================================================
void printBottomView(Node* root) {

    // Edge case
    if (root == NULL)
        return;

    // Map: HD → node value (bottom-most)
    map<int, int> nodeMap;

    // Queue for BFS: {node, horizontal distance}
    queue<pair<Node*, int>> q;

    // Start with root at HD = 0
    q.push({root, 0});

    while (!q.empty()) {

        auto temp = q.front();
        q.pop();

        Node* curr = temp.first;
        int hd = temp.second;

        // --------------------------------------------------
        // Update map (overwrite ensures bottom-most node)
        // --------------------------------------------------
        nodeMap[hd] = curr->data;

        // --------------------------------------------------
        // Process left child (HD - 1)
        // --------------------------------------------------
        if (curr->left)
            q.push({curr->left, hd - 1});

        // --------------------------------------------------
        // Process right child (HD + 1)
        // --------------------------------------------------
        if (curr->right)
            q.push({curr->right, hd + 1});
    }

    // --------------------------------------------------
    // Print result (sorted by horizontal distance)
    // --------------------------------------------------
    cout << "\nBottom View of Tree:\n";

    for (auto &it : nodeMap) {
        cout << it.second << " ";
    }

    cout << endl;
}

// ======================================================================
// MAIN FUNCTION
// ----------------------------------------------------------------------
// Builds a binary tree and prints its bottom view.
//
// SAMPLE TREE:
//
//            1
//           / \
//          2   3
//           \   \
//            4   5
//
// BOTTOM VIEW:
//
//   2 4 3 5
// ======================================================================
int main() {

    cout << "Build Binary Tree (-1 for NULL):\n";

    // Construct tree
    Node* root = buildTree();

    // Print bottom view
    printBottomView(root);

    return 0;
}