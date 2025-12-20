class NodeData {
    public:
        int size;
        int minVal;
        int maxVal;
        bool validBST;

        NodeData() {

        }

        NodeData(int size, int max, int min, bool valid) {
            this -> size = size;
            minVal = min;
            maxVal = max;
            validBST = valid;
        }
};

NodeData findLargestBST(Node* root, int &ans) {
    //Base case
    if(root == NULL) {
        NodeData temp( 0, INT_MAX, INT_MIN, true);
        return temp;
    }

    NodeData leftKaAns = findLargestBST(root -> left, ans);
    NodeData rightKaAns = findLargestBST(root -> right, ans);

    //Checking starts here
    NodeData currNodeKaAns;

    currNodeKaAns.size = leftKaAns.size + rightKaAns.size + 1;
    currNodeKaAns.maxVal = max(root -> data, rightKaAns.maxVal);
    currNodeKaAns.minVal = min(root -> data, leftKaAns.minVal);

    if(leftKaAns.validBST && rightKaAns.validBST && (root -> data > leftKaAns.maxVal && root -> data < rightKaAns.minVal)) {
        currNodeKaAns.validBST = true;
    }
    else {
        currNodeKaAns.validBST = false;
    }

    if(currNodeKaAns.validBST) {
        ans = max(ans, currNodeKaAns.size);
    }

    return currNodeKaAns;
}

int main() {

    Node* root = new Node(5);
    Node* fist = new Node(2);
    Node* second = new Node(4);
    Node* third = new Node(1);
    Node* fourth = new Node(3);

    root -> left = first;
    root -> right = third;
    first -> left = third;
    first -> right = fourth;

    cout << "Printing the tree " << endl;
    levelOrderTraversal(root);

    int ans = 0;
    findLargestBST(root, ans);
    cout << "Largest BSK ka size : " << ans << endl;
}