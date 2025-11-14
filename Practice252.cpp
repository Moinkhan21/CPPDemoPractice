#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// ============================
// Linked List Node definition
// ============================
class ListNode {
public:
    int val;
    ListNode* next;
    ListNode(int v) : val(v), next(NULL) {}
};

// ============================
// Next Greater Nodes Function
// ============================
vector<int> nextLargeNodes(ListNode* head) {
    vector<int> ll;

    // Convert Linked List → array
    while (head) {
        ll.push_back(head->val);
        head = head->next;
    }

    int n = ll.size();
    vector<int> ans(n, 0); // default all next greater = 0

    stack<int> st; // stores indices

    // Monotonic stack approach
    for (int i = 0; i < n; i++) {
        // If current element is next greater for elements in stack
        while (!st.empty() && ll[i] > ll[st.top()]) {
            int index = st.top();
            st.pop();
            ans[index] = ll[i]; // store next greater
        }
        st.push(i);
    }

    // Remaining elements have no next greater → already = 0
    return ans;
}

// ============================
// Helper: Print vector
// ============================
void printVector(vector<int>& v) {
    for (int x : v) cout << x << " ";
    cout << endl;
}

// ============================
// Main Function (Test)
// ============================
int main() {
    // Create Linked List: 2 → 7 → 4 → 3 → 5
    ListNode* head = new ListNode(2);
    head->next = new ListNode(7);
    head->next->next = new ListNode(4);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(5);

    vector<int> result = nextLargeNodes(head);

    // Expected Output: 7 0 5 5 0
    // Explanation:
    // 2 → next greater = 7
    // 7 → next greater = none → 0
    // 4 → next greater = 5
    // 3 → next greater = 5
    // 5 → none → 0

    cout << "Next Greater Nodes: ";
    printVector(result);

    return 0;
}
