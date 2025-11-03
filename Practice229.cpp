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
// Iterates through list and counts number of nodes
int getLength(ListNode* head){
    int len = 0;
    while(head) {
        ++len;                // Increase count
        head = head -> next;  // Move to next node
    }
    return len;               // Return total length
}

ListNode* rotateRight(ListNode* head, int k) {
    if(!head) return 0;          // Empty list, no rotation
    if(!head->next) return head; // Only one node, no rotation needed

    // Step 1: Find length of linked list
    int len = getLength(head);
    
    // Step 2: Reduce k to within list range
    int actualRotateK = k % len;  // If k >= len, only k % len rotations matter
    if(actualRotateK == 0) return head; // No rotation needed if k is multiple of len

    // Step 3: Determine the position of new last node after rotation
    // New last node will be (len - k - 1)th position (0-based indexing)
    int newLastNodePos = len - actualRotateK - 1;
    ListNode* newLastNode = head;
    
    // Move pointer to new last node
    for(int i = 0; i < newLastNodePos; i++) {
        newLastNode = newLastNode -> next;
    }

    // Step 4: New head becomes next node after new last node
    ListNode* newHead = newLastNode -> next;
    newLastNode -> next = NULL; // Break list here

    // Step 5: Attach original head at end of rotated part
    ListNode* it = newHead;
    while(it -> next) {          // Move to the end of rotated part
        it = it -> next;
    }
    it -> next = head;           // Connect end to original head

    return newHead;              // Return new start of list
}

// Function to print linked list
// Prints all elements until NULL
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

    // Rotate list by k positions
    int k = 2;
    head = rotateRight(head, k);

    cout << "Rotated List by " << k << ": ";
    printList(head);

    return 0;
}
