#include <iostream>
using namespace std;

class ListNode {
public:
    int data;
    ListNode* next;

    // Constructor initializes node value and sets next pointer to NULL
    ListNode(int x) {
        data = x;
        next = NULL;
    }
};

/*
    Function: getIntersectionNode
    Purpose: Find intersection node of two singly linked lists using iteration
    Logic Used:
        ✔ Two pointers traverse both lists
        ✔ Find which list is longer by traversing until one reaches end
        ✔ Move head of longer list forward to align both lists by length
        ✔ Walk both pointers together to find intersection
*/
ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {

    // Edge case: If any list is empty → cannot intersect
    if(headA == NULL || headB == NULL) 
        return NULL;

    // Pointers to traverse both lists
    ListNode* a = headA;
    ListNode* b = headB;

    // Step 1: Traverse both lists together until one list ends
    // If nodes match at any time, that's intersection point
    while(a->next && b->next) {
        if(a == b) 
            return a;  // ✅ Found intersection

        a = a->next;
        b = b->next;
    }

    // Step 2: If both reached end and no match yet → no intersection
    if(a->next == NULL && b->next == NULL && a != b) 
        return NULL;

    // Step 3: Find which list is longer and shift its head forward
    if(a->next == NULL) {
        // B is longer than A
        int blen = 0;

        // Count remaining nodes in B
        while(b->next != NULL) {
            blen++;
            b = b->next;
        }

        // Shift headB forward to align both lists by length
        while(blen--) 
            headB = headB->next;
    }
    else {
        // A is longer than B
        int alen = 0;

        // Count remaining nodes in A
        while(a->next != NULL) {
            alen++;
            a = a->next;
        }

        // Shift headA forward to align both lists
        while(alen--) 
            headA = headA->next;
    }

    // Step 4: Now move both pointers together until they meet
    while(headA != headB) {
        headA = headA->next;
        headB = headB->next;
    }

    // Both heads now point to intersection node (or NULL if none)
    return headA;
}

int main() {
    // Example demonstration

    // Common nodes (intersection point starts here)
    ListNode* common = new ListNode(8);
    common->next = new ListNode(10);

    // First linked list: 3 -> 6 -> 9 -> 8 -> 10
    ListNode* headA = new ListNode(3);
    headA->next = new ListNode(6);
    headA->next->next = new ListNode(9);
    headA->next->next->next = common;

    // Second linked list: 4 -> 7 -> 8 -> 10
    ListNode* headB = new ListNode(4);
    headB->next = new ListNode(7);
    headB->next->next = common;

    // Function call
    ListNode* result = getIntersectionNode(headA, headB);

    // Output result
    if(result != NULL)
        cout << "Intersection at node with value: " << result->data << endl;
    else
        cout << "No Intersection" << endl;

    return 0;
}
