#include <iostream>
#include <queue>
#include <unordered_map>
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

Node* buildTreeFromPostOrderInOrder(int inorder[], int postorder[], int &postIndex, int size, int inorderStart, int inorderEnd, unordered_map<int, int> mapping) {

    //Basecase
    if(postIndex < 0 || inorderStart > inorderEnd) {
        return NULL;
    }

    // Step A
    int element = postorder[postIndex];
    postIndex--;
    Node* root = new Node(element);

    int pos = mapping[element];

    //root -> right solve
    root -> right = buildTreeFromPostOrderInOrder(inorder, postorder, postIndex, size, pos + 1, inorderEnd, mapping);

    //root -> left solve
    root -> left = buildTreeFromPostOrderInOrder(inorder, postorder, postIndex, size, inorderStart, pos - 1, mapping);

    return root;
}

void levelOrderTraversal(Node* root) {
    queue<Node*> q;

    //Initially
    q.push(root);
    q.push(NULL);

    while(!q.empty()) {
        //A
        Node* temp = q.front();

        //B
        q.pop();

        if(temp == NULL) {
            cout << endl;
            if(!q.empty()) {
                q.push(NULL);
            }
        }
        else {
            //C
            cout << temp -> data << " ";
            //D 
            if(temp -> left) {
                q.push(temp -> left);
            }
            if(temp -> right) {
                q.push(temp -> right);
            }
        }
    }
}

void createMapping(unordered_map<int, int> &mapping, int inorder[], int n) {
    for(int i = 0; i < n; i++) {
        mapping[inorder[i]] = i;
    }
}

 int main() {
    
    int inoreder[] = {40, 20, 10, 50, 30, 60};
    int postorder[] = {40, 20, 50, 60, 30, 10};
    int size = 6;
    int postIndex = size - 1;
    int inorederStart = 0;
    int inorderEnd = size - 1;

    unordered_map<int, int> mapping;
    createMapping(mapping, inoreder, size);

    cout << "Building the tree: " << endl;
    Node* root = buildTreeFromPostOrderInOrder(inoreder, postorder, postIndex, size, inorederStart, inorderEnd, mapping);

    cout << "Printing the tree " << endl;
    levelOrderTraversal(root);
 }