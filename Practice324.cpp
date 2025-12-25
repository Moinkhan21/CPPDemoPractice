#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// ======================================================================
// CLASS: TreeNode
// ----------------------------------------------------------------------
// Represents a node in a Binary Search Tree (BST)
// and also acts as a node in a Doubly Linked List (DLL).
//
// Each node contains:
//   • val   → value stored in the node
//   • left  → left child (BST) / previous pointer (DLL)
//   • right → right child (BST) / next pointer (DLL)
// ======================================================================
class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    // Constructor initializes node with given value
    // and sets both pointers to NULL
    TreeNode(int val) {
        this->val = val;
        left = NULL;
        right = NULL;
    }
};

// ======================================================================
// FUNCTION: bstUsingInorder()
// ----------------------------------------------------------------------
// PURPOSE:
//   Builds a HEIGHT-BALANCED BST from a sorted inorder array.
//
// LOGIC:
//   • Middle element becomes root
//   • Left half → left subtree
//   • Right half → right subtree
//
// BASE CASE:
//   • If start index > end index → return NULL
//
// TIME COMPLEXITY: O(n)
// SPACE COMPLEXITY: O(h)
// ======================================================================
TreeNode* bstUsingInorder(int inorder[], int s, int e) {
    if (s > e)
        return NULL;

    int mid = (s + e) / 2;
    TreeNode* root = new TreeNode(inorder[mid]);

    // Recursively build left and right subtrees
    root->left = bstUsingInorder(inorder, s, mid - 1);
    root->right = bstUsingInorder(inorder, mid + 1, e);

    return root;
}

// ======================================================================
// FUNCTION: levelOrderTraversal()
// ----------------------------------------------------------------------
// PURPOSE:
//   Prints the BST level by level (Breadth First Search).
//
// USE CASE:
//   • Helps visualize the structure of the BST
//
// TIME COMPLEXITY: O(n)
// SPACE COMPLEXITY: O(n)
// ======================================================================
void levelOrderTraversal(TreeNode* root) {
    if (!root) return;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* temp = q.front();
        q.pop();

        cout << temp->val << " ";

        if (temp->left)
            q.push(temp->left);

        if (temp->right)
            q.push(temp->right);
    }
}

// ======================================================================
// FUNCTION: convertIntoSortedDLL()
// ----------------------------------------------------------------------
// PURPOSE:
//   Converts a BST into a SORTED Doubly Linked List (DLL)
//   using REVERSE INORDER traversal.
//
// KEY IDEA:
//   • Inorder traversal of BST → sorted order
//   • Reverse inorder (Right → Node → Left)
//     allows building DLL from right to left
//
// PARAMETERS:
//   • root → current BST node
//   • head → reference to head of DLL
//
// POINTER USAGE:
//   • left  → previous pointer
//   • right → next pointer
//
// TIME COMPLEXITY: O(n)
// SPACE COMPLEXITY: O(h)
// ======================================================================
void convertIntoSortedDLL(TreeNode* root, TreeNode* &head) {

    // Base case
    if (root == NULL)
        return;

    // --------------------------------------------------
    // Step 1: Process RIGHT subtree first
    // --------------------------------------------------
    convertIntoSortedDLL(root->right, head);

    // --------------------------------------------------
    // Step 2: Attach current node to DLL
    // --------------------------------------------------
    root->right = head;      // next pointer
    if (head)
        head->left = root;  // previous pointer

    head = root;             // update head

    // --------------------------------------------------
    // Step 3: Process LEFT subtree
    // --------------------------------------------------
    convertIntoSortedDLL(root->left, head);
}

// ======================================================================
// FUNCTION: printLinkedList()
// ----------------------------------------------------------------------
// PURPOSE:
//   Prints the Doubly Linked List from head to tail
//   using right (next) pointers.
// ======================================================================
void printLinkedList(TreeNode* head) {
    TreeNode* temp = head;
    while (temp) {
        cout << temp->val << " ";
        temp = temp->right;
    }
    cout << endl;
}

// ======================================================================
// MAIN FUNCTION
// ----------------------------------------------------------------------
// • Builds a balanced BST from sorted inorder array
// • Prints BST using level order traversal
// • Converts BST into sorted DLL
// • Prints the DLL
//
// INORDER ARRAY:
//   1 2 3 4 5 6 7 8 9
// ======================================================================
int main() {

    int inorder[] = {1,2,3,4,5,6,7,8,9};
    int n = sizeof(inorder) / sizeof(inorder[0]);

    // Build balanced BST
    TreeNode* root = bstUsingInorder(inorder, 0, n - 1);

    cout << "Level Order Traversal of BST:\n";
    levelOrderTraversal(root);
    cout << endl;

    // Convert BST to sorted DLL
    TreeNode* head = NULL;
    convertIntoSortedDLL(root, head);

    cout << "Sorted Doubly Linked List:\n";
    printLinkedList(head);

    return 0;
}
