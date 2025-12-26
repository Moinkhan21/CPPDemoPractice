#include <iostream>
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
// FUNCTION: countPairs()
// ----------------------------------------------------------------------
// PURPOSE:
//   Counts the number of pairs (u, v) such that:
//     • u is a node from BST1
//     • v is a node from BST2
//     • u->data + v->data == x
//
// APPROACH (Two Pointer Technique on BSTs):
//   • Perform INORDER traversal on BST1  → ascending order
//   • Perform REVERSE INORDER traversal on BST2 → descending order
//   • Similar to two-pointer technique on sorted arrays
//
// DATA STRUCTURES USED:
//   • s1 → stack for inorder traversal of BST1
//   • s2 → stack for reverse inorder traversal of BST2
//
// TIME COMPLEXITY: O(n1 + n2)
// SPACE COMPLEXITY: O(h1 + h2)
// ======================================================================
int countPairs(Node* root1, Node* root2, int x) {

    int ans = 0;               // Stores count of valid pairs
    stack<Node*> s1, s2;       // Stacks for BST traversals

    Node* a = root1;           // Pointer for BST1
    Node* b = root2;           // Pointer for BST2

    while (true) {

        // --------------------------------------------------
        // Step 1: Inorder traversal for BST1
        // (Smallest to largest)
        // --------------------------------------------------
        while (a) {
            s1.push(a);
            a = a->left;
        }

        // --------------------------------------------------
        // Step 2: Reverse inorder traversal for BST2
        // (Largest to smallest)
        // --------------------------------------------------
        while (b) {
            s2.push(b);
            b = b->right;
        }

        // If either stack is empty, no more pairs possible
        if (s1.empty() || s2.empty())
            break;

        // Get current nodes from both BSTs
        Node* atop = s1.top();
        Node* btop = s2.top();

        int sum = atop->data + btop->data;

        // --------------------------------------------------
        // Step 3: Compare sum with target
        // --------------------------------------------------
        if (sum == x) {
            // Valid pair found
            ++ans;

            // Move both pointers
            s1.pop();
            s2.pop();
            a = atop->right;
            b = btop->left;
        }
        else if (sum < x) {
            // Need larger sum → move inorder pointer forward
            s1.pop();
            a = atop->right;
        }
        else {
            // Need smaller sum → move reverse inorder pointer backward
            s2.pop();
            b = btop->left;
        }
    }

    return ans;
}

// ======================================================================
// MAIN FUNCTION
// ----------------------------------------------------------------------
// Builds two BSTs and counts number of pairs
// whose sum equals the given target value.
//
// BST 1:
//            5
//           / \
//          3   7
//         / \
//        2   4
//
// BST 2:
//            10
//           /  \
//          6    15
//         / \     \
//        3   8     18
//
// TARGET SUM = 11
// VALID PAIRS:
//   (5,6), (3,8)
//
// ANSWER = 2
// ======================================================================
int main() {

    // Constructing BST 1
    Node* root1 = new Node(5);
    root1->left = new Node(3);
    root1->right = new Node(7);
    root1->left->left = new Node(2);
    root1->left->right = new Node(4);

    // Constructing BST 2
    Node* root2 = new Node(10);
    root2->left = new Node(6);
    root2->right = new Node(15);
    root2->left->left = new Node(3);
    root2->left->right = new Node(8);
    root2->right->right = new Node(18);

    int x = 11;

    // Count and print number of valid pairs
    cout << "Number of pairs = "
         << countPairs(root1, root2, x) << endl;

    return 0;
}
