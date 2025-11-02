#include <iostream>
using namespace std;

class ListNode {
public:
    int data;
    ListNode* next;

    // Constructor to initialize node with value
    ListNode(int val) {
        data = val;
        next = NULL;
    }
};

// ✅ Function to find middle node of linked list
// Uses Fast & Slow pointer technique
ListNode* findMid(ListNode* head) {
    ListNode* slow = head;        // moves 1 step
    ListNode* fast = head->next;  // moves 2 steps

    /*
        Fast pointer moves twice as fast as slow.
        When fast reaches end, slow will be at middle.
        We return slow, which will be end of left half.
    */
    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow; // mid node
}

// ✅ Merge two sorted linked lists
ListNode* merge(ListNode* left, ListNode* right) {

    // If any list is empty, return the other
    if(left == NULL) return right;
    if(right == NULL) return left;

    ListNode* ans = new ListNode(-1);  // Dummy node to start merged list
    ListNode* mptr = ans;              // Pointer to build result list

    /*
        Compare nodes from both lists and attach smaller one
        Continue until one list becomes empty
    */
    while(left && right) {
        if(left->data <= right->data) {
            mptr->next = left;
            mptr = left;
            left = left->next;
        }
        else {
            mptr->next = right;
            mptr = right;
            right = right->next;
        }
    }

    // If nodes remain in left list, append them
    while(left != NULL) {
        mptr->next = left;
        mptr = left;
        left = left->next;
    }

    // If nodes remain in right list, append them
    while(right != NULL) {
        mptr->next = right;
        mptr = right;
        right = right->next;
    }

    return ans->next; // Skip dummy and return actual head
}

// ✅ Recursive Merge Sort on Linked List
ListNode* sortList(ListNode* head) {

    // Base condition: if list empty OR only one node -> already sorted
    if(head == NULL || head->next == NULL) {
        return head;
    }

    // Break LL into two halves
    ListNode* mid = findMid(head);
    ListNode* left = head;         // Left half starts at head
    ListNode* right = mid->next;   // Right half after middle
    mid->next = NULL;              // Break the list into two parts

    // Recursively sort both halves
    left = sortList(left);
    right = sortList(right);

    // Merge the two sorted halves
    return merge(left, right);
}

// ✅ Utility function to print linked list
void printList(ListNode* head) {
    while(head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Creating unsorted list: 4 -> 2 -> 1 -> 3
    ListNode* head = new ListNode(4);
    head->next = new ListNode(2);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(3);

    cout << "Original List: ";
    printList(head);

    // ✅ Call merge sort on Linked List
    head = sortList(head);

    cout << "Sorted List: ";
    printList(head);

    return 0;
}
