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

int minVal(Node* root) {
    Node* temp = root;
    if(temp == NULL) {
        return -1;
    }

    while(temp -> left != NULL) {
        temp = temp -> left;
    }
    return temp -> data;
}

int maxVal(Node* root) {
    Node* temp = root;
    if(temp == NULL) {
        return -1;
    }

    while(temp -> right != NULL) {
        temp = temp -> right;
    }
    return temp -> data;
}

int main() {
    Node* root = NULL;
    cout << "Enter the data for Node" << endl;
    takeInput(root);
    cout << "Printing the tree: " << endl;
    levelOrderTraversal(root); 
    cout << endl;

    cout << "Minimum value: " << minVal(root) << endl;

    cout << "Maximum value: " << maxVal(root) << endl;
 
    return 0;
}