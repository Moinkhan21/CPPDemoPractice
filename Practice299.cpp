#include <iostream>
#include <map>
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

Node* buildTree() {
    int data;
    cout << "Enter data: ";
    cin >> data;

    if (data == -1)
        return NULL;

    Node* root = new Node(data);

    cout << "Enter LEFT child of " << data << endl;
    root->left = buildTree();

    cout << "Enter RIGHT child of " << data << endl;
    root->right = buildTree();

    return root;
}

void printRightBoundary(Node* root) {
    //Base case
    if(root == NULL)
        return;
    if(root -> left == NULL && root -> right == NULL)
        return;
    
    if(root -> right) {
        printRightBoundary(root -> right);
    }
    else {
        printRightBoundary(root -> left);
    }

    cout << root -> data << " ";
}

void printLeafBoundary(Node* root) {
    //Base case
    if(root == NULL)
        return;

    if(root -> left == NULL && root -> right == NULL) {
        cout << root -> data << " ";
    }
    printLeafBoundary(root -> left);
    printLeafBoundary(root -> right);
}

void printLeftBoundary(Node* root) {

    //Base case
    //If root is Null,then go back
    if(root == NULL)
        return;

    //If root is a leaf node, then go back
    if(root -> left == NULL && root -> right == NULL)
        return;

    cout << root -> data << " ";
    if(root -> left) {
        printLeftBoundary(root -> left);
    }
    else {
        printLeftBoundary(root -> right);
    }

}

void boundaryTraversal(Node* root) {
    if(root == NULL)
        return;

    cout << root -> data << " ";

    //A
    printLeftBoundary(root -> left);

    //B
    printLeafBoundary(root);

    //C
    printRightBoundary(root -> right);
}

int main() {

    Node* root = buildTree();
    boundaryTraversal(root);
    
    return 0;
}