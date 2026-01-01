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
//   • If tree is empty → create new node
//   • If data < root->data → insert in left subtree
//   • Else → insert in right subtree
//
// TIME COMPLEXITY:
//   • Average: O(log n)
//   • Worst: O(n) (skewed BST)
// ======================================================================
Node* insertIntoBST(Node* root, int data) {

    // Base case: create first node
    if (root == NULL) {
        root = new Node(data);
        return root;
    }

    // Insert into left or right subtree
    if (root->data > data) {
        root->left = insertIntoBST(root->left, data);
    }
    else {
        root->right = insertIntoBST(root->right, data);
    }

    return root;
}

// ======================================================================
// FUNCTION: takeInput()
// ----------------------------------------------------------------------
// PURPOSE:
//   Takes input from user and inserts values into BST.
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
    q.push(NULL);   // Level separator

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
            // Print current node
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
// FUNCTION: minVal()
// ----------------------------------------------------------------------
// PURPOSE:
//   Finds the MINIMUM value in a BST.
//
// LOGIC:
//   • Minimum value lies in the LEFTMOST node
//
// TIME COMPLEXITY: O(h)
// ======================================================================
int minVal(Node* root) {

    Node* temp = root;

    // Empty tree
    if (temp == NULL) {
        return -1;
    }

    // Move to leftmost node
    while (temp->left != NULL) {
        temp = temp->left;
    }

    return temp->data;
}

// ======================================================================
// FUNCTION: maxVal()
// ----------------------------------------------------------------------
// PURPOSE:
//   Finds the MAXIMUM value in a BST.
//
// LOGIC:
//   • Maximum value lies in the RIGHTMOST node
//
// TIME COMPLEXITY: O(h)
// ======================================================================
int maxVal(Node* root) {

    Node* temp = root;

    // Empty tree
    if (temp == NULL) {
        return -1;
    }

    // Move to rightmost node
    while (temp->right != NULL) {
        temp = temp->right;
    }

    return temp->data;
}

// ======================================================================
// MAIN FUNCTION
// ----------------------------------------------------------------------
// 1️⃣ Takes input to build BST
// 2️⃣ Prints BST using level order traversal
// 3️⃣ Prints minimum and maximum value in BST
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

    cout << "Minimum value: " << minVal(root) << endl;
    cout << "Maximum value: " << maxVal(root) << endl;

    return 0;
}
