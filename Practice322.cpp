#include <iostream>
#include <queue>
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
// FUNCTION: bstUsingInorder()
// ----------------------------------------------------------------------
// PURPOSE:
//   Constructs a HEIGHT-BALANCED Binary Search Tree
//   from a sorted inorder array.
//
// INPUT:
//   • inorder[] → sorted array (inorder traversal of BST)
//   • s         → starting index
//   • e         → ending index
//
// KEY IDEA:
//   • Inorder traversal of a BST is sorted
//   • To create a balanced BST:
//       - Choose the middle element as root
//       - Recursively build left subtree from left half
//       - Recursively build right subtree from right half
//
// BASE CASE:
//   • If s > e → no elements → return NULL
//
// TIME COMPLEXITY: O(n)
// SPACE COMPLEXITY: O(h)  (recursion stack)
// ======================================================================
Node* bstUsingInorder(int inorder[], int s, int e) {

    // Base case: no elements to process
    if (s > e) {
        return NULL;
    }

    // Find middle element
    int mid = (s + e) / 2;
    int element = inorder[mid];

    // Create root node with middle element
    Node* root = new Node(element);

    // Recursively build left subtree
    root->left = bstUsingInorder(inorder, s, mid - 1);

    // Recursively build right subtree
    root->right = bstUsingInorder(inorder, mid + 1, e);

    return root;
}

// ======================================================================
// FUNCTION: inorderTraversal()
// ----------------------------------------------------------------------
// PURPOSE:
//   Prints the inorder traversal of the BST.
//
// USE CASE:
//   • Used here to VERIFY correctness
//   • Output should be sorted if BST is built correctly
//
// TIME COMPLEXITY: O(n)
// ======================================================================
void inorderTraversal(Node* root) {
    if (!root) return;

    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

// ======================================================================
// FUNCTION: levelOrderTraversal()
// ----------------------------------------------------------------------
// PURPOSE:
//   Prints the BST level by level (Breadth First Search).
//
// USE CASE:
//   • Helps visualize the SHAPE of the BST
//
// TIME COMPLEXITY: O(n)
// SPACE COMPLEXITY: O(n)
// ======================================================================
void levelOrderTraversal(Node* root) {
    if (!root) return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        cout << temp->data << " ";

        if (temp->left)
            q.push(temp->left);

        if (temp->right)
            q.push(temp->right);
    }
}

// ======================================================================
// MAIN FUNCTION
// ----------------------------------------------------------------------
// Builds a balanced BST from a sorted inorder array
// and prints inorder + level order traversal.
//
// SORTED INORDER ARRAY:
//   1 2 3 4 5 6 7
//
// CONSTRUCTED BALANCED BST:
//
//                4
//              /   \
//             2     6
//            / \   / \
//           1   3 5   7
// ======================================================================
int main() {

    // Given sorted inorder array
    int inorder[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(inorder) / sizeof(inorder[0]);

    // Construct BST
    Node* root = bstUsingInorder(inorder, 0, n - 1);

    // Verify using inorder traversal
    cout << "Inorder Traversal of BST: ";
    inorderTraversal(root);
    cout << endl;

    // Print tree structure using level order traversal
    cout << "Level Order Traversal of BST: ";
    levelOrderTraversal(root);
    cout << endl;

    return 0;
}
