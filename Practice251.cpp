#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// ======================================================
// ✅ Linked List Node Structure
// ======================================================
class ListNode {
public:
    int val;
    ListNode* next;

    ListNode(int v) {
        val = v;
        next = NULL;
    }
};

// ======================================================
// ✅ Function: nextLargeNodes
// Given a Linked List, returns vector of next greater values
// ======================================================
vector<int> nextLargeNodes(ListNode* head) {
    vector<int> ll;  // Store linked list values in array form

    // Step 1: Convert LL → Array
    while (head) {
        ll.push_back(head->val);
        head = head->next;
    }

    int n = ll.size();
    vector<int> ans(n, 0);  // By default, next greater = 0
    stack<int> st;          // Store indices of ll[]

    // Step 2: Next Greater Element logic using stack
    for (int i = 0; i < n; i++) {
        // While current element is greater than element at stack top
        while (!st.empty() && ll[i] > ll[st.top()]) {
            int index = st.top();
            st.pop();
            ans[index] = ll[i];   // Found next greater
        }
        st.push(i); // Push current index
    }

    return ans;
}

// ======================================================
// ✅ Helper function to print vector
// ======================================================
void printVector(vector<int>& v) {
    for (int x : v) cout << x << " ";
    cout << endl;
}

// ======================================================
// ✅ Main function to test nextLargeNodes()
// ======================================================
int main() {
    // Example Linked List: 2 → 1 → 5
    ListNode* head = new ListNode(2);
    head->next = new ListNode(1);
    head->next->next = new ListNode(5);

    vector<int> result = nextLargeNodes(head);

    // Expected Output: 5 5 0
    cout << "Next Greater Nodes: ";
    printVector(result);

    return 0;
}
