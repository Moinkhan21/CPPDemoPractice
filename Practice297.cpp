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

void printLeftTree(Node* root, vector<int> &ans, int level) {

    //Base case
    if(root == NULL)
        return;

    if(level == ans.size()) {
        ans.push_back(root -> data);
    }

    //Left
    printLeftTree(root -> left, ans, level + 1);

    //Right
    printLeftTree(root -> right, ans, level + 1);

}

int main() {

    Node* root = buildTree();
    vector<int> ans;
    int level = 0;
    printLeftTree(root, ans, level);

    cout << "Printing the Left view: " << endl;
    for(auto i : ans) {
        cout << i << " ";
    }

    return 0;
}