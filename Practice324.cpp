#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// ===============================
// TreeNode Definition
// ===============================
class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) {
        this->val = val;
        left = NULL;
        right = NULL;
    }
};

// ===============================
// Build BST from Inorder
// ===============================
TreeNode* bstUsingInorder(int inorder[], int s, int e) {
    if (s > e)
        return NULL;

    int mid = (s + e) / 2;
    TreeNode* root = new TreeNode(inorder[mid]);

    root->left = bstUsingInorder(inorder, s, mid - 1);
    root->right = bstUsingInorder(inorder, mid + 1, e);

    return root;
}

// ===============================
// Level Order Traversal
// ===============================
void levelOrderTraversal(TreeNode* root) {
    if (!root) return;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* temp = q.front();
        q.pop();

        cout << temp->val << " ";

        if (temp->left) q.push(temp->left);
        if (temp->right) q.push(temp->right);
    }
}

// ===============================
// Convert BST → Sorted DLL
// ===============================
void convertIntoSortedDLL(TreeNode* root, TreeNode* &head) {
    if (root == NULL)
        return;

    // Right subtree
    convertIntoSortedDLL(root->right, head);

    // Attach root
    root->right = head;
    if (head)
        head->left = root;

    head = root;

    // Left subtree
    convertIntoSortedDLL(root->left, head);
}

// ===============================
// Print Doubly Linked List
// ===============================
void printLinkedList(TreeNode* head) {
    TreeNode* temp = head;
    while (temp) {
        cout << temp->val << " ";
        temp = temp->right;
    }
    cout << endl;
}

// ===============================
// MAIN
// ===============================
int main() {

    int inorder[] = {1,2,3,4,5,6,7,8,9};
    int n = sizeof(inorder) / sizeof(inorder[0]);

    TreeNode* root = bstUsingInorder(inorder, 0, n - 1);

    cout << "Level Order Traversal of BST:\n";
    levelOrderTraversal(root);
    cout << endl;

    TreeNode* head = NULL;
    convertIntoSortedDLL(root, head);

    cout << "Sorted Doubly Linked List:\n";
    printLinkedList(head);

    return 0;
}
