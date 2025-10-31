#include <iostream>
#include <unordered_map>
using namespace std;

// Node structure for linked list with random pointer
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

Node* helper(Node* head, unordered_map<Node*, Node*>& mp) {
    if(head == NULL) return NULL;

    Node* newHead = new Node(head->val);
    mp[head] = newHead;

    newHead->next = helper(head->next, mp);

    if(head->random)
        newHead->random = mp[head->random];

    return newHead;
}

Node* copyRandomList(Node* head) {
    unordered_map<Node*, Node*> mp;  // original -> cloned node map
    return helper(head, mp);
}

// Utility to print list (val + random val)
void printList(Node* head) {
    Node* temp = head;
    while(temp) {
        cout << "Node: " << temp->val;
        if(temp->random)
            cout << ", Random: " << temp->random->val;
        else
            cout << ", Random: NULL";
        cout << endl;
        temp = temp->next;
    }
}

// Driver code
int main() {
    // Creating list: 1 -> 2 -> 3
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);

    // Setting random pointers:
    head->random = head->next;               // 1 -> 2
    head->next->random = head->next->next;   // 2 -> 3
    head->next->next->random = head;         // 3 -> 1

    cout << "Original List:\n";
    printList(head);

    Node* clone = copyRandomList(head);

    cout << "\nCloned List:\n";
    printList(clone);

    return 0;
}
