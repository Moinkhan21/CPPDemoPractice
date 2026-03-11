#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// =====================================================
// STRUCT: ListNode
// -----------------------------------------------------
// PURPOSE:
//   Represents a node of a singly linked list.
//
// MEMBERS:
//   val  → value stored in node
//   next → pointer to next node
//
// CONSTRUCTOR:
//   Initializes node value and sets next to NULL
// =====================================================
struct ListNode {
    int val;
    ListNode* next;

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
// DEFAULT BEHAVIOR:
//   priority_queue creates a MAX HEAP.
//
// WHAT WE NEED:
//   A MIN HEAP (smallest element first).
//
// LOGIC:
//   Return true if first node has larger value
//   than second node → ensures smallest node
//   stays on top of heap.
// =====================================================
class compare {
public:
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val;   // condition for MIN HEAP
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
    // PROBLEM:
    //   Merge K sorted linked lists into one sorted list.
    //
    // APPROACH (MIN HEAP):
    //
    //   1️⃣ Insert the head of each list into a min heap
    //   2️⃣ Extract the smallest node from heap
    //   3️⃣ Attach it to result list
    //   4️⃣ Push the next node of that list into heap
    //   5️⃣ Repeat until heap becomes empty
    //
    // WHY HEAP?
    //   Heap helps quickly get the smallest element
    //   among K lists.
    //
    // TIME COMPLEXITY:
    //   O(N log K)
    //   N = total number of nodes
    //   K = number of linked lists
    //
    // SPACE COMPLEXITY:
    //   O(K) → heap stores at most K nodes
    // =================================================
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        // Min heap storing ListNode pointers
        priority_queue<ListNode*, vector<ListNode*>, compare> minHeap;

        int k = lists.size();

        // Edge case: no lists provided
        if (k == 0)
            return NULL;

        // -------------------------------------------------
        // STEP 1: Insert first node of each linked list
        // -------------------------------------------------
        for (int i = 0; i < k; i++) {
            if (lists[i] != NULL) {
                minHeap.push(lists[i]);
            }
        }

        // Pointers for merged linked list
        ListNode* head = NULL;
        ListNode* tail = NULL;

        // -------------------------------------------------
        // STEP 2: Process heap until it becomes empty
        // -------------------------------------------------
        while (!minHeap.empty()) {

            // Extract smallest node
            ListNode* temp = minHeap.top();
            minHeap.pop();

            // -------------------------------------------------
            // STEP 3: Attach node to result linked list
            // -------------------------------------------------
            if (head == NULL) {
                // First node of merged list
                head = temp;
                tail = temp;
            }
            else {
                tail->next = temp;
                tail = temp;
            }

            // -------------------------------------------------
            // STEP 4: Insert next node of extracted list
            // -------------------------------------------------
            if (temp->next != NULL) {
                minHeap.push(temp->next);
            }
        }

        return head;
    }
};

// =====================================================
// MAIN FUNCTION (TESTING)
// =====================================================
int main() {

    /*
        Input Lists:

        List 1: 1 -> 4 -> 5
        List 2: 1 -> 3 -> 4
        List 3: 2 -> 6

        Expected Output:
        1 1 2 3 4 4 5 6
    */

    // Create List 1
    ListNode* l1 = new ListNode(1);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(5);

    // Create List 2
    ListNode* l2 = new ListNode(1);
    l2->next = new ListNode(3);
    l2->next->next = new ListNode(4);

    // Create List 3
    ListNode* l3 = new ListNode(2);
    l3->next = new ListNode(6);

    // Store all list heads
    vector<ListNode*> lists = {l1, l2, l3};

    // Create solution object
    Solution sol;

    // Merge all lists
    ListNode* result = sol.mergeKLists(lists);

    // Print merged linked list
    cout << "Merged List: ";

    while (result) {
        cout << result->val << " ";
        result = result->next;
    }

    cout << endl;

    return 0;
}