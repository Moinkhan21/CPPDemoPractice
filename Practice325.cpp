#include <iostream>
#include <queue>
using namespace std;

// ======================================================================
// CLASS: Node
// ----------------------------------------------------------------------
// Represents a node in a Binary Search Tree (BST)
// and also reused as a Doubly Linked List node.
//
// Each node contains:
//   • data  → value stored in the node
//   • left  → pointer to left child / previous DLL node
//   • right → pointer to right child / next DLL node
// ======================================================================
class Node {
public:
    int data;
    Node* left;
    Node* right;

    // Constructor initializes node with given value
    // and sets both pointers to NULL
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
//   Builds a HEIGHT-BALANCED BST from a sorted inorder array.
//
// APPROACH:
//   • Choose middle element as root
//   • Left half → left subtree
//   • Right half → right subtree
//
// BASE CASE:
//   • If start index > end index → return NULL
//
// TIME COMPLEXITY: O(n)
// SPACE COMPLEXITY: O(h)
// ======================================================================
Node* bstUsingInorder(int inorder[], int s, int e) {

    // Base case
    if (s > e)
        return NULL;

    // Choose middle element
    int mid = (s + e) / 2;
    Node* root = new Node(inorder[mid]);

    // Recursively build left and right subtrees
    root->left = bstUsingInorder(inorder, s, mid - 1);
    root->right = bstUsingInorder(inorder, mid + 1, e);

    return root;
}

// ======================================================================
// FUNCTION: levelOrderTraversal()
// ----------------------------------------------------------------------
// PURPOSE:
//   Prints the tree in LEVEL ORDER (Breadth First Search).
//
// USE CASE:
//   • Helps visualize tree structure before and after conversion
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

        if (temp->left) q.push(temp->left);
        if (temp->right) q.push(temp->right);
    }
    cout << endl;
}

// ======================================================================
// FUNCTION: convertIntoSortedDLL()
// ----------------------------------------------------------------------
// PURPOSE:
//   Converts a BST into a SORTED DOUBLY LINKED LIST.
//
// KEY IDEA:
//   • Use REVERSE INORDER traversal (Right → Node → Left)
//   • Always insert node at the head of DLL
//
// PARAMETERS:
//   • root → current BST node
//   • head → reference to head of DLL
//
// TIME COMPLEXITY: O(n)
// SPACE COMPLEXITY: O(h)
// ======================================================================
void convertIntoSortedDLL(Node* root, Node*& head) {

    // Base case
    if (root == NULL)
        return;

    // Convert right subtree first
    convertIntoSortedDLL(root->right, head);

    // Attach current node at head of DLL
    root->right = head;
    if (head)
        head->left = root;

    head = root;

    // Convert left subtree
    convertIntoSortedDLL(root->left, head);
}

// ======================================================================
// FUNCTION: printLinkedList()
// ----------------------------------------------------------------------
// PURPOSE:
//   Prints the sorted doubly linked list
//   using right pointers.
//
// TIME COMPLEXITY: O(n)
// ======================================================================
void printLinkedList(Node* head) {

    Node* temp = head;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->right;
    }
    cout << endl;
}

// ======================================================================
// FUNCTION: sortedLinkedListIntoBST()
// ----------------------------------------------------------------------
// PURPOSE:
//   Converts a SORTED DOUBLY LINKED LIST
//   into a HEIGHT-BALANCED BST.
//
// APPROACH (Inorder Simulation):
//   • Build left subtree from first n/2 nodes
//   • Current head becomes root
//   • Move head forward
//   • Build right subtree from remaining nodes
//
// PARAMETERS:
//   • head → reference to current DLL head
//   • n    → number of nodes in DLL
//
// TIME COMPLEXITY: O(n)
// SPACE COMPLEXITY: O(h)
// ======================================================================
Node* sortedLinkedListIntoBST(Node*& head, int n) {

    // Base case
    if (n <= 0 || head == NULL)
        return NULL;

    // Build left subtree
    Node* leftSubtree = sortedLinkedListIntoBST(head, n / 2);

    // Current head becomes root
    Node* root = head;
    root->left = leftSubtree;

    // Move head to next DLL node
    head = head->right;

    // Build right subtree
    root->right = sortedLinkedListIntoBST(head, n - 1 - n / 2);

    return root;
}

// ======================================================================
// MAIN FUNCTION
// ----------------------------------------------------------------------
// Demonstrates complete conversion flow:
//
//   1️⃣ Sorted array → Balanced BST
//   2️⃣ BST → Sorted Doubly Linked List
//   3️⃣ DLL → Balanced BST
//
// INPUT ARRAY:
//   1 2 3 4 5 6 7 8 9
// ======================================================================
int main() {

    int inorder[] = {1,2,3,4,5,6,7,8,9};
    int n = sizeof(inorder) / sizeof(inorder[0]);

    // --------------------------------------------------
    // Step 1: Inorder Array → Balanced BST
    // --------------------------------------------------
    Node* root = bstUsingInorder(inorder, 0, n - 1);
    cout << "Level Order Traversal of BST:\n";
    levelOrderTraversal(root);

    // --------------------------------------------------
    // Step 2: BST → Sorted Doubly Linked List
    // --------------------------------------------------
    Node* head = NULL;
    convertIntoSortedDLL(root, head);

    cout << "Sorted Doubly Linked List:\n";
    printLinkedList(head);

    // --------------------------------------------------
    // Step 3: Sorted DLL → Balanced BST
    // --------------------------------------------------
    Node* root1 = sortedLinkedListIntoBST(head, n);

    cout << "Level Order Traversal after DLL -> BST:\n";
    levelOrderTraversal(root1);

    return 0;
}
