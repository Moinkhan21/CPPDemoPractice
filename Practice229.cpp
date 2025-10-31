#include <iostream>
using namespace std;

// Definition for singly-linked list node
class ListNode {
public:
    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = NULL;
    }
};

// Function to get the length of the linked list
int getLength(ListNode* head){
    int len = 0;
    while(head) {
        ++len;
        head = head -> next;
    }
    return len;
}

ListNode* rotateRight(ListNode* head, int k) {
    if(!head) return 0; // Empty list
    if(!head->next) return head; // Only one node

    int len = getLength(head);
    
    int actualRotateK = k % len;  // Avoid unnecessary rotations
    if(actualRotateK == 0) return head; // No rotation needed

    // Find the (len - k - 1)th node (new last node after rotation)
    int newLastNodePos = len - actualRotateK - 1;
    ListNode* newLastNode = head;
    
    for(int i = 0; i < newLastNodePos; i++) {
        newLastNode = newLastNode -> next;
    }

    // New head will be next of new last node
    ListNode* newHead = newLastNode -> next;
    newLastNode -> next = NULL;

    // Traverse to the end of new head and link old head
    ListNode* it = newHead;
    while(it -> next) {
        it = it -> next;
    }
    it -> next = head;

    return newHead;
}

// Function to print linked list
void printList(ListNode* head) {
    while(head) {
        cout << head->val << " ";
        head = head -> next;
    }
    cout << endl;
}

int main() {
    // Create LL: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    cout << "Original List: ";
    printList(head);

    int k = 2;
    head = rotateRight(head, k);

    cout << "Rotated List by " << k << ": ";
    printList(head);

    return 0;
}
