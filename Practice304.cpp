#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// ======================================================================
// CLASS: Node
// ----------------------------------------------------------------------
// Represents a node of a Binary Tree.
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
        left = NULL;
        right = NULL;
    }
};

// ======================================================================
// FUNCTION: diagonal()
// ----------------------------------------------------------------------
// PURPOSE:
//   Performs DIAGONAL TRAVERSAL of a Binary Tree.
//
// WHAT IS DIAGONAL TRAVERSAL?
//   Nodes that lie on the same diagonal are grouped together.
//
// DIAGONAL RULE:
//
//   For any node:
//       RIGHT child → stays on the SAME diagonal
//       LEFT child  → moves to the NEXT diagonal
//
// VISUAL EXAMPLE:
//
//            8
//           / \
//          3   10
//         / \    \
//        1   6    14
//           / \   /
//          4   7 13
//
// Diagonal groups:
//
// Diagonal 0 → 8 10 14
// Diagonal 1 → 3 6 7 13
// Diagonal 2 → 1 4
//
// Final Traversal:
//   8 10 14 3 6 7 13 1 4
//
// APPROACH USED:
//   Queue + Right Traversal
//
// CORE IDEA:
//
//   1️⃣ Push root node into queue.
//
//   2️⃣ While queue is not empty:
//
//       a) Pop a node → start of a diagonal
//
//       b) Traverse its RIGHT chain:
//             • Add node value to result
//             • Push LEFT child into queue
//               (because it belongs to next diagonal)
//             • Move to RIGHT child
//
// WHY QUEUE?
//
//   Queue stores the LEFT children that belong
//   to future diagonals.
//
// TIME COMPLEXITY: O(N)
//   Each node is visited exactly once.
//
// SPACE COMPLEXITY: O(N)
//   Queue + result vector.
// ======================================================================
vector<int> diagonal(Node* root) {

    // Stores final traversal result
    vector<int> ans;

    // Edge case: empty tree
    if (!root)
        return ans;

    // Queue for processing diagonals
    queue<Node*> q;

    // Start traversal from root
    q.push(root);

    // Continue until queue becomes empty
    while (!q.empty()) {

        // Get starting node of current diagonal
        Node* temp = q.front();
        q.pop();

        // --------------------------------------------------
        // Traverse all nodes in the same diagonal
        // --------------------------------------------------
        while (temp) {

            // Add current node value to result
            ans.push_back(temp->data);

            // --------------------------------------------------
            // LEFT child belongs to next diagonal
            // --------------------------------------------------
            if (temp->left)
                q.push(temp->left);

            // --------------------------------------------------
            // Move to RIGHT child (same diagonal)
            // --------------------------------------------------
            temp = temp->right;
        }
    }

    return ans;
}

// ======================================================================
// MAIN FUNCTION (Test Case)
// ----------------------------------------------------------------------
// Builds a sample binary tree and prints its diagonal traversal.
//
// TREE STRUCTURE:
//
//            8
//           / \
//          3   10
//         / \    \
//        1   6    14
//           / \   /
//          4   7 13
//
// DIAGONAL GROUPS:
//
// Diagonal 0 → 8 10 14
// Diagonal 1 → 3 6 7 13
// Diagonal 2 → 1 4
//
// FINAL OUTPUT:
//   8 10 14 3 6 7 13 1 4
// ======================================================================
int main() {

    // Constructing the binary tree
    Node* root = new Node(8);
    root->left = new Node(3);
    root->right = new Node(10);
    root->left->left = new Node(1);
    root->left->right = new Node(6);
    root->left->right->left = new Node(4);
    root->left->right->right = new Node(7);
    root->right->right = new Node(14);
    root->right->right->left = new Node(13);

    // Perform diagonal traversal
    vector<int> result = diagonal(root);

    // Print result
    cout << "Diagonal Traversal: ";

    for (int x : result)
        cout << x << " ";

    cout << endl;

    return 0;
}