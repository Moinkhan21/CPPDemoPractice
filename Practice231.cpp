#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Singly Linked List Node Structure
class ListNode {
public:
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Function to calculate min and max distance between critical points
vector<int> nodesBetweenCriticalPoints(ListNode* head) {
    vector<int> ans = {-1, -1};
    if (!head || !head->next || !head->next->next)
        return ans;

    ListNode* prev = head;
    ListNode* curr = head->next;
    ListNode* nxt = head->next->next;

    int firstCP = -1, lastCP = -1;
    int minDist = INT_MAX;
    int index = 1;

    while (nxt) {
        bool isCP = ((curr->val > prev->val && curr->val > nxt->val) ||
                     (curr->val < prev->val && curr->val < nxt->val));

        if (isCP && firstCP == -1) {
            firstCP = index;
            lastCP = index;
        } 
        else if (isCP) {
            minDist = min(minDist, index - lastCP);
            lastCP = index;
        }

        prev = curr;
        curr = nxt;
        nxt = nxt->next;
        index++;
    }

    if (firstCP == lastCP)
        return ans;

    ans[0] = minDist;
    ans[1] = lastCP - firstCP;
    return ans;
}

// ✅ MAIN FUNCTION
int main() {
    // Example Linked List: 1 -> 3 -> 2 -> 5 -> 1
    ListNode* head = new ListNode(1);
    head->next = new ListNode(3);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(5);
    head->next->next->next->next = new ListNode(1);

    vector<int> result = nodesBetweenCriticalPoints(head);

    cout << "Min Distance: " << result[0] << endl;
    cout << "Max Distance: " << result[1] << endl;

    return 0;
}
