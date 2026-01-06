#include <iostream>
#include <queue>
using namespace std;

// ======================================================================
// CLASS: Node
// ----------------------------------------------------------------------
// PURPOSE:
//   Represents a single node of the binary tree used for BST construction.
//
// DATA MEMBERS:
//   • data  → integer value stored in this node
//   • left  → pointer to left child node
//   • right → pointer to right child node
//
// CONSTRUCTOR:
//   Initializes the node with given value and sets children to NULL.
// ======================================================================
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        // Store the value in current node
        this->data = data;

        // Initially both children are empty
        this->left = NULL;
        this->right = NULL;
    }
};

// ======================================================================
// FUNCTION: findPosition()
// ----------------------------------------------------------------------
// PURPOSE:
//   Finds index of an element inside INORDER array.
//
// PARAMETERS:
//   • arr[]   → array in which we need to search
//   • n       → size of array
//   • element → value to find
//
// RETURN:
//   • index if found
//   • -1 if not found
//
// TIME COMPLEXITY: O(n)
// ======================================================================
int findPosition(int arr[], int n, int element) {

    // Linear search through array
    for (int i = 0; i < n; i++) {

        // Match found
        if (arr[i] == element) {
            return i;
        }
    }

    // Element not present
    return -1;
}

// ======================================================================
// FUNCTION: buildTreeFromPostOrderInOrder()
// ----------------------------------------------------------------------
// PURPOSE:
//   Constructs BST from given inorder + postorder traversal.
//
// PARAMETERS:
//   • inorder[]        → sorted inorder traversal
//   • postorder[]      → postorder traversal
//   • postIndex (ref)  → tracks current root position in postorder
//   • size             → total number of nodes
//   • inorderStart     → start index of current subtree
//   • inorderEnd       → end index of current subtree
//
// APPROACH:
//   1️⃣ Pick element from postorder using postIndex
//   2️⃣ Create node
//   3️⃣ Find position in inorder
//   4️⃣ Build RIGHT subtree first
//   5️⃣ Then build LEFT subtree
//
// BASE CASE:
//   • No elements left in subtree
//   • postIndex exhausted
//
// TIME COMPLEXITY: O(n²) due to findPosition
// ======================================================================
Node* buildTreeFromPostOrderInOrder(
    int inorder[],
    int postorder[],
    int &postIndex,
    int size,
    int inorderStart,
    int inorderEnd
) {

    // -------------------------------
    // BASE CONDITION
    // -------------------------------
    if (postIndex < 0 || inorderStart > inorderEnd) {
        return NULL;
    }

    // -------------------------------
    // STEP A: Create ROOT node
    // -------------------------------
    int element = postorder[postIndex];

    // Move index backward
    postIndex--;

    // Create node with that value
    Node* root = new Node(element);

    // -------------------------------
    // STEP B: Find split in INORDER
    // -------------------------------
    int pos = findPosition(inorder, size, element);

    // -------------------------------
    // STEP C: Build RIGHT subtree
    // -------------------------------
    root->right = buildTreeFromPostOrderInOrder(
        inorder,
        postorder,
        postIndex,
        size,
        pos + 1,
        inorderEnd
    );

    // -------------------------------
    // STEP D: Build LEFT subtree
    // -------------------------------
    root->left = buildTreeFromPostOrderInOrder(
        inorder,
        postorder,
        postIndex,
        size,
        inorderStart,
        pos - 1
    );

    // Return constructed subtree root
    return root;
}

// ======================================================================
// FUNCTION: levelOrderTraversal()
// ----------------------------------------------------------------------
// PURPOSE:
//   Prints tree level-by-level using BFS.
//
// TECHNIQUE:
//   • Queue
//   • NULL marker for line break
//
// TIME COMPLEXITY: O(n)
// ======================================================================
void levelOrderTraversal(Node* root) {

    // Safety check
    if (!root) return;

    // Create queue for BFS
    queue<Node*> q;

    // Push root + NULL marker
    q.push(root);
    q.push(NULL);

    while (!q.empty()) {

        // STEP A: Take front
        Node* temp = q.front();

        // STEP B: Pop it
        q.pop();

        // If NULL → new line
        if (temp == NULL) {

            cout << endl;

            // If nodes still remain
            if (!q.empty()) {
                q.push(NULL);
            }
        }
        else {

            // Print node data
            cout << temp->data << " ";

            // Push children if exist
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
// MAIN FUNCTION
// ======================================================================
int main() {

    // ------------------------------------------------
    // GIVEN TEST CASE
    // ------------------------------------------------
    int inorder[]   = {40, 20, 10, 50, 30, 60};
    int postorder[] = {40, 20, 50, 60, 30, 10};

    int size = 6;

    // PostIndex starts from end of postorder
    int postIndex = size - 1;

    int inorderStart = 0;
    int inorderEnd   = size - 1;

    cout << "Building the tree:" << endl;

    // Build BST
    Node* root = buildTreeFromPostOrderInOrder(
        inorder,
        postorder,
        postIndex,
        size,
        inorderStart,
        inorderEnd
    );

    cout << "\nPrinting the tree:" << endl;

    // Verify structure
    levelOrderTraversal(root);

    return 0;
}
