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

ListNode* mergeTwoLists(ListNode* left, ListNode* right) {

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

// Function to print list
void printList(ListNode* head) {
    while(head != NULL) {
        cout << head->data << " ";
        head = head->next;
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

    ListNode* mergedHead = mergeTwoLists(left, right);

    cout << "Merged Linked List: ";
    printList(mergedHead);

    return 0;
}
