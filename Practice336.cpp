#include <iostream>
#include <vector>
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
// FUNCTION: insert()
// ----------------------------------------------------------------------
// PURPOSE:
//   Inserts a value into the BST and simultaneously
//   tracks the INORDER SUCCESSOR of that value.
//
// PARAMETERS:
//   • root → root of BST
//   • val  → value to be inserted
//   • succ → reference variable to store successor
//
// LOGIC:
//   • If val < root->data:
//       - Current root is a potential successor
//       - Move to left subtree
//   • Else:
//       - Move to right subtree
//
// WHY THIS WORKS?
//   • Inorder successor in BST is the smallest element
//     greater than the current value.
//
// TIME COMPLEXITY:
//   Average: O(log n)
//   Worst:   O(n)
// ======================================================================
Node* insert(Node* root, int val, int &succ) {

    // Base case: insert new node
    if (!root)
        return new Node(val);

    // If value is greater or equal, move right
    if (val >= root->data) {
        root->right = insert(root->right, val, succ);
    }
    else {
        // Current node is a potential successor
        succ = root->data;
        root->left = insert(root->left, val, succ);
    }

    return root;
}

// ======================================================================
// FUNCTION: findLeastGreater()
// ----------------------------------------------------------------------
// PURPOSE:
//   Finds the Least Greater Element on the RIGHT side
//   of each array element.
//
// APPROACH:
//   • Traverse array from RIGHT to LEFT
//   • Insert elements into BST
//   • While inserting, track inorder successor
//
// WHY RIGHT TO LEFT?
//   • BST must contain only elements to the right
//     of current index
//
// TIME COMPLEXITY:
//   Average: O(n log n)
//   Worst:   O(n²)
//
// SPACE COMPLEXITY: O(n)
// ======================================================================
vector<int> findLeastGreater(vector<int> &arr, int n) {

    vector<int> ans(arr.size());   // Stores result
    Node* root = NULL;             // Root of BST

    // Traverse array from right to left
    for (int i = arr.size() - 1; i >= 0; --i) {

        int succ = -1;             // Default: no greater element
        root = insert(root, arr[i], succ);
        ans[i] = succ;
    }

    return ans;
}

// ======================================================================
// MAIN FUNCTION
// ----------------------------------------------------------------------
// Given an array, finds the least greater element
// on the right for every element.
//
// INPUT:
//   [8, 58, 71, 18, 31, 32, 63, 92, 43, 3, 91, 93, 25, 80, 28]
//
// OUTPUT:
//   [18, 63, 80, 25, 32, 43, 80, 93, 80, 25, 93, -1, 28, -1, -1]
// ======================================================================
int main() {

    vector<int> arr = {
        8, 58, 71, 18, 31, 32, 63,
        92, 43, 3, 91, 93, 25, 80, 28
    };

    // Find least greater elements
    vector<int> ans = findLeastGreater(arr, arr.size());

    cout << "Least Greater Elements:\n";
    for (int x : ans)
        cout << x << " ";
    cout << endl;

    return 0;
}
