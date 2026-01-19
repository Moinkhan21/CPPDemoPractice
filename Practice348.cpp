#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// =====================================================
// STRUCT: ListNode
// -----------------------------------------------------
// Represents a node of a singly linked list.
//
// MEMBERS:
//   • val  → value stored in the node
//   • next → pointer to the next node
// =====================================================
struct ListNode {
    int val;
    ListNode* next;

    // Constructor initializes node value
    // and sets next pointer to NULL
    ListNode(int x) {
        val = x;
        next = NULL;
    }
};

// =====================================================
// CLASS: compare
// -----------------------------------------------------
// PURPOSE:
//   Custom comparator for priority_queue.
//
// WHY REQUIRED?
//   • priority_queue is MAX heap by default
//   • We need a MIN heap (smallest element first)
//
// RULE:
//   Node with smaller value gets higher priority
// =====================================================
class compare {
public:
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val;   // MIN HEAP condition
    }
};

// =====================================================
// CLASS: Solution
// =====================================================
class Solution {
public:

    // =================================================
    // FUNCTION: mergeKLists
    // -------------------------------------------------
    // PURPOSE:
    //   Merge K sorted linked lists into one sorted list
    //
    // APPROACH (MIN HEAP):
    //   1️⃣ Push head of each linked list into heap
    //   2️⃣ Extract smallest node
    //   3️⃣ Attach it to result list
    //   4️⃣ Push its next node into heap
    //   5️⃣ Repeat until heap is empty
    //
    // TIME COMPLEXITY: O(N log K)
    // SPACE COMPLEXITY: O(K)
    // =================================================
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        // Min heap storing ListNode pointers
        priority_queue<ListNode*, vector<ListNode*>, compare> minHeap;

        int k = lists.size();

        // Edge case: no lists
        if (k == 0)
            return NULL;

        // ---------------------------------------------
        // Step 1: Push first node of each list
        // ---------------------------------------------
        for (int i = 0; i < k; i++) {
            if (lists[i] != NULL) {
                minHeap.push(lists[i]);
            }
        }

        // Head and tail of merged linked list
        ListNode* head = NULL;
        ListNode* tail = NULL;

        // ---------------------------------------------
        // Step 2: Process heap until empty
        // ---------------------------------------------
        while (!minHeap.empty()) {

            // Get smallest node
            ListNode* temp = minHeap.top();
            minHeap.pop();

            // -----------------------------------------
            // Step 3: Attach node to result list
            // -----------------------------------------
            if (head == NULL) {
                // First node of merged list
                head = temp;
                tail = temp;
            }
            else {
                tail->next = temp;
                tail = temp;
            }

            // -----------------------------------------
            // Step 4: Push next node of extracted list
            // -----------------------------------------
            if (temp->next != NULL) {
                minHeap.push(temp->next);
            }
        }

        return head;
    }
};

// =====================================================
// MAIN FUNCTION (TEST CASE)
// =====================================================
int main() {

    /*
        Input Lists:
        1 -> 4 -> 5
        1 -> 3 -> 4
        2 -> 6

        Output:
        1 1 2 3 4 4 5 6
    */

    // List 1
    ListNode* l1 = new ListNode(1);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(5);

    // List 2
    ListNode* l2 = new ListNode(1);
    l2->next = new ListNode(3);
    l2->next->next = new ListNode(4);

    // List 3
    ListNode* l3 = new ListNode(2);
    l3->next = new ListNode(6);

    // Store all list heads
    vector<ListNode*> lists = {l1, l2, l3};

    // Merge lists
    Solution sol;
    ListNode* result = sol.mergeKLists(lists);

    // Print merged list
    cout << "Merged List: ";
    while (result) {
        cout << result->val << " ";
        result = result->next;
    }
    cout << endl;

    return 0;
}
