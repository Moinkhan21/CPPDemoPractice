#include <iostream>
using namespace std;

class ListNode {
public:
    int data;
    ListNode* next;

    ListNode(int val) {
        data = val;
        next = NULL;
    }
};

ListNode* findMid(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head->next;

    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

ListNode* merge(ListNode* left, ListNode* right) {

    if(left == NULL) return right;
    if(right == NULL) return left;

    ListNode* ans = new ListNode(-1);  // Dummy node
    ListNode* mptr = ans;

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

    while(left != NULL) {
        mptr->next = left;
        mptr = left;
        left = left->next;
    }

    while(right != NULL) {
        mptr->next = right;
        mptr = right;
        right = right->next;
    }

    return ans->next; // skip dummy node
}

ListNode* sortList(ListNode* head) {
    if(head == NULL || head->next == NULL) {
        return head;
    }

    // Break LL into halves
    ListNode* mid = findMid(head);
    ListNode* left = head;
    ListNode* right = mid->next;
    mid->next = NULL;

    // Sort both halves
    left = sortList(left);
    right = sortList(right);

    // Merge the halves
    return merge(left, right);
}

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

    head = sortList(head);

    cout << "Sorted List: ";
    printList(head);

    return 0;
}
