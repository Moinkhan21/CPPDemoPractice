#include <iostream>
#include <queue>
using namespace std;

class Node {
    public:
        int data;
        Node* left;
        Node* right;

        Node(int data) {
            this -> data = data;
            this -> left = NULL;
            this -> right = NULL;
        }
};

int findPosition(int arr[], int n, int element) {
    for(int i = 0; i < n; i++) {
        if(arr[i] == element) {
            return i;
        }
    }
    return -1;
}

//build tree from inorder and preorder traversal
Node* buildTreeFromPreOrderInOrder(int inorder[], int preorder[], int size, int &preIndex, int inorderStart, int inorderEnd) {

    //Base case
    if(preIndex >= size || inorderStart > inorderEnd) {
        return NULL;
    }

    //Step A:
    int element = preorder[preIndex++];
    Node* root = new Node(element);
    int pos = findPosition(inorder, size, element);

    //Step B: root -> left solve
    root -> left = buildTreeFromPreOrderInOrder(inorder, preorder, size, preIndex, inorderStart, pos - 1);

    //Step C: root -> right solve
    root -> right = buildTreeFromPreOrderInOrder(inorder, preorder, size, preIndex, pos + 1, inorderEnd); 
        
        return root;
}

int main() {

    int inorder[] = {40, 20, 50, 10, 60, 30, 70};
    int preorder[] = {10, 20, 40, 50, 30, 60, 70};
    int size = 7;
    int preIndex = 0;
    int inorderStart = 0;
    int inorderEnd = size - 1;

    cout << "Building tree: " << endl;

    Node* root = buildTreeFromPreOrderInOrder(inorder, preorder, size, preIndex, inorderStart, inorderEnd);

    cout << endl << "Printing level order traversal " << endl;
    levelOrderTaversal(root);

    return 0;
}