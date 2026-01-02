#include <iostream>
#include <unordered_map>
#include <queue>
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

    // Constructor
    Node(int data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

// ======================================================================
// STEP 1: Parent Mapping + Target Node Search
// ----------------------------------------------------------------------
// FUNCTION:
//   makeNodetoParentMappingAndFindTargetNode()
//
// PURPOSE:
//   • Creates a mapping from each node → its parent
//   • Finds and returns the node having value == target
//
// WHY PARENT MAP?
//   • Tree nodes don’t have parent pointers
//   • Fire can spread to left, right AND parent
//
// APPROACH:
//   • Level Order Traversal (BFS)
//   • Store parent for each child
//
// TIME COMPLEXITY: O(n)
// SPACE COMPLEXITY: O(n)
// ======================================================================
Node* makeNodetoParentMappingAndFindTargetNode(
    Node* root,
    unordered_map<Node*, Node*>& parentMap,
    int target
) {
    queue<Node*> q;
    Node* targetNode = NULL;

    // Root has no parent
    q.push(root);
    parentMap[root] = NULL;

    while (!q.empty()) {
        Node* front = q.front();
        q.pop();

        // Check if current node is target
        if (front->data == target) {
            targetNode = front;
        }

        // Process left child
        if (front->left) {
            q.push(front->left);
            parentMap[front->left] = front;
        }

        // Process right child
        if (front->right) {
            q.push(front->right);
            parentMap[front->right] = front;
        }
    }

    return targetNode;
}

// ======================================================================
// STEP 2: Burn the Tree
// ----------------------------------------------------------------------
// FUNCTION:
//   burnTheTree()
//
// PURPOSE:
//   • Simulates burning of the tree starting from target node
//   • Fire spreads to:
//       - left child
//       - right child
//       - parent
//
// LOGIC:
//   • BFS level by level
//   • Each level = 1 unit of time
//   • Increase time only if fire spreads further
//
// DATA STRUCTURES USED:
//   • queue → BFS traversal
//   • isBurnt map → avoid revisiting nodes
//
// TIME COMPLEXITY: O(n)
// SPACE COMPLEXITY: O(n)
// ======================================================================
int burnTheTree(
    Node* targetNode,
    unordered_map<Node*, Node*>& parentMap
) {
    unordered_map<Node*, bool> isBurnt;
    queue<Node*> q;

    int T = 0;

    // Start burning from target node
    q.push(targetNode);
    isBurnt[targetNode] = true;

    while (!q.empty()) {

        int size = q.size();
        bool isFireSpreaded = false;

        // Process all nodes burning at current time
        for (int i = 0; i < size; i++) {

            Node* front = q.front();
            q.pop();

            // Burn left child
            if (front->left && !isBurnt[front->left]) {
                q.push(front->left);
                isBurnt[front->left] = true;
                isFireSpreaded = true;
            }

            // Burn right child
            if (front->right && !isBurnt[front->right]) {
                q.push(front->right);
                isBurnt[front->right] = true;
                isFireSpreaded = true;
            }

            // Burn parent
            if (parentMap[front] && !isBurnt[parentMap[front]]) {
                q.push(parentMap[front]);
                isBurnt[parentMap[front]] = true;
                isFireSpreaded = true;
            }
        }

        // Increase time only if fire spreads further
        if (isFireSpreaded)
            ++T;
    }

    return T;
}

// ======================================================================
// MAIN FUNCTION: minTime()
// ----------------------------------------------------------------------
// PURPOSE:
//   • Coordinates the whole process
//   • Step 1 → Parent mapping + find target
//   • Step 2 → Burn the tree
//
// RETURNS:
//   • Minimum time required to burn the entire tree
// ======================================================================
int minTime(Node* root, int target) {

    unordered_map<Node*, Node*> parentMap;

    // Find target node and build parent mapping
    Node* targetNode =
        makeNodetoParentMappingAndFindTargetNode(root, parentMap, target);

    // Burn the tree starting from target node
    return burnTheTree(targetNode, parentMap);
}

// ======================================================================
// MAIN FUNCTION (Test Case)
// ======================================================================
int main() {

    /*
            1
           / \
          2   3
         / \
        4   5

    Target = 2

    Burning process:
    t = 0 → 2
    t = 1 → 1, 4, 5
    t = 2 → 3

    Answer = 2
    */

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << "Minimum time to burn the tree = "
         << minTime(root, 2) << endl;

    return 0;
}
