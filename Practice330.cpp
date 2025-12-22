#include <iostream>
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
// Count Pairs from Two BSTs
// ===============================
int countPairs(Node* root1, Node* root2, int x) {

    int ans = 0;
    stack<Node*> s1, s2;

    Node* a = root1;
    Node* b = root2;

    while (true) {

        // Inorder traversal for BST1
        while (a) {
            s1.push(a);
            a = a->left;
        }

        // Reverse inorder traversal for BST2
        while (b) {
            s2.push(b);
            b = b->right;
        }

        if (s1.empty() || s2.empty())
            break;

        Node* atop = s1.top();
        Node* btop = s2.top();

        int sum = atop->data + btop->data;

        if (sum == x) {
            ++ans;
            s1.pop();
            s2.pop();
            a = atop->right;
            b = btop->left;
        }
        else if (sum < x) {
            s1.pop();
            a = atop->right;
        }
        else {
            s2.pop();
            b = btop->left;
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
            5
           / \
          3   7
         / \
        2   4

        BST 2:
            10
           /  \
          6    15
         / \     \
        3   8     18

        Target Sum = 11
        Valid pairs:
        (5,6), (3,8)
        Answer = 2
    */

    Node* root1 = new Node(5);
    root1->left = new Node(3);
    root1->right = new Node(7);
    root1->left->left = new Node(2);
    root1->left->right = new Node(4);

    Node* root2 = new Node(10);
    root2->left = new Node(6);
    root2->right = new Node(15);
    root2->left->left = new Node(3);
    root2->left->right = new Node(8);
    root2->right->right = new Node(18);

    int x = 11;

    cout << "Number of pairs = "
         << countPairs(root1, root2, x) << endl;

    return 0;
}
