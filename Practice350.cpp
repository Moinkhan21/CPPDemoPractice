#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

// =====================================================
// FUNCTION: minStoneSum
// -----------------------------------------------------
// PROBLEM:
//   Given an array piles where piles[i] represents the
//   number of stones in the ith pile, and an integer k.
//
//   In one operation:
//   - Choose the pile with the maximum stones.
//   - Remove floor(pile / 2) stones from it.
//
//   Perform exactly k operations.
//
//   Return the minimum possible total number of stones.
//
// EXAMPLE:
//   piles = [5,4,9], k = 2
//
//   Step 1: remove from 9 → floor(9/2) = 4
//           new pile = 9 - 4 = 5
//
//   Step 2: remove from 5 → floor(5/2) = 2
//           new pile = 5 - 2 = 3
//
//   Final piles = [5,4,3]
//   Sum = 12
//
// APPROACH (GREEDY + MAX HEAP):
//
//   1️⃣ Insert all piles into a max heap.
//
//   2️⃣ Repeat k times:
//        - Take the largest pile
//        - Remove floor(pile / 2)
//        - Insert the updated pile back
//
//   3️⃣ Sum all remaining piles.
//
// WHY MAX HEAP?
//   We always want to reduce the largest pile first
//   to minimize the total number of stones.
//
// TIME COMPLEXITY:
//   O(n log n + k log n)
//
// SPACE COMPLEXITY:
//   O(n)
// =====================================================
int minStoneSum(vector<int>& piles, int k) {

    // Max Heap to always get largest pile
    priority_queue<int> maxHeap;

    // -------------------------------------------------
    // STEP 1: Insert all piles into heap
    // -------------------------------------------------
    for (int i = 0; i < piles.size(); i++) {
        maxHeap.push(piles[i]);
    }

    // -------------------------------------------------
    // STEP 2: Perform k operations
    // -------------------------------------------------
    while (k--) {

        // Get largest pile
        int maxElement = maxHeap.top();
        maxHeap.pop();

        // Remove floor(maxElement / 2)
        maxElement = maxElement - floor(maxElement / 2);

        // Insert updated pile back
        maxHeap.push(maxElement);
    }

    // -------------------------------------------------
    // STEP 3: Compute remaining sum
    // -------------------------------------------------
    int sum = 0;

    while (!maxHeap.empty()) {
        sum += maxHeap.top();
        maxHeap.pop();
    }

    return sum;
}

// =====================================================
// MAIN FUNCTION
// -----------------------------------------------------
// PURPOSE:
//   Demonstrates minimum stone sum problem
// =====================================================
int main() {

    /*
        Input:
        piles = [5, 4, 9]
        k = 2

        Step 1: Remove from 9 → 9 - 4 = 5
        Step 2: Remove from 5 → 5 - 2 = 3

        Final piles = [5, 4, 3]
        Sum = 12
    */

    vector<int> piles = {5, 4, 9};
    int k = 2;

    int result = minStoneSum(piles, k);

    cout << "Minimum possible sum of stones = " << result << endl;

    return 0;
}