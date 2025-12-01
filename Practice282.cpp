#include <iostream>
#include <queue>
using namespace std;

class Node{
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

Node* buildTree() {
    int data;
    cout << "Enter the data: " << endl;
    cin >> data;

    if(data == -1) {
        return NULL;
    }

    //Step A, B and C
    Node* root = new Node(data);

    cout << "Enter data for left part of " << data << " node " << endl;
    root -> left = buildTree();

    cout << "Enter data for right part of " << data << " node " << endl;
    root -> right = buildTree();

    return root;
}

void levelOrderTraversal(Node* root) {
    queue<Node*> q;

    //Initially
    q.push(root);
    q.push(NULL); // Marker for end of level

    while(!q.empty()) {
        //Step A 
        Node* temp = q.front();

        //Step B
        q.pop();


        if(temp == NULL) {
            cout << endl;
            if(!q.empty()) {
                q.push(NULL);
            }
        }
        else {
            
            //Step C
            cout << temp -> data << " ";

            //Step D
            if(temp -> left) {
                q.push(temp -> left);
            }

            if(temp -> right) {
                q.push(temp -> right);
            }
        }

        
    }
} 

int main() {
    Node* root = NULL;
    root = buildTree();
    levelOrderTraversal(root);
    return 0;
}