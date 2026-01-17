#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// ===============================
// ListNode Definition
// ===============================
struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = NULL;
    }
};

// ===============================
// Comparator for Min Heap
// ===============================
class compare {
public:
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val;   // MIN HEAP
    }
};

// ===============================
// Solution Class
// ===============================
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        priority_queue<ListNode*, vector<ListNode*>, compare> minHeap;

        int k = lists.size();
        if (k == 0)
            return NULL;

        // Push first node of each list
        for (int i = 0; i < k; i++) {
            if (lists[i] != NULL) {
                minHeap.push(lists[i]);
            }
        }

        ListNode* head = NULL;
        ListNode* tail = NULL;

        while (!minHeap.empty()) {

            ListNode* temp = minHeap.top();
            minHeap.pop();

            // First node of result list
            if (head == NULL) {
                head = temp;
                tail = temp;
            }
            else {
                tail->next = temp;
                tail = temp;
            }

            // Push next node of the extracted node
            if (temp->next != NULL) {
                minHeap.push(temp->next);
            }
        }

        return head;
    }
};

// ===============================
// MAIN (Test Case)
// ===============================
int main() {

    /*
        Lists:
        1 -> 4 -> 5
        1 -> 3 -> 4
        2 -> 6

        Output:
        1 1 2 3 4 4 5 6
    */

    ListNode* l1 = new ListNode(1);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(5);

    ListNode* l2 = new ListNode(1);
    l2->next = new ListNode(3);
    l2->next->next = new ListNode(4);

    ListNode* l3 = new ListNode(2);
    l3->next = new ListNode(6);

    vector<ListNode*> lists = {l1, l2, l3};

    Solution sol;
    ListNode* result = sol.mergeKLists(lists);

    cout << "Merged List: ";
    while (result) {
        cout << result->val << " ";
        result = result->next;
    }
    cout << endl;

    return 0;
}
