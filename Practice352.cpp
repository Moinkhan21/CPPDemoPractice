#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

// ===============================
// Node Definition
// ===============================
class node {
public:
    char data;
    int count;

    node(char d, int c) {
        data = d;
        count = c;
    }
};

// ===============================
// Comparator for MAX HEAP (pointer based)
// ===============================
class compare {
public:
    bool operator()(node* a, node* b) {
        return a->count < b->count;   // max heap
    }
};

// ===============================
// Longest Diverse String
// ===============================
string longestDiverseString(int a, int b, int c) {

    priority_queue<node*, vector<node*>, compare> maxHeap;

    if (a > 0)
        maxHeap.push(new node('a', a));

    if (b > 0)
        maxHeap.push(new node('b', b));

    if (c > 0)
        maxHeap.push(new node('c', c));

    string ans = "";

    while (maxHeap.size() > 1) {

        node* first = maxHeap.top();
        maxHeap.pop();

        node* second = maxHeap.top();
        maxHeap.pop();

        // Use first character
        if (first->count >= 2) {
            ans += first->data;
            ans += first->data;
            first->count -= 2;
        }
        else {
            ans += first->data;
            first->count--;
        }

        // Use second character
        if (second->count >= 2 && second->count >= first->count) {
            ans += second->data;
            ans += second->data;
            second->count -= 2;
        }
        else {
            ans += second->data;
            second->count--;
        }

        if (first->count > 0)
            maxHeap.push(first);

        if (second->count > 0)
            maxHeap.push(second);
    }

    // Handle last remaining character
    if (maxHeap.size() == 1) {
        node* temp = maxHeap.top();
        maxHeap.pop();

        if (temp->count >= 2) {
            ans += temp->data;
            ans += temp->data;
        }
        else {
            ans += temp->data;
        }
    }

    return ans;
}

// ===============================
// MAIN FUNCTION
// ===============================
int main() {

    /*
        Example:
        a = 1, b = 3, c = 2

        Possible Output:
        "bbcbac" (no three consecutive same chars)
    */

    int a = 1, b = 3, c = 2;

    string result = longestDiverseString(a, b, c);

    cout << "Longest Diverse String: " << result << endl;

    return 0;
}
