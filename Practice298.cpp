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

void printRightView(Node* root, vector<int> &ans, int level) {

    //Base case
    if(root == NULL)
        return;

    if(level == ans.size()) {
        ans.push_back(root -> data);
    }

    //Right
    printRightView(root -> right, ans, level + 1);

    //Left
    printRightView(root -> left, ans, level + 1);

}

int main() {

    Node* root = buildTree();
    vector<int> ans;
    int level = 0;
    printRightView(root, ans, level);

    cout << "Printing the right view: " << endl;
    for(auto i : ans) {
        cout << i << " ";
    }

    return 0;
}