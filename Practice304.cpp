#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// ======================================================================
// CLASS: Node
// ----------------------------------------------------------------------
// Represents a node of a Binary Tree.
// Each node contains:
//   • data  → integer value stored in the node
//   • left  → pointer to left child
//   • right → pointer to right child
// ======================================================================
class Node {
public:
    int data;
    Node* left;
    Node* right;

    // Constructor initializes node with given value
    // and sets left & right children to NULL
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
//   Performs DIAGONAL TRAVERSAL of a binary tree.
//
// DIAGONAL TRAVERSAL RULE:
//   • All nodes lying on the same diagonal are printed together.
//   • For any node:
//        - RIGHT child stays on the SAME diagonal
//        - LEFT child goes to the NEXT diagonal
//
// APPROACH: Queue + Right Traversal
//
// ALGORITHM:
//   1. Push root into a queue.
//   2. While queue is not empty:
//        a) Pop a node from queue → starting node of a diagonal
//        b) Traverse its right chain:
//             • Add current node data to answer
//             • Push left child into queue (for next diagonal)
//             • Move to right child
//
// WHY QUEUE?
//   Queue stores left children that belong to future diagonals,
//   ensuring correct diagonal-by-diagonal traversal.
//
// TIME COMPLEXITY: O(n)
// SPACE COMPLEXITY: O(n)
// ======================================================================
vector<int> diagonal(Node* root) {

    vector<int> ans;

    // Edge case: empty tree
    if (!root) return ans;

    queue<Node*> q;
    q.push(root);   // Start traversal from root

    while (!q.empty()) {

        // Take the front node from queue
        Node* temp = q.front();
        q.pop();

        // Traverse all nodes in the current diagonal
        while (temp) {

            // Add current node value to answer
            ans.push_back(temp->data);

            // LEFT child belongs to the next diagonal
            if (temp->left)
                q.push(temp->left);

            // Move along the same diagonal using RIGHT pointer
            temp = temp->right;
        }
    }

    return ans;
}

// ======================================================================
// MAIN FUNCTION
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
// DIAGONAL TRAVERSAL OUTPUT:
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
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
