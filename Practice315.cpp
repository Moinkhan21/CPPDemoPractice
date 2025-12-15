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

Node* insertIntoBST(Node* root, int data) {
    if(root == NULL) {
        //This is the first node we have to create
        root = new Node(data);
        return root;
    }

    //No the first node
    if(root -> data > data) {
        //Insert into left
        root -> left = insertIntoBST(root -> left, data);
    }
    else {
        //Insert into right
        root -> right = insertIntoBST(root -> right, data);
    }

    return root;
}

void takeInput(Node* &root) {
    int data;
    cin >> data;

    while(data != -1) {
        root = insertIntoBST(root, data);
        cin >> data;
    }
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

//Assuming there are only unique values in tree
bool findNodeInBST(Node* root, int target) {
    //Base case
    if(root == NULL) {
        return false;
    }

    if(root -> data == target)
        return true;

    if(target > root -> data) {
        //Right subtree me search karo
        return findNodeInBST(root -> right, target);
    }
    else {
        return findNodeInBST(root -> left, target);
    }
}

int main() {
    Node* root = NULL;
    cout << "Enter the data for Node" << endl;
    takeInput(root);
    cout << "Printing the tree: " << endl;
    levelOrderTraversal(root); 
    cout << endl;

    bool ans = findNodeInBST(root, 15);
    cout << "Present or not : " << ans << endl;
    
    return 0;
}