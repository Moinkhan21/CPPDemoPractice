#include <iostream>
#include <map>
#include <queue>
using namespace std;

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

}

int main() {
    return 0;
}