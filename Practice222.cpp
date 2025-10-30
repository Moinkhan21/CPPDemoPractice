#include <iostream>
using namespace std;

// ---------------------
// ✅ Singly Linked List Node Structure
// ---------------------
class SinglyLinkedListNode {
public:
    int data;
    SinglyLinkedListNode* next;

    SinglyLinkedListNode(int data) {
        this->data = data;
        this->next = NULL;
    }
};

// ---------------------
// ✅ Recursive Function to find value from tail
// ---------------------
void fun(SinglyLinkedListNode* head, int &positionFromTail, int &ans) {
    // Base Case: reached end
    if(head == NULL) {
        return;
    }

    // Recursive call to go till end
    fun(head->next, positionFromTail, ans);

    // When we start returning back, decrease count
    if(positionFromTail == 0) {
        ans = head->data;  // Found required node
    }
    positionFromTail--;
}

// ---------------------
// ✅ Function Wrapper
// ---------------------
int getNode(SinglyLinkedListNode* llist, int positionFromTail) {
    int ans = -1;   // Default if not found
    fun(llist, positionFromTail, ans);
    return ans;
}

// ---------------------
// ✅ MAIN FUNCTION — testing the logic
// Linked List: 10 -> 20 -> 30 -> 40 -> 50
// Example: positionFromTail = 2 → Output = 30
// ---------------------
int main() {
    SinglyLinkedListNode* head = new SinglyLinkedListNode(10);
    head->next = new SinglyLinkedListNode(20);
    head->next->next = new SinglyLinkedListNode(30);
    head->next->next->next = new SinglyLinkedListNode(40);
    head->next->next->next->next = new SinglyLinkedListNode(50);

    int positionFromTail = 2; // 0-based index from tail
    cout << "Node from tail = " << getNode(head, positionFromTail) << endl;

    return 0;
}
