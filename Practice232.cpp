#include <iostream>
using namespace std;

// ===============================
// ✅ Definition for singly-linked list node
// ===============================
class ListNode {
public:
    int val;          // Value of the node
    ListNode* next;   // Pointer to the next node

    // Constructor to initialize node with value
    ListNode(int x) {
        val = x;
        next = NULL;
    }
};

// ===============================
// ✅ Function: mergeNodes
// Given a linked list where nodes between 0s need to be merged,
// this function modifies nodes in place such that each block
// between two zeroes becomes a single node with sum of values.
// ===============================
ListNode* mergeNodes(ListNode* head) {
    if(!head) return 0; // If list is empty, return null

    ListNode* slow = head;          // Slow pointer: writes merged values
    ListNode* fast = head->next;    // Fast pointer: reads ahead
    ListNode* newLastNode = 0;      // Points to last valid merged node
    int sum = 0;                    // Stores sum between two zeroes

    // Traverse list using fast pointer
    while(fast) {
        if(fast->val != 0) {
            sum += fast->val;       // Add values until we meet zero
        } 
        else {
            // When zero encountered, write sum at slow node
            slow->val = sum;
            newLastNode = slow;     // Track last processed node
            slow = slow->next;      // Move slow forward to prepare next result
            sum = 0;                // Reset sum for next block
        }
        fast = fast->next;          // Move fast ahead
    }

    // Delete leftover unused nodes after last merged node
    ListNode* temp = slow;
    newLastNode->next = NULL;  // Final new tail of modified list

    while(temp) {
        ListNode* nxt = temp->next;
        delete temp;
        temp = nxt;
    }

    return head; // Return modified list head
}

// ===============================
// ✅ Utility Function to Print Linked List
// ===============================
void printList(ListNode* head) {
    while(head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

// ===============================
// ✅ Main Function — Test mergeNodes()
// Input: 0 → 3 → 1 → 0 → 4 → 5 → 2 → 0
// Output: 4 → 11
// ===============================
int main() {
    // Creating linked list: 0 -> 3 -> 1 -> 0 -> 4 -> 5 -> 2 -> 0
    ListNode* head = new ListNode(0);
    head->next = new ListNode(3);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(0);
    head->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next->next = new ListNode(2);
    head->next->next->next->next->next->next->next = new ListNode(0);

    cout << "Original List: 0 3 1 0 4 5 2 0" << endl;
    
    // Call mergeNodes function
    ListNode* result = mergeNodes(head);

    cout << "Merged List: ";
    printList(result);   // Expected Output: 4 11

    return 0;
}
