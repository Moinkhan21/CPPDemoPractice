#include <iostream>
#include <queue>
using namespace std;

// ===============================
// Node Definition
// ===============================
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

// ===============================
// Build BST from Inorder Array
// ===============================
Node* bstUsingInorder(int inorder[], int s, int e) {
    if (s > e)
        return NULL;

    int mid = (s + e) / 2;
    Node* root = new Node(inorder[mid]);

    root->left = bstUsingInorder(inorder, s, mid - 1);
    root->right = bstUsingInorder(inorder, mid + 1, e);

    return root;
}

// ===============================
// Level Order Traversal
// ===============================
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

// ===============================
// Convert BST → Sorted DLL
// (Reverse Inorder Traversal)
// ===============================
void convertIntoSortedDLL(Node* root, Node*& head) {
    if (root == NULL)
        return;

    convertIntoSortedDLL(root->right, head);

    root->right = head;
    if (head)
        head->left = root;

    head = root;

    convertIntoSortedDLL(root->left, head);
}

// ===============================
// Print Doubly Linked List
// ===============================
void printLinkedList(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->right;
    }
    cout << endl;
}

// ===============================
// Convert Sorted DLL → Balanced BST
// ===============================
Node* sortedLinkedListIntoBST(Node*& head, int n) {

    // Base case
    if (n <= 0 || head == NULL)
        return NULL;

    // Left subtree
    Node* leftSubtree = sortedLinkedListIntoBST(head, n / 2);

    // Root
    Node* root = head;
    root->left = leftSubtree;

    // Move head forward
    head = head->right;

    // Right subtree
    root->right = sortedLinkedListIntoBST(head, n - 1 - n / 2);

    return root;
}

// ===============================
// MAIN
// ===============================
int main() {

    int inorder[] = {1,2,3,4,5,6,7,8,9};
    int n = sizeof(inorder) / sizeof(inorder[0]);

    // Step 1: Array → BST
    Node* root = bstUsingInorder(inorder, 0, n - 1);
    cout << "Level Order Traversal of BST:\n";
    levelOrderTraversal(root);

    // Step 2: BST → Sorted DLL
    Node* head = NULL;
    convertIntoSortedDLL(root, head);

    cout << "Sorted Doubly Linked List:\n";
    printLinkedList(head);

    // Step 3: DLL → Balanced BST
    Node* root1 = sortedLinkedListIntoBST(head, n);

    cout << "Level Order Traversal after DLL → BST:\n";
    levelOrderTraversal(root1);

    return 0;
}
