#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

// ===============================
// Function: Minimum Stone Sum
// ===============================
int minStoneSum(vector<int>& piles, int k) {

    priority_queue<int> maxHeap;

    // Insert all piles into max heap
    for (int i = 0; i < piles.size(); i++) {
        maxHeap.push(piles[i]);
    }

    // Perform k operations
    while (k--) {
        int maxElement = maxHeap.top();
        maxHeap.pop();

        // Remove floor(maxElement / 2)
        maxElement = maxElement - floor(maxElement / 2);
        maxHeap.push(maxElement);
    }

    // Calculate remaining sum
    int sum = 0;
    while (!maxHeap.empty()) {
        sum += maxHeap.top();
        maxHeap.pop();
    }

    return sum;
}

// ===============================
// MAIN FUNCTION
// ===============================
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
