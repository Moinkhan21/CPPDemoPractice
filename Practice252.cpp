#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// ======================================================
// ✅ Class Definition: ListNode
// ------------------------------------------------------
// Represents a singly linked list node.
// Each node stores an integer value (`val`) and a pointer to the next node.
// ======================================================
class ListNode {
public:
    int val;          // Value stored in the node
    ListNode* next;   // Pointer to the next node in the list

    // Constructor to initialize the node
    ListNode(int v) : val(v), next(NULL) {}
};

// ======================================================
// ✅ Function: nextLargeNodes()
// ------------------------------------------------------
// Purpose:
//   Finds the **Next Greater Node** for each node in a linked list.
//   For every node, the function determines the first node (to its right)
//   that has a greater value. If none exists, the result is 0.
//
// Example:
//   Input:  2 → 7 → 4 → 3 → 5
//   Output: 7 0 5 5 0
//
// Approach:
//   - Convert the linked list into a vector for easy index access.
//   - Use a **monotonic decreasing stack** to find the next greater value.
//   - Traverse through each element, maintaining indices in the stack.
//   - When a greater value is found, pop from stack and assign the answer.
// ======================================================
vector<int> nextLargeNodes(ListNode* head) {
    vector<int> ll; // To store linked list values

    // Step 1: Convert Linked List → Vector
    while (head) {
        ll.push_back(head->val);
        head = head->next;
    }

    int n = ll.size();
    vector<int> ans(n, 0); // Initialize all next greater elements as 0
    stack<int> st;         // Stack stores indices of elements

    // Step 2: Traverse through vector and find next greater elements
    for (int i = 0; i < n; i++) {
        // While stack not empty and current element > element at stack's top index
        while (!st.empty() && ll[i] > ll[st.top()]) {
            int index = st.top();
            st.pop();

            // Current element is next greater for element at `index`
            ans[index] = ll[i];
        }

        // Push current index for later comparison
        st.push(i);
    }

    // Step 3: Remaining elements have no next greater (default = 0)
    return ans;
}

// ======================================================
// ✅ Helper Function: printVector()
// ------------------------------------------------------
// Prints elements of the result vector.
// ======================================================
void printVector(vector<int>& v) {
    for (int x : v)
        cout << x << " ";
    cout << endl;
}

// ======================================================
// ✅ Main Function: Test nextLargeNodes()
// ------------------------------------------------------
// Builds a linked list and finds next greater elements for each node.
// ======================================================
int main() {
    // Create Linked List: 2 → 7 → 4 → 3 → 5
    ListNode* head = new ListNode(2);
    head->next = new ListNode(7);
    head->next->next = new ListNode(4);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(5);

    // Step 1: Compute next greater elements
    vector<int> result = nextLargeNodes(head);

    // Expected Output: 7 0 5 5 0
    // Explanation:
    //   2 → next greater = 7
    //   7 → no greater → 0
    //   4 → next greater = 5
    //   3 → next greater = 5
    //   5 → no greater → 0

    cout << "Next Greater Nodes: ";
    printVector(result);

    return 0;
}
