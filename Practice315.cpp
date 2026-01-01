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
        this->left = NULL;
        this->right = NULL;
    }
};

// ======================================================================
// FUNCTION: insertIntoBST()
// ----------------------------------------------------------------------
// PURPOSE:
//   Inserts a value into the BST while maintaining BST properties.
//
// LOGIC:
//   • If tree is empty → create a new node
//   • If data < root->data → insert in left subtree
//   • Else → insert in right subtree
//
// TIME COMPLEXITY:
//   • Average: O(log n)
//   • Worst: O(n) (skewed tree)
// ======================================================================
Node* insertIntoBST(Node* root, int data) {

    // Base case: create first node
    if (root == NULL) {
        root = new Node(data);
        return root;
    }

    // Decide left or right subtree
    if (root->data > data) {
        // Insert into left subtree
        root->left = insertIntoBST(root->left, data);
    }
    else {
        // Insert into right subtree
        root->right = insertIntoBST(root->right, data);
    }

    return root;
}

// ======================================================================
// FUNCTION: takeInput()
// ----------------------------------------------------------------------
// PURPOSE:
//   Takes input from user and builds the BST.
//
// INPUT RULE:
//   • Input continues until -1 is encountered
//
// NOTE:
//   • Root is passed by reference so updates persist
// ======================================================================
void takeInput(Node*& root) {

    int data;
    cin >> data;

    while (data != -1) {
        root = insertIntoBST(root, data);
        cin >> data;
    }
}

// ======================================================================
// FUNCTION: levelOrderTraversal()
// ----------------------------------------------------------------------
// PURPOSE:
//   Prints the BST level by level (Breadth First Search).
//
// APPROACH:
//   • Use a queue
//   • Use NULL marker to separate levels
//
// TIME COMPLEXITY: O(n)
// SPACE COMPLEXITY: O(n)
// ======================================================================
void levelOrderTraversal(Node* root) {

    queue<Node*> q;

    // Initial push
    q.push(root);
    q.push(NULL);   // Marker for level separation

    while (!q.empty()) {

        Node* temp = q.front();
        q.pop();

        // End of current level
        if (temp == NULL) {
            cout << endl;
            if (!q.empty()) {
                q.push(NULL);
            }
        }
        else {
            // Print current node
            cout << temp->data << " ";

            // Push left and right children
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
// FUNCTION: findNodeInBST()
// ----------------------------------------------------------------------
// PURPOSE:
//   Searches for a target value in the BST.
//
// ASSUMPTION:
//   • All values in the BST are UNIQUE
//
// LOGIC:
//   • If current node matches target → return true
//   • If target > root->data → search right subtree
//   • Else → search left subtree
//
// TIME COMPLEXITY:
//   • Average: O(log n)
//   • Worst: O(n)
// ======================================================================
bool findNodeInBST(Node* root, int target) {

    // Base case: empty subtree
    if (root == NULL) {
        return false;
    }

    // Target found
    if (root->data == target)
        return true;

    // Decide subtree to search
    if (target > root->data) {
        // Search in right subtree
        return findNodeInBST(root->right, target);
    }
    else {
        // Search in left subtree
        return findNodeInBST(root->left, target);
    }
}

// ======================================================================
// MAIN FUNCTION
// ----------------------------------------------------------------------
// 1️⃣ Builds a BST using user input
// 2️⃣ Prints the BST using level order traversal
// 3️⃣ Searches for a specific value in the BST
//
// INPUT FORMAT:
//   Enter values followed by -1 to stop
// ======================================================================
int main() {

    Node* root = NULL;

    cout << "Enter the data for Node" << endl;
    takeInput(root);

    cout << "Printing the tree: " << endl;
    levelOrderTraversal(root);
    cout << endl;

    // Search for value 15
    bool ans = findNodeInBST(root, 15);
    cout << "Present or not : " << ans << endl;

    return 0;
}
