#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

// =====================================================
// CLASS: node
// -----------------------------------------------------
// PURPOSE:
//   Represents a character and its remaining frequency.
//
// DATA MEMBERS:
//   • data  → character ('a', 'b', or 'c')
//   • count → number of times it can still be used
//
// WHY USE A CLASS?
//   • priority_queue works with a single object
//   • We want to compare characters based on frequency
// =====================================================
class node {
public:
    char data;
    int count;

    node(char d, int c) {
        data = d;
        count = c;
    }
};

// =====================================================
// CLASS: compare
// -----------------------------------------------------
// PURPOSE:
//   Custom comparator for priority_queue (pointer-based)
//
// WHY NEEDED?
//   • priority_queue is MAX heap by default
//   • For pointer objects, comparison logic must be
//     explicitly defined
//
// RULE:
//   • Character with higher frequency gets higher priority
// =====================================================
class compare {
public:
    bool operator()(node* a, node* b) {
        return a->count < b->count;   // MAX HEAP
    }
};

// =====================================================
// FUNCTION: longestDiverseString
// -----------------------------------------------------
// PURPOSE:
//   Generate the longest possible string using
//   characters 'a', 'b', and 'c' such that:
//
//   ❌ No character appears more than 2 times consecutively
//
// INPUT:
//   • a → count of character 'a'
//   • b → count of character 'b'
//   • c → count of character 'c'
//
// OUTPUT:
//   • Longest valid diverse string
//
// GREEDY + MAX HEAP STRATEGY:
//   1️⃣ Always pick the character with highest frequency
//   2️⃣ Add it at most twice (to avoid "aaa", "bbb", etc.)
//   3️⃣ Pick the second most frequent character next
//   4️⃣ Reinsert characters if frequency remains
//
// WHY THIS WORKS?
//   • Greedy choice maximizes length
//   • Heap ensures best next character
//   • Limiting to 2 prevents invalid sequences
//
// TIME COMPLEXITY:
//   • O((a + b + c) log 3) ≈ O(N)
//
// SPACE COMPLEXITY:
//   • O(1) → at most 3 heap elements
// =====================================================
string longestDiverseString(int a, int b, int c) {

    // -------------------------------------------------
    // Step 1: Build MAX HEAP
    // -------------------------------------------------
    priority_queue<node*, vector<node*>, compare> maxHeap;

    // Insert characters with positive count
    if (a > 0)
        maxHeap.push(new node('a', a));

    if (b > 0)
        maxHeap.push(new node('b', b));

    if (c > 0)
        maxHeap.push(new node('c', c));

    // Resultant string
    string ans = "";

    // -------------------------------------------------
    // Step 2: Process heap while 2 choices exist
    // -------------------------------------------------
    while (maxHeap.size() > 1) {

        // Extract two most frequent characters
        node* first = maxHeap.top();
        maxHeap.pop();

        node* second = maxHeap.top();
        maxHeap.pop();

        // -------------------------------------------------
        // Use FIRST character
        // -------------------------------------------------
        // Add it twice if possible for maximum length
        if (first->count >= 2) {
            ans += first->data;
            ans += first->data;
            first->count -= 2;
        }
        else {
            ans += first->data;
            first->count--;
        }

        // -------------------------------------------------
        // Use SECOND character
        // -------------------------------------------------
        // Add twice only if it is safe and beneficial
        if (second->count >= 2 &&
            second->count >= first->count) {

            ans += second->data;
            ans += second->data;
            second->count -= 2;
        }
        else {
            ans += second->data;
            second->count--;
        }

        // -------------------------------------------------
        // Reinsert remaining characters
        // -------------------------------------------------
        if (first->count > 0)
            maxHeap.push(first);

        if (second->count > 0)
            maxHeap.push(second);
    }

    // -------------------------------------------------
    // Step 3: Handle last remaining character
    // -------------------------------------------------
    if (maxHeap.size() == 1) {

        node* temp = maxHeap.top();
        maxHeap.pop();

        // Can add at most 2 characters safely
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

// =====================================================
// MAIN FUNCTION (TEST CASE)
// =====================================================
int main() {

    /*
        Input:
        a = 1, b = 3, c = 2

        One possible output:
        "bbcbac"

        Properties:
        ✔ Uses maximum characters
        ✔ No three consecutive same characters
        ✔ Greedy + heap based solution
    */

    int a = 1, b = 3, c = 2;

    string result = longestDiverseString(a, b, c);

    cout << "Longest Diverse String: "
         << result << endl;

    return 0;
}
