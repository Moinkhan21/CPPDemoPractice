#include <iostream>
using namespace std;

class ListNode {
public:
    int data;
    ListNode* next;

    // Constructor to initialize node with value
    ListNode(int val) {
        data = val;
        next = NULL;   // pointer initially set to NULL
    }
};

ListNode* mergeTwoLists(ListNode* left, ListNode* right) {

    // If first list is empty, return second list
    if(left == NULL) return right;

    // If second list is empty, return first list
    if(right == NULL) return left;

    ListNode* ans = new ListNode(-1);  // Dummy node (helps simplify merging logic)
    ListNode* mptr = ans;              // Pointer used to build the merged list

    /* 
       Merge process:
       Compare nodes of both lists and attach the smaller one 
       to the merged list, then move the pointer ahead 
    */
    while(left && right) {
        if(left->data <= right->data) {
            mptr->next = left;      // attach left node if it's smaller
            mptr = left;            // move merged pointer to this node
            left = left->next;      // move left pointer
        }
        else {
            mptr->next = right;     // attach right node if smaller
            mptr = right;           // move merged pointer
            right = right->next;    // move right pointer
        }
    }

    // If any nodes are remaining in left list, append them
    while(left != NULL) {
        mptr->next = left;
        mptr = left;
        left = left->next;
    }

    // If any nodes are remaining in right list, append them
    while(right != NULL) {
        mptr->next = right;
        mptr = right;
        right = right->next;
    }

    // ans->next skips the dummy node and returns actual head
    return ans->next; 
}

// Function to print list (needed for demonstration)
void printList(ListNode* head) {
    while(head != NULL) {
        cout << head->data << " ";  // print current node
        head = head->next;          // move to next node
    }
    cout << endl;
}

int main() {
    // List 1: 1 -> 3 -> 5
    ListNode* left = new ListNode(1);
    left->next = new ListNode(3);
    left->next->next = new ListNode(5);

    // List 2: 2 -> 4 -> 6
    ListNode* right = new ListNode(2);
    right->next = new ListNode(4);
    right->next->next = new ListNode(6);

    // Call merge function
    ListNode* mergedHead = mergeTwoLists(left, right);

    cout << "Merged Linked List: ";
    printList(mergedHead);  // Print final merged list

    return 0;
}
