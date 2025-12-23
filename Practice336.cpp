#include <iostream>
#include <vector>
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
// Insert into BST and track successor
// ===============================
Node* insert(Node* root, int val, int &succ) {

    if (!root)
        return new Node(val);

    if (val >= root->data) {
        root->right = insert(root->right, val, succ);
    }
    else {
        succ = root->data;
        root->left = insert(root->left, val, succ);
    }
    return root;
}

// ===============================
// Find Least Greater Element on Right
// ===============================
vector<int> findLeastGreater(vector<int> &arr, int n) {

    vector<int> ans(arr.size());
    Node* root = NULL;

    for (int i = arr.size() - 1; i >= 0; --i) {
        int succ = -1;
        root = insert(root, arr[i], succ);
        ans[i] = succ;
    }
    return ans;
}

// ===============================
// MAIN (Test Case)
// ===============================
int main() {

    /*
        Input:  [8, 58, 71, 18, 31, 32, 63, 92, 43, 3, 91, 93, 25, 80, 28]
        Output: [18, 63, 80, 25, 32, 43, 80, 93, 80, 25, 93, -1, 28, -1, -1]
    */

    vector<int> arr = {8, 58, 71, 18, 31, 32, 63, 92, 43, 3, 91, 93, 25, 80, 28};

    vector<int> ans = findLeastGreater(arr, arr.size());

    cout << "Least Greater Elements:\n";
    for (int x : ans)
        cout << x << " ";
    cout << endl;

    return 0;
}
