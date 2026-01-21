#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// ======================================================================
// CLASS: Node
// ----------------------------------------------------------------------
// Represents a node in a Binary Search Tree (BST).
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
    // and sets both children to NULL
    Node(int data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

// ======================================================================
// FUNCTION: merge()
// ----------------------------------------------------------------------
// PURPOSE:
//   Merges two Binary Search Trees into a single
//   sorted list of elements.
//
// KEY IDEA:
//   • Inorder traversal of BST gives sorted order
//   • Perform iterative inorder traversal on BOTH BSTs
//   • Merge results similar to merging two sorted arrays
//
// DATA STRUCTURES USED:
//   • sa → stack for BST1 inorder traversal
//   • sb → stack for BST2 inorder traversal
//
// APPROACH:
//   1️⃣ Push all left nodes of both trees
//   2️⃣ Compare top elements of stacks
//   3️⃣ Take the smaller one and move to its right subtree
//
// TIME COMPLEXITY: O(n1 + n2)
// SPACE COMPLEXITY: O(h1 + h2)
// ======================================================================
vector<int> merge(Node* root1, Node* root2) {

    vector<int> ans;           // Stores merged sorted result
    stack<Node*> sa, sb;       // Stacks for inorder traversal

    Node* a = root1;           // Pointer for BST1
    Node* b = root2;           // Pointer for BST2

    // Continue until both trees are fully processed
    while (a || b || !sa.empty() || !sb.empty()) {

        // -------------------------------------------------- 
        // Push all left children of BST1
        // --------------------------------------------------
        while (a) {
            sa.push(a);
            a = a->left;
        }

        // --------------------------------------------------
        // Push all left children of BST2
        // --------------------------------------------------
        while (b) {
            sb.push(b);
            b = b->left;
        }

        // --------------------------------------------------
        // Choose the smaller top element
        // --------------------------------------------------
        if (sb.empty() || (!sa.empty() && sa.top()->data <= sb.top()->data)) {

            // Take node from BST1
            Node* atop = sa.top();
            sa.pop();

            ans.push_back(atop->data);   // Add to result
            a = atop->right;             // Move to right subtree
        }
        else {

            // Take node from BST2
            Node* btop = sb.top();
            sb.pop();

            ans.push_back(btop->data);   // Add to result
            b = btop->right;             // Move to right subtree
        }
    }

    return ans;
}

// ======================================================================
// MAIN FUNCTION
// ----------------------------------------------------------------------
// Builds two BSTs, merges them,
// and prints the sorted merged output.
//
// BST 1:
//            3
//           / \
//          1   5
//
// BST 2:
//            4
//           / \
//          2   6
//
// MERGED OUTPUT:
//   1 2 3 4 5 6
// ======================================================================
int main() {

    // Constructing BST 1
    Node* root1 = new Node(3);
    root1->left = new Node(1);
    root1->right = new Node(5);

    // Constructing BST 2
    Node* root2 = new Node(4);
    root2->left = new Node(2);
    root2->right = new Node(6);

    // Merge BSTs
    vector<int> result = merge(root1, root2);

    cout << "Merged BST elements:\n";
    for (int x : result)
        cout << x << " ";
    cout << endl;

    return 0;
}
