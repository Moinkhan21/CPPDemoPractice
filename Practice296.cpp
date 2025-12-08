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

void printTopView(Node* root) {
    if (root == NULL)
        return;

    // Map: horizontal distance → node value
    map<int, int> topNode;

    // Queue for BFS: Node + HD
    queue<pair<Node*, int>> q;
    q.push({root, 0});

    while (!q.empty()) {
        auto temp = q.front();
        q.pop();

        Node* frontNode = temp.first;
        int hd = temp.second;

        topNode[hd] = frontNode->data;
        
        // Traverse left subtree
        if (frontNode->left) {
            q.push({frontNode->left, hd - 1});
        }

        // Traverse right subtree
        if (frontNode->right) {
            q.push({frontNode->right, hd + 1});
        }
    }

    // Printing the answer
    cout << "\nTop View of Tree:\n";
    for (auto &i : topNode) {
        cout << i.second << " ";
    }
    cout << endl;
}

int main() {
    cout << "Build Binary Tree (-1 for NULL):\n";
    Node* root = buildTree();

    printTopView(root);

    return 0;
}
