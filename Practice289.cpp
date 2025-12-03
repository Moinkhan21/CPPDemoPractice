#include <iostream>
using namespace std;

class Node {
    public:
        int data;
        Node* left;
        Node* right;

        Node(int data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
};

// Build tree recursively. Use -1 to indicate NULL.
Node* buildTree() {
    int data;
    cout << "Enter data (-1 for NULL): ";
    cin >> data;

    if (data == -1)
        return NULL;

    Node* root = new Node(data);

    cout << "Enter left child of " << data << endl;
    root->left = buildTree();

    cout << "Enter right child of " << data << endl;
    root->right = buildTree();

    return root;
}


bool kthAncestor(Node* root, int &k, int p) {
    //Base case
    if(root == NULL) 
        return false;
    
    if(root -> data == p) {
        return true;
    }

    bool leftAns = kthAncestor(root -> left, k, p);
    bool rightAns = kthAncestor(root -> right, k, p);

    //Wapas aare honge
    //Check left ya right me answer mila ya nahi
    if(leftAns || rightAns)
        k--;
    if(k == 0) {
        cout << "Answer: " << root -> data << endl;
        k = -1;
    }

    return leftAns || rightAns;
}

int main() {
    Node* root = NULL;
    root = buildTree();

    int k = 1;
    int p = 4;
    bool found = kthAncestor(root, k, p);
}