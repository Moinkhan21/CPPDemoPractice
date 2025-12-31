#include <iostream>
#include <queue>
#include <climits>
#include <algorithm>
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

    // Constructor initializes node with given value
    // and sets both children to NULL
    Node(int data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

// ======================================================================
// FUNCTION: levelOrderTraversal()
// ----------------------------------------------------------------------
// PURPOSE:
//   Prints the tree in LEVEL ORDER (BFS).
//
// USE CASE:
//   • Helps visualize the tree structure
//
// TIME COMPLEXITY: O(n)
// SPACE COMPLEXITY: O(n)
// ======================================================================
void levelOrderTraversal(Node* root) {
    if (!root) return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        cout << temp->data << " ";

        if (temp->left) q.push(temp->left);
        if (temp->right) q.push(temp->right);
    }
    cout << endl;
}

// ======================================================================
// CLASS: NodeData
// ----------------------------------------------------------------------
// Stores information about a subtree needed to determine
// whether it is a BST.
//
// MEMBERS:
//   • size     → total number of nodes in subtree
//   • minVal   → minimum value in subtree
//   • maxVal   → maximum value in subtree
//   • validBST → whether subtree is a valid BST
// ======================================================================
class NodeData {
public:
    int size;
    int minVal;
    int maxVal;
    bool validBST;

    NodeData() {}

    NodeData(int size, int maxVal, int minVal, bool valid) {
        this->size = size;
        this->minVal = minVal;
        this->maxVal = maxVal;
        this->validBST = valid;
    }
};

// ======================================================================
// FUNCTION: findLargestBST()
// ----------------------------------------------------------------------
// PURPOSE:
//   Finds the size of the LARGEST BST present
//   inside a Binary Tree.
//
// APPROACH (Bottom-Up / Postorder):
//   • Recursively get info from left & right subtrees
//   • Current subtree is BST if:
//       1️⃣ Left subtree is BST
//       2️⃣ Right subtree is BST
//       3️⃣ root->data > left.maxVal
//       4️⃣ root->data < right.minVal
//
// PARAMETERS:
//   • root → current node
//   • ans  → stores maximum BST size found so far
//
// TIME COMPLEXITY: O(n)
// SPACE COMPLEXITY: O(h)
// ======================================================================
NodeData findLargestBST(Node* root, int &ans) {

    // Base case: empty tree is a valid BST
    if (root == NULL) {
        return NodeData(0, INT_MIN, INT_MAX, true);
    }

    // Get information from left and right subtrees
    NodeData leftKaAns = findLargestBST(root->left, ans);
    NodeData rightKaAns = findLargestBST(root->right, ans);

    NodeData currNodeKaAns;

    // --------------------------------------------------
    // Calculate current subtree information
    // --------------------------------------------------
    currNodeKaAns.size =
        leftKaAns.size + rightKaAns.size + 1;

    currNodeKaAns.maxVal =
        max(root->data, rightKaAns.maxVal);

    currNodeKaAns.minVal =
        min(root->data, leftKaAns.minVal);

    // --------------------------------------------------
    // Check if current subtree is a valid BST
    // --------------------------------------------------
    if (leftKaAns.validBST &&
        rightKaAns.validBST &&
        (root->data > leftKaAns.maxVal &&
         root->data < rightKaAns.minVal)) {

        currNodeKaAns.validBST = true;
    }
    else {
        currNodeKaAns.validBST = false;
    }

    // --------------------------------------------------
    // Update answer if current subtree is BST
    // --------------------------------------------------
    if (currNodeKaAns.validBST) {
        ans = max(ans, currNodeKaAns.size);
    }

    return currNodeKaAns;
}

// ======================================================================
// MAIN FUNCTION
// ----------------------------------------------------------------------
// Builds a Binary Tree and finds the size of the
// LARGEST BST present inside it.
//
// TREE STRUCTURE:
//
//            5
//           /
//          2
//         / \
//        1   3
//             \
//              4
//
// LARGEST BST:
//   Subtree rooted at node 2
//   Nodes: 1, 2, 3
//   Size = 3
// ======================================================================
int main() {

    // Constructing the tree
    Node* root = new Node(5);
    Node* first = new Node(2);
    Node* second = new Node(4);
    Node* third = new Node(1);
    Node* fourth = new Node(3);

    root->left = first;
    first->left = third;
    first->right = fourth;
    fourth->right = second;

    cout << "Printing the tree:" << endl;
    levelOrderTraversal(root);

    int ans = 0;
    findLargestBST(root, ans);

    cout << "Largest BST ka size : " << ans << endl;

    return 0;
}
