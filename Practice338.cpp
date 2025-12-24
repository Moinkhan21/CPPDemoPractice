#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// ===============================
// Node Definition
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
// Merge Two BSTs (Inorder)
// ===============================
vector<int> merge(Node* root1, Node* root2) {

    vector<int> ans;
    stack<Node*> sa, sb;

    Node* a = root1;
    Node* b = root2;

    while (a || b || !sa.empty() || !sb.empty()) {

        // Push left nodes of BST1
        while (a) {
            sa.push(a);
            a = a->left;
        }

        // Push left nodes of BST2
        while (b) {
            sb.push(b);
            b = b->left;
        }

        // Choose smaller top
        if (sb.empty() || (!sa.empty() && sa.top()->data <= sb.top()->data)) {
            Node* atop = sa.top();
            sa.pop();
            ans.push_back(atop->data);
            a = atop->right;
        }
        else {
            Node* btop = sb.top();
            sb.pop();
            ans.push_back(btop->data);
            b = btop->right;
        }
    }

    return ans;
}

// ===============================
// MAIN (Test Case)
// ===============================
int main() {

    /*
        BST 1:
            3
           / \
          1   5

        BST 2:
            4
           / \
          2   6

        Merged Output:
        1 2 3 4 5 6
    */

    Node* root1 = new Node(3);
    root1->left = new Node(1);
    root1->right = new Node(5);

    Node* root2 = new Node(4);
    root2->left = new Node(2);
    root2->right = new Node(6);

    vector<int> result = merge(root1, root2);

    cout << "Merged BST elements:\n";
    for (int x : result)
        cout << x << " ";
    cout << endl;

    return 0;
}
