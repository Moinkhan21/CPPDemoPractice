#include <iostream>
#include <queue>
using namespace std;

// ======================================================================
// CLASS: Node
// ----------------------------------------------------------------------
// Represents a node in a Binary Tree.
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

    // Constructor to initialize node
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
//   Finds the index of a given element in the inorder array.
//
// PARAMETERS:
//   • arr     → inorder array
//   • n       → size of array
//   • element → value to find
//
// RETURNS:
//   • index of element if found
//   • -1 if not found
//
// TIME COMPLEXITY: O(n)
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
// FUNCTION: buildTreeFromPreOrderInOrder()
// ----------------------------------------------------------------------
// PURPOSE:
//   Builds a Binary Tree using preorder and inorder traversals.
//
// PARAMETERS:
//   • inorder       → inorder traversal array
//   • preorder      → preorder traversal array
//   • size          → total number of nodes
//   • preIndex      → current index in preorder (passed by reference)
//   • inorderStart  → start index of inorder segment
//   • inorderEnd    → end index of inorder segment
//
// CORE LOGIC:
//   1️⃣ Take current preorder element as root
//   2️⃣ Find root position in inorder array
//   3️⃣ Recursively build left subtree
//   4️⃣ Recursively build right subtree
//
// TRAVERSAL PROPERTIES USED:
//   • Preorder → Root is processed first
//   • Inorder  → Left | Root | Right
//
// TIME COMPLEXITY: O(n²) (due to linear search in inorder)
// SPACE COMPLEXITY: O(h)
// ======================================================================
Node* buildTreeFromPreOrderInOrder(
    int inorder[],
    int preorder[],
    int size,
    int &preIndex,
    int inorderStart,
    int inorderEnd
) {

    // Base case
    if (preIndex >= size || inorderStart > inorderEnd) {
        return NULL;
    }

    // Step A: Create root from preorder
    int element = preorder[preIndex++];
    Node* root = new Node(element);

    // Find root position in inorder array
    int pos = findPosition(inorder, size, element);

    // Step B: Build left subtree
    root->left = buildTreeFromPreOrderInOrder(
        inorder, preorder, size, preIndex,
        inorderStart, pos - 1
    );

    // Step C: Build right subtree
    root->right = buildTreeFromPreOrderInOrder(
        inorder, preorder, size, preIndex,
        pos + 1, inorderEnd
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

        // End of one level
        if (temp == NULL) {
            cout << endl;
            if (!q.empty()) {
                q.push(NULL);
            }
        }
        else {
            // Print node value
            cout << temp->data << " ";

            // Push children
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

    /*
        Inorder   : 40 20 50 10 60 30 70
        Preorder  : 10 20 40 50 30 60 70

        Constructed Tree:
                 10
               /    \
             20      30
            /  \    /  \
          40   50  60  70
    */

    int inorder[]  = {40, 20, 50, 10, 60, 30, 70};
    int preorder[] = {10, 20, 40, 50, 30, 60, 70};

    int size = 7;
    int preIndex = 0;
    int inorderStart = 0;
    int inorderEnd = size - 1;

    cout << "Building tree: " << endl;

    Node* root = buildTreeFromPreOrderInOrder(
        inorder, preorder, size, preIndex,
        inorderStart, inorderEnd
    );

    cout << endl << "Printing level order traversal " << endl;
    levelOrderTraversal(root);

    return 0;
}
