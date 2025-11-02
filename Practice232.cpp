#include <iostream>
using namespace std;

ListNode* mergeNodes(ListNode* head) {
    if(!head) return 0;
    ListNode* slow = head, *fast = head -> next, *newLastNode = 0;
    int sum = 0;
    while(fast) {
        if(fast -> val != 0) {
            sum += fast -> val;
        }
        else{
            //fast -> val == 0
            slow -> val = sum;
            newLastNode = slow;
            slow = slow -> next;
            sum = 0;
        }
        fast = fast -> next;
    }

    ListNode* temp = slow;

    //Just formed new list
    newLastNode -> next = 0; 

    //Deleting old list
    while(temp) {
        ListNode*nxt = temp -> next;
        delete temp;
        temp = nxt;
    }
    return head;
}