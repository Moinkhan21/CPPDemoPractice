#include <iostream>
#include <queue>
using namespace std;

// =====================================================
// CLASS: Node
// -----------------------------------------------------
// Represents a node in a Binary Search Tree (BST)
//
// Each node contains:
//   • data  → value stored in the node
//   • left  → pointer to left child
//   • right → pointer to right child
// =====================================================
class Node {
public:
    int data;
    Node* left;
    Node* right;

    // Constructor
    Node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

// =====================================================
// FUNCTION: insertIntoBST
// -----------------------------------------------------
// PURPOSE:
//   Inserts a new value into the BST following BST rules.
//
// BST PROPERTY:
//   • Left subtree  → values < root
//   • Right subtree → values > root
//
// TIME COMPLEXITY: O(h)
// =====================================================
Node* insertIntoBST(Node* root, int data) {

    // Base case: empty position found
    if (root == NULL) {
        return new Node(data);
    }

    // Insert in left subtree
    if (root->data > data) {
        root->left = insertIntoBST(root->left, data);
    }
    // Insert in right subtree
    else {
        root->right = insertIntoBST(root->right, data);
    }

    return root;
}

// =====================================================
// FUNCTION: takeInput
// -----------------------------------------------------
// PURPOSE:
//   Takes multiple inputs and inserts them into BST.
//   Input stops when user enters -1.
// =====================================================
void takeInput(Node*& root) {
    int data;
    cin >> data;

    while (data != -1) {
        root = insertIntoBST(root, data);
        cin >> data;
    }
}

// =====================================================
// FUNCTION: levelOrderTraversal
// -----------------------------------------------------
// PURPOSE:
//   Prints the BST level-by-level (BFS traversal).
//
// TECHNIQUE:
//   Uses queue + NULL marker to separate levels.
// =====================================================
void levelOrderTraversal(Node* root) {
    if (!root) return;

    queue<Node*> q;
    q.push(root);
    q.push(NULL);   // Level separator

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if (temp == NULL) {
            cout << endl;
            if (!q.empty())
                q.push(NULL);
        }
        else {
            cout << temp->data << " ";

            if (temp->left)
                q.push(temp->left);

            if (temp->right)
                q.push(temp->right);
        }
    }
}

// =====================================================
// FUNCTION: findNodeInBST
// -----------------------------------------------------
// PURPOSE:
//   Searches for a target node in BST.
//
// TIME COMPLEXITY: O(h)
// =====================================================
Node* findNodeInBST(Node* root, int target) {

    if (root == NULL)
        return NULL;

    if (root->data == target)
        return root;

    if (target > root->data)
        return findNodeInBST(root->right, target);
    else
        return findNodeInBST(root->left, target);
}

// =====================================================
// FUNCTION: minVal
// -----------------------------------------------------
// PURPOSE:
//   Finds minimum value in BST.
//   (Leftmost node)
// =====================================================
int minVal(Node* root) {
    Node* temp = root;
    while (temp && temp->left)
        temp = temp->left;

    return temp ? temp->data : -1;
}

// =====================================================
// FUNCTION: maxVal
// -----------------------------------------------------
// PURPOSE:
//   Finds maximum value in BST.
//   (Rightmost node)
// =====================================================
int maxVal(Node* root) {
    Node* temp = root;
    while (temp && temp->right)
        temp = temp->right;

    return temp ? temp->data : -1;
}

// =====================================================
// FUNCTION: deleteNodeInBST
// -----------------------------------------------------
// PURPOSE:
//   Deletes a node from BST while maintaining BST rules.
//
// DELETION CASES:
//   1️⃣ Leaf node
//   2️⃣ Node with only right child
//   3️⃣ Node with only left child
//   4️⃣ Node with two children
//
// STRATEGY FOR CASE 4:
//   • Replace node with inorder predecessor
//   • Delete predecessor recursively
//
// TIME COMPLEXITY: O(h)
// =====================================================
Node* deleteNodeInBST(Node* root, int target) {

    if (root == NULL)
        return NULL;

    // Node found
    if (root->data == target) {

        // Case 1: Leaf node
        if (!root->left && !root->right) {
            delete root;
            return NULL;
        }

        // Case 2: Only right child
        if (!root->left && root->right) {
            Node* child = root->right;
            delete root;
            return child;
        }

        // Case 3: Only left child
        if (root->left && !root->right) {
            Node* child = root->left;
            delete root;
            return child;
        }

        // Case 4: Two children
        int inorderPre = maxVal(root->left);
        root->data = inorderPre;
        root->left = deleteNodeInBST(root->left, inorderPre);
        return root;
    }
    // Search in right subtree
    else if (target > root->data) {
        root->right = deleteNodeInBST(root->right, target);
    }
    // Search in left subtree
    else {
        root->left = deleteNodeInBST(root->left, target);
    }

    return root;
}

// =====================================================
// MAIN FUNCTION
// =====================================================
int main() {

    Node* root = NULL;

    cout << "Enter the data for Node (-1 to stop):" << endl;
    takeInput(root);

    cout << "\nPrinting the tree:" << endl;
    levelOrderTraversal(root);

    cout << "\n\nDeleting node 20...\n";
    root = deleteNodeInBST(root, 20);

    cout << "\nTree after deletion:" << endl;
    levelOrderTraversal(root);

    return 0;
}
