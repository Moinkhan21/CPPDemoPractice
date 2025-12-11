#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// ===============================
// Node Structure
// ===============================
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

// ===============================
// DIAGONAL TRAVERSAL FUNCTION
// ===============================
vector<int> diagonal(Node* root) {

    vector<int> ans;
    if (!root) return ans;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        // Traverse all right nodes in the current diagonal
        while (temp) {
            ans.push_back(temp->data);

            // Left child will be part of next diagonal
            if (temp->left)
                q.push(temp->left);

            temp = temp->right;
        }
    }
    return ans;
}

// ===============================
// MAIN FUNCTION (Test Example)
// ===============================
int main() {

    /*
            8
           / \
          3   10
         / \    \
        1   6    14
           / \   /
          4   7 13

    Diagonal Traversal Output:
    [8, 10, 14, 3, 6, 7, 13, 1, 4]
    */

    Node* root = new Node(8);
    root->left = new Node(3);
    root->right = new Node(10);
    root->left->left = new Node(1);
    root->left->right = new Node(6);
    root->left->right->left = new Node(4);
    root->left->right->right = new Node(7);
    root->right->right = new Node(14);
    root->right->right->left = new Node(13);

    vector<int> result = diagonal(root);
    
    cout << "Diagonal Traversal: ";
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
