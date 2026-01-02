#include <iostream>
#include <queue>
using namespace std;

// ======================================================================
// CLASS: Node
// ----------------------------------------------------------------------
// Represents a node of a Binary Search Tree (BST)
//
// Each node contains:
//   • data  → value stored
//   • left  → pointer to left child
//   • right → pointer to right child
// ======================================================================
class Node {
public:
    int data;
    Node* left;
    Node* right;

    // Constructor: initializes node with given value
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
//   Inserts a value into the BST following BST properties.
//
// LOGIC:
//   • If tree is empty → create new node
//   • If value < root->data → insert in left subtree
//   • Else → insert in right subtree
//
// TIME COMPLEXITY:
//   • Average: O(log n)
//   • Worst: O(n) (skewed tree)
// ======================================================================
Node* insertIntoBST(Node* root, int data) {

    // Base case: empty tree
    if (root == NULL) {
        root = new Node(data);
        return root;
    }

    // Decide correct subtree
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
//   Reads input from user and builds the BST.
//
// INPUT FORMAT:
//   • Enter numbers
//   • -1 indicates end of input
//
// NOTE:
//   • root is passed by reference so changes persist
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
//   Prints the tree level by level (Breadth First Traversal)
//
// APPROACH:
//   • Queue is used
//   • NULL marker separates each level
//
// TIME COMPLEXITY: O(n)
// SPACE COMPLEXITY: O(n)
// ======================================================================
void levelOrderTraversal(Node* root) {

    queue<Node*> q;

    // Push root and level separator
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
// FUNCTION: preOrderTraversal()
// ----------------------------------------------------------------------
// ORDER: N → L → R
// Used to copy tree or evaluate expressions
// ======================================================================
void preOrderTraversal(Node* root) {
    if (root == NULL)
        return;

    cout << root->data << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

// ======================================================================
// FUNCTION: inOrderTraversal()
// ----------------------------------------------------------------------
// ORDER: L → N → R
// IMPORTANT:
//   • Inorder traversal of BST looks SORTED
// ======================================================================
void inOrderTraversal(Node* root) {
    if (root == NULL)
        return;

    inOrderTraversal(root->left);
    cout << root->data << " ";
    inOrderTraversal(root->right);
}

// ======================================================================
// FUNCTION: postOrderTraversal()
// ----------------------------------------------------------------------
// ORDER: L → R → N
// Used to delete tree or evaluate postfix expressions
// ======================================================================
void postOrderTraversal(Node* root) {
    if (root == NULL)
        return;

    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->data << " ";
}

// ======================================================================
// MAIN FUNCTION
// ----------------------------------------------------------------------
// 1️⃣ Build BST using user input
// 2️⃣ Print tree level-wise
// 3️⃣ Print all DFS traversals
// ======================================================================
int main() {

    Node* root = NULL;

    cout << "Enter the data for Node" << endl;
    takeInput(root);

    cout << "Printing the tree: " << endl;
    levelOrderTraversal(root);
    cout << endl;

    cout << "Printing Inorder: " << endl;
    inOrderTraversal(root);
    cout << endl;

    cout << "Printing Preorder: " << endl;
    preOrderTraversal(root);
    cout << endl;

    cout << "Printing Postorder: " << endl;
    postOrderTraversal(root);
    cout << endl;

    return 0;
}
