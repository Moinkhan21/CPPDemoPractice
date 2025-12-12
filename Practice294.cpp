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
            this -> data = data;
            this -> left = NULL;
            this -> right = NULL;
        }
};

Node* buildTree() {
    int data;
    cout << "Enter the data: " << endl;
    cin >> data;

    // BASE CASE: -1 means no node should be created here
    if (data == -1) {
        return NULL;
    }

    // STEP A: Create a new node with given value
    Node* root = new Node(data);

    // STEP B: Build LEFT subtree recursively
    cout << "Enter data for left part of " << data << " node " << endl;
    root->left = buildTree();

    // STEP C: Build RIGHT subtree recursively
    cout << "Enter data for right part of " << data << " node " << endl;
    root->right = buildTree();

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

void printTopView(Node* root) {
    if(root == NULL)
        return;

    //Create a map for storing HD -> TopNode -> data
    map<int, int> topNode;

    //Level order
    //We will store a pair consisting of Node and Horizontal distance
    queue<pair<Node*, int>> q;
    q.push(make_pair(root, 0));

    while(!q.empty()) {
        pair<Node*, int> temp = q.fornt();
        q.pop();

        Node* forntNode = temp.first;
        int hd = temp.second;

        //Jo bhi horizontal distance aaya he, check if answer for that hd already exists or not
        if(topNode.find(hd) == topNode.end()) {
            //Create entry
            topNode[hd] = frontNode -> data;
        }

        if(frontNode -> left) {
            q.push(make_pair(forntNode -> left, hd - 1));
        }

        if(forntNode -> right) {
            q.push(make_pair(frontNode -> right, hd + 1));
        }
    }

    //Ab aapka answer store hua hoga aapke map me
    cout << "Printing the answer: " << endl;
    for(auto i : topNode) {
        cout << i.first << " ->" << i.second << endl;
    }

}

int main() {

    Node* root = buildTree();
    printTopView(root);

    return 0;
}