#include <iostream>
#include <queue>
using namespace std;

// ======================================================================
// CLASS: Node
// ----------------------------------------------------------------------
// Represents a node in the binary tree.  
// Each node stores:
//     • data  → integer value  
//     • left  → pointer to left child  
//     • right → pointer to right child  
// ======================================================================
class Node {
public:
    int data;
    Node* left;
    Node* right;

    // Constructor → initializes node with given value, children as NULL
    Node(int data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

// ======================================================================
// FUNCTION: buildTree()
// ----------------------------------------------------------------------
// PURPOSE:
//   Builds a binary tree using recursive PREORDER input method.
//
// INPUT RULE:
//   • Enter any integer as node value  
//   • Enter -1 to indicate "no node" (NULL pointer)
//
// PROCESS FLOW (PREORDER):
//   Step A: Read data for current node  
//   Step B: Recursively build left subtree  
//   Step C: Recursively build right subtree  
//
// RETURNS:
//   Pointer to the constructed root node.
// ======================================================================
Node* buildTree() {
    int data;
    cout << "Enter the data: " << endl;
    cin >> data;

    // Base case: -1 means the node doesn't exist
    if (data == -1) {
        return NULL;
    }

    // Step A → Create the node
    Node* root = new Node(data);

    // Step B → Build left subtree
    cout << "Enter data for left part of " << data << " node " << endl;
    root->left = buildTree();

    // Step C → Build right subtree
    cout << "Enter data for right part of " << data << " node " << endl;
    root->right = buildTree();

    return root;
}

// ======================================================================
// FUNCTION: levelOrderTraversal()
// ----------------------------------------------------------------------
// PURPOSE:
//   Prints the binary tree level-by-level (BFS traversal).
//
// TECHNIQUE:
//   Uses a queue and a NULL marker to separate levels.
//
// WORKING:
//   • Push root, then push NULL (acts as level separator).
//   • Pop elements from queue one-by-one:
//        - If element is NULL → end of current level → print newline  
//        - If element is a node → print its data → push its children  
//   • When encountering NULL and queue is not empty → push another NULL  
//
// OUTPUT FORMAT:
//   Each tree level appears on a new line.
// ======================================================================
void levelOrderTraversal(Node* root) {
    queue<Node*> q;

    // Initially push root node and a NULL level marker
    q.push(root);
    q.push(NULL);

    while (!q.empty()) {

        // Step A → Get front element
        Node* temp = q.front();

        // Step B → Remove it from the queue
        q.pop();

        if (temp == NULL) {
            // End of current level
            cout << endl;

            // If queue still has elements, insert new level marker
            if (!q.empty()) {
                q.push(NULL);
            }
        }
        else {
            // Step C → Print node data
            cout << temp->data << " ";

            // Step D → Push left child if exists
            if (temp->left) {
                q.push(temp->left);
            }

            // Push right child if exists
            if (temp->right) {
                q.push(temp->right);
            }
        }
    }
}

// ======================================================================
// FUNCTION: height()
// ----------------------------------------------------------------------
// PURPOSE:
//   Computes the height of the binary tree.
//
// HEIGHT DEFINITION:
//   Number of nodes in the longest path from root → leaf.
//   (Height of NULL node = 0)
//
// RECURSIVE RELATION:
//   height = max(height(left), height(right)) + 1
//
// TIME COMPLEXITY: O(n)
//   Every node is visited once.
// ======================================================================
int height(Node* root) {
    if (root == NULL)
        return 0;

    int leftHeight = height(root->left);     // Height of left subtree
    int rightHeight = height(root->right);   // Height of right subtree

    int ans = max(leftHeight, rightHeight) + 1;  // Height of current node
    return ans;
}

// ======================================================================
// MAIN FUNCTION
// ----------------------------------------------------------------------
// Builds a tree using recursive input, prints its level order traversal,
// and prints the height of the tree.
// ======================================================================
int main() {
    Node* root = NULL;

    // Build tree
    root = buildTree();

    // Print BFS traversal level-wise
    levelOrderTraversal(root);

    // Print height of tree
    cout << "Height: " << height(root) << endl;

    return 0;
}
