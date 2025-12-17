#include <iostream>
#include <queue>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* insertIntoBST(Node* root, int data) {
    if (root == NULL) {
        return new Node(data);
    }

    if (root->data > data) {
        root->left = insertIntoBST(root->left, data);
    } else {
        root->right = insertIntoBST(root->right, data);
    }
    return root;
}

void takeInput(Node*& root) {
    int data;
    cin >> data;

    while (data != -1) {
        root = insertIntoBST(root, data);
        cin >> data;
    }
}

void levelOrderTraversal(Node* root) {
    if (!root) return;

    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if (temp == NULL) {
            cout << endl;
            if (!q.empty())
                q.push(NULL);
        } else {
            cout << temp->data << " ";
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
    }
}

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

int minVal(Node* root) {
    Node* temp = root;
    while (temp && temp->left)
        temp = temp->left;
    return temp ? temp->data : -1;
}

int maxVal(Node* root) {
    Node* temp = root;
    while (temp && temp->right)
        temp = temp->right;
    return temp ? temp->data : -1;
}

Node* deleteNodeInBST(Node* root, int target) {
    if (root == NULL)
        return NULL;

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
    else if (target > root->data) {
        root->right = deleteNodeInBST(root->right, target);
    }
    else {
        root->left = deleteNodeInBST(root->left, target);
    }
    return root;
}

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
