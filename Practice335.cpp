// C++ program to search a given key in a BST
// and flatten the BST into a sorted linked list
#include <iostream>
using namespace std;

// ======================================================================
// STRUCT: node
// ----------------------------------------------------------------------
// Represents a node in a Binary Search Tree (BST).
//
// Each node contains:
//   • key   → value stored in the node
//   • left  → pointer to left child
//   • right → pointer to right child
// ======================================================================
struct node {
    int key;
    struct node* left;
    struct node* right;
};

// ======================================================================
// FUNCTION: newNode()
// ----------------------------------------------------------------------
// PURPOSE:
//   Creates and returns a new BST node with the given key.
//
// TIME COMPLEXITY: O(1)
// ======================================================================
struct node* newNode(int item) {
    struct node* temp = new struct node;
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

// ======================================================================
// FUNCTION: insert()
// ----------------------------------------------------------------------
// PURPOSE:
//   Inserts a new key into the BST while maintaining BST properties.
//
// LOGIC:
//   • If tree is empty → create new node
//   • If key < current node → insert into left subtree
//   • If key > current node → insert into right subtree
//
// TIME COMPLEXITY:
//   Average: O(log n)
//   Worst:   O(n) (skewed tree)
// ======================================================================
struct node* insert(struct node* node, int key) {

    // If the tree is empty, create a new node
    if (node == NULL)
        return newNode(key);

    // Recur down the tree
    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);

    // Return unchanged root pointer
    return node;
}

// ======================================================================
// FUNCTION: search()
// ----------------------------------------------------------------------
// PURPOSE:
//   Searches for a given key in the BST.
//
// LOGIC:
//   • If root is NULL or key found → return root
//   • If key is greater → search right subtree
//   • If key is smaller → search left subtree
//
// TIME COMPLEXITY:
//   Average: O(log n)
//   Worst:   O(n)
// ======================================================================
struct node* search(struct node* root, int key) {

    // Base case: root is NULL or key matches
    if (root == NULL || root->key == key)
        return root;

    // Key is greater than current node
    if (root->key < key)
        return search(root->right, key);

    // Key is smaller than current node
    return search(root->left, key);
}

// ======================================================================
// FUNCTION: printLL()
// ----------------------------------------------------------------------
// PURPOSE:
//   Prints the flattened BST as a linked list
//   using right pointers.
//
// NOTE:
//   After flattening, BST behaves like a sorted
//   singly linked list.
// ======================================================================
void printLL(node* head) {
    while (head) {
        cout << head->key << " ";
        head = head->right;
    }
}

// ======================================================================
// FUNCTION: in()
// ----------------------------------------------------------------------
// PURPOSE:
//   Helper function to flatten BST into a sorted
//   linked list using INORDER traversal.
//
// PARAMETERS:
//   • root → current BST node
//   • prev → previously processed node (by reference)
//
// LOGIC:
//   • Perform inorder traversal (Left → Node → Right)
//   • Connect previous node to current node
//
// TIME COMPLEXITY: O(n)
// SPACE COMPLEXITY: O(h)
// ======================================================================
void in(node* root, node*& prev) {

    // Base case
    if (!root) return;

    // Process left subtree
    in(root->left, prev);

    // Link previous node with current node
    prev->left = NULL;
    prev->right = root;
    prev = root;

    // Process right subtree
    in(root->right, prev);
}

// ======================================================================
// FUNCTION: flatten()
// ----------------------------------------------------------------------
// PURPOSE:
//   Converts a BST into a sorted linked list
//   using inorder traversal.
//
// APPROACH:
//   • Use a dummy node to simplify linking
//   • Perform inorder traversal
//   • Return dummy->right as head of list
//
// TIME COMPLEXITY: O(n)
// SPACE COMPLEXITY: O(h)
// ======================================================================
node* flatten(node* root) {

    // Dummy node to start linked list
    node* dummy = newNode(-1);
    node* prev = dummy;

    // Flatten BST using inorder traversal
    in(root, prev);

    // Properly terminate linked list
    prev->left = prev->right = NULL;

    // Actual head of linked list
    root = dummy->right;
    return root;
}

// ======================================================================
// MAIN FUNCTION
// ----------------------------------------------------------------------
// Builds a BST, flattens it into a sorted linked list,
// and prints the result.
//
// BST VALUES INSERTED:
//   5, 3, 2, 4, 7, 6, 8
//
// OUTPUT (Sorted Linked List):
//   2 3 4 5 6 7 8
// ======================================================================
int main() {

    struct node* root = NULL;

    // Insert elements into BST
    root = insert(root, 5);
    insert(root, 3);
    insert(root, 2);
    insert(root, 4);
    insert(root, 7);
    insert(root, 6);
    insert(root, 8);

    // Flatten BST into sorted linked list
    root = flatten(root);

    // Print linked list
    printLL(root);

    return 0;
}
