#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// ===========================================================
// ✅ Singly Linked List Node Structure
// Each node contains an integer value and a pointer to the next node.
// ===========================================================
class ListNode {
public:
    int val;         // Data value stored in the node
    ListNode* next;  // Pointer to the next node

    // Constructor initializes node with given value
    ListNode(int x) : val(x), next(NULL) {}
};

// ===========================================================
// ✅ Function: nodesBetweenCriticalPoints
// Purpose: To find the minimum and maximum distance between
//          critical points in a singly linked list.
//
// A critical point is defined as a node that is either:
//  - a local maxima → value > previous node and next node
//  - a local minima → value < previous node and next node
//
// Returns a vector:
//  ans[0] → minimum distance between any two critical points
//  ans[1] → maximum distance between first and last critical point
// ===========================================================
vector<int> nodesBetweenCriticalPoints(ListNode* head) {

    // Initialize result with [-1, -1] for cases where <2 critical points exist
    vector<int> ans = {-1, -1};

    // If the list has fewer than 3 nodes, no critical point can exist
    if (!head || !head->next || !head->next->next)
        return ans;

    // Initialize pointers for traversal
    ListNode* prev = head;           // Points to previous node
    ListNode* curr = head->next;     // Points to current node
    ListNode* nxt = head->next->next;// Points to next node

    // Variables to track first and last critical point indices
    int firstCP = -1, lastCP = -1;

    // Variable to track minimum distance between consecutive critical points
    int minDist = INT_MAX;

    // Current node index (start from 1 since head is at index 0)
    int index = 1;

    // Traverse through the linked list until 'nxt' becomes NULL
    while (nxt) {

        // --------------------------------------------
        // ✅ Step 1: Check if current node is a critical point
        // Local maxima → curr->val > prev->val && curr->val > nxt->val
        // Local minima → curr->val < prev->val && curr->val < nxt->val
        // --------------------------------------------
        bool isCP = ((curr->val > prev->val && curr->val > nxt->val) ||
                     (curr->val < prev->val && curr->val < nxt->val));

        // --------------------------------------------
        // ✅ Step 2: If current node is a critical point
        // --------------------------------------------
        if (isCP && firstCP == -1) {
            // First critical point found → record its position
            firstCP = index;
            lastCP = index;
        } 
        else if (isCP) {
            // For every next critical point, update minimum distance
            // between consecutive critical points
            minDist = min(minDist, index - lastCP);

            // Update last critical point position
            lastCP = index;
        }

        // --------------------------------------------
        // ✅ Step 3: Move all pointers one step forward
        // --------------------------------------------
        prev = curr;
        curr = nxt;
        nxt = nxt->next;
        index++;
    }

    // --------------------------------------------
    // ✅ Step 4: Handle case where <2 critical points exist
    // --------------------------------------------
    if (firstCP == lastCP)
        return ans;  // Return [-1, -1]

    // --------------------------------------------
    // ✅ Step 5: Calculate min and max distances
    // minDist → minimum gap between any two consecutive critical points
    // lastCP - firstCP → distance between first and last critical points
    // --------------------------------------------
    ans[0] = minDist;
    ans[1] = lastCP - firstCP;

    return ans;
}

// ===========================================================
// ✅ MAIN FUNCTION — Demonstration
// Example Linked List: 1 -> 3 -> 2 -> 5 -> 1
// Critical points: 3 (local max), 2 (local min), 5 (local max)
// ===========================================================
int main() {
    // Create example linked list
    ListNode* head = new ListNode(1);
    head->next = new ListNode(3);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(5);
    head->next->next->next->next = new ListNode(1);

    // Function call
    vector<int> result = nodesBetweenCriticalPoints(head);

    // Output results
    cout << "Min Distance: " << result[0] << endl;
    cout << "Max Distance: " << result[1] << endl;

    return 0;
}
