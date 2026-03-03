#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// =====================================================
// PROGRAM: Minimum Cost to Connect Ropes
// -----------------------------------------------------
// PROBLEM:
//   Given an array representing lengths of ropes,
//   connect all ropes into one rope.
//
//   Cost of connecting two ropes = sum of their lengths.
//
//   Find the minimum total cost required.
//
// EXAMPLE:
//   arr = {4, 3, 2, 6}
//
//   Step 1: Connect 2 + 3 = 5  → cost = 5
//   Step 2: Connect 4 + 5 = 9  → cost = 5 + 9 = 14
//   Step 3: Connect 6 + 9 = 15 → cost = 14 + 15 = 29
//
//   Final Answer = 29
//
// APPROACH (GREEDY + MIN HEAP):
//   1️⃣ Always pick the two smallest ropes
//   2️⃣ Connect them
//   3️⃣ Add the cost
//   4️⃣ Push new rope back into heap
//   5️⃣ Repeat until only one rope remains
//
// WHY MIN HEAP?
//   • Efficiently gives smallest elements
//   • Ensures minimum total cost (Greedy)
//
// TIME COMPLEXITY:
//   • O(n log n)
//
// SPACE COMPLEXITY:
//   • O(n)
// =====================================================
int main() {

    // -------------------------------------------------
    // INPUT: Rope lengths
    // -------------------------------------------------
    int arr[] = {4, 3, 2, 6};
    int n = 4;

    // -------------------------------------------------
    // STEP 1: Create Min Heap
    // -------------------------------------------------
    // By default priority_queue is max heap
    // Using greater<int> makes it min heap
    priority_queue<int, vector<int>, greater<int>> pq;

    // Push all rope lengths into heap
    for (int i = 0; i < n; i++) {
        pq.push(arr[i]);
    }

    int cost = 0;  // Stores total minimum cost

    // -------------------------------------------------
    // STEP 2: Connect ropes until one remains
    // -------------------------------------------------
    while (pq.size() != 1) {

        // Extract two smallest ropes
        int first = pq.top();
        pq.pop();

        int second = pq.top();
        pq.pop();

        // Add their cost
        cost += first + second;

        // New rope formed
        int newLength = first + second;

        // Push new rope back into heap
        pq.push(newLength);
    }

    // -------------------------------------------------
    // OUTPUT: Minimum cost
    // -------------------------------------------------
    cout << "Cost is: " << cost << endl;

    return 0;
}