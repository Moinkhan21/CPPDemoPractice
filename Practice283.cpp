void inorderTraversal(Node* root) {
    //Base case
    if(root == NULL) {
        return;
    }

    //LNR
    inorderTraversal(root -> left);
    cout << root -> data << " ";
    inorderTraversal(root -> right);
}

void preorderTraversal(Node* root) {
    //Base case
    if(root == NULL) {
        return;
    }

    //NLR
    cout << root -> data << " ";
    preorderTraversal(root -> left);
    preorderTraversal(root -> right);
}

void postorderTraversal(Node* root) {
    //Base case
    if(root == NULL) {
        return;
    }

    //LRN    
    postorderTraversal(root -> left);
    postorderTraversal(root -> right);
    cout << root -> data << " ";
}

