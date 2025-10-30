#include <iostream>
using namespace std;

class ListNode {
public:
    int data;
    ListNode* next;
    ListNode(int x) {
        data = x;
        next = NULL;
    }
};

ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {

    if(headA == NULL || headB == NULL) 
        return NULL;

    ListNode* a = headA;
    ListNode* b = headB;

    // Step 1: Traverse both until one finishes
    while(a->next && b->next) {
        if(a == b) return a;
        a = a->next;
        b = b->next;
    }

    // Step 2: If both ended and no match, return NULL
    if(a->next == NULL && b->next == NULL && a != b) 
        return NULL;

    // Step 3: Find which list is longer
    if(a->next == NULL) {
        // B is longer
        int blen = 0;
        while(b->next != NULL) {
            blen++;
            b = b->next;
        }
        while(blen--) headB = headB->next;
    }
    else {
        // A is longer
        int alen = 0;
        while(a->next != NULL) {
            alen++;
            a = a->next;
        }
        while(alen--) headA = headA->next;
    }

    // Step 4: Now move both together to find intersection
    while(headA != headB) {
        headA = headA->next;
        headB = headB->next;
    }

    return headA;  // or headB (same thing)
}

int main() {
    // Example demonstration
    ListNode* common = new ListNode(8);
    common->next = new ListNode(10);

    ListNode* headA = new ListNode(3);
    headA->next = new ListNode(6);
    headA->next->next = new ListNode(9);
    headA->next->next->next = common;

    ListNode* headB = new ListNode(4);
    headB->next = new ListNode(7);
    headB->next->next = common;

    ListNode* result = getIntersectionNode(headA, headB);

    if(result != NULL)
        cout << "Intersection at node with value: " << result->data << endl;
    else
        cout << "No Intersection" << endl;

    return 0;
}
