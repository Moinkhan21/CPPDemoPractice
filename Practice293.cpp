#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

// ======================================================================
// CLASS: Node
// ----------------------------------------------------------------------
// Represents a node of a Binary Tree.
//
// Each node contains:
//   • data  → value of the node
//   • left  → pointer to left child
//   • right → pointer to right child
// ======================================================================
class Node {
public:
    int data;
    Node* left;
    Node* right;

    // Constructor initializes node with given value
    Node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

// ======================================================================
// FUNCTION: findPosition()
// ----------------------------------------------------------------------
// PURPOSE:
//   Finds index of an element in inorder array (linear search).
//
// NOTE:
//   This function is NOT used in final logic because
//   we optimized using hashmap (unordered_map).
// ======================================================================
int findPosition(int arr[], int n, int element) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == element) {
            return i;
        }
    }
    return -1;
}

// ======================================================================
// FUNCTION: buildTreeFromPostOrderInOrder()
// ----------------------------------------------------------------------
// PURPOSE:
//   Builds a Binary Tree using POSTORDER and INORDER traversals.
//
// PARAMETERS:
//   • inorder        → inorder traversal array
//   • postorder      → postorder traversal array
//   • postIndex      → current index in postorder (passed by reference)
//   • size           → number of nodes
//   • inorderStart   → start index of inorder segment
//   • inorderEnd     → end index of inorder segment
//   • mapping        → value → index mapping of inorder array
//
// CORE IDEA:
//   • Postorder traversal gives ROOT at the end
//   • Inorder traversal splits left & right subtrees
//   • Build RIGHT subtree first (because postorder goes backward)
//
// TIME COMPLEXITY: O(n)
// SPACE COMPLEXITY: O(h)
// ======================================================================
Node* buildTreeFromPostOrderInOrder(
    int inorder[],
    int postorder[],
    int &postIndex,
    int size,
    int inorderStart,
    int inorderEnd,
    unordered_map<int, int> mapping
) {

    // Base case
    if (postIndex < 0 || inorderStart > inorderEnd) {
        return NULL;
    }

    // --------------------------------------------------
    // Step A: Create root from postorder
    // --------------------------------------------------
    int element = postorder[postIndex];
    postIndex--;
    Node* root = new Node(element);

    // Find root position in inorder using hashmap
    int pos = mapping[element];

    // --------------------------------------------------
    // Step B: Build RIGHT subtree first
    // --------------------------------------------------
    root->right = buildTreeFromPostOrderInOrder(
        inorder, postorder, postIndex, size,
        pos + 1, inorderEnd, mapping
    );

    // --------------------------------------------------
    // Step C: Build LEFT subtree
    // --------------------------------------------------
    root->left = buildTreeFromPostOrderInOrder(
        inorder, postorder, postIndex, size,
        inorderStart, pos - 1, mapping
    );

    return root;
}

// ======================================================================
// FUNCTION: levelOrderTraversal()
// ----------------------------------------------------------------------
// PURPOSE:
//   Prints the tree level by level (Breadth First Traversal).
//
// APPROACH:
//   • Uses queue
//   • NULL marker separates levels
//
// TIME COMPLEXITY: O(n)
// SPACE COMPLEXITY: O(n)
// ======================================================================
void levelOrderTraversal(Node* root) {

    queue<Node*> q;

    // Initially push root and NULL marker
    q.push(root);
    q.push(NULL);

    while (!q.empty()) {

        Node* temp = q.front();
        q.pop();

        if (temp == NULL) {
            cout << endl;
            if (!q.empty()) {
                q.push(NULL);
            }
        }
        else {
            cout << temp->data << " ";

            if (temp->left) {
                q.push(temp->left);
            }
            if (temp->right) {
                q.push(temp->right);
            }
        }
    }
}

// ======================================================================
// FUNCTION: createMapping()
// ----------------------------------------------------------------------
// PURPOSE:
//   Creates a hashmap for inorder traversal
//   to store value → index mapping.
//
// BENEFIT:
//   • Reduces search from O(n) to O(1)
//
// TIME COMPLEXITY: O(n)
// ======================================================================
void createMapping(unordered_map<int, int> &mapping, int inorder[], int n) {
    for (int i = 0; i < n; i++) {
        mapping[inorder[i]] = i;
    }
}

// ======================================================================
// MAIN FUNCTION
// ======================================================================
int main() {

    /*
        Inorder    : 40 20 10 50 30 60
        Postorder  : 40 20 50 60 30 10

        Constructed Tree:
                 10
               /    \
             20      30
            /       /  \
          40      50   60
    */

    int inorder[]   = {40, 20, 10, 50, 30, 60};
    int postorder[] = {40, 20, 50, 60, 30, 10};

    int size = 6;
    int postIndex = size - 1;
    int inorderStart = 0;
    int inorderEnd = size - 1;

    unordered_map<int, int> mapping;
    createMapping(mapping, inorder, size);

    cout << "Building the tree: " << endl;
    Node* root = buildTreeFromPostOrderInOrder(
        inorder, postorder, postIndex, size,
        inorderStart, inorderEnd, mapping
    );

    cout << "Printing the tree: " << endl;
    levelOrderTraversal(root);

    return 0;
}
