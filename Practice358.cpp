#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// =====================================================
// FUNCTION: maxSlidingWindow
// -----------------------------------------------------
// PROBLEM:
//   Given an array nums and window size k,
//   return the maximum element for every sliding window.
//
// EXAMPLE:
//   nums = [1,3,-1,-3,5,3,6,7]
//   k = 3
//
//   Windows:
//   [1,3,-1] → 3
//   [3,-1,-3] → 3
//   [-1,-3,5] → 5
//   [-3,5,3] → 5
//   [5,3,6] → 6
//   [3,6,7] → 7
//
//   Output = [3,3,5,5,6,7]
//
// APPROACH (MAX HEAP):
//
//   1️⃣ Store elements in priority_queue as:
//        {value, index}
//
//   2️⃣ First insert first k elements
//
//   3️⃣ The top of heap = maximum element
//
//   4️⃣ When sliding window moves:
//        • Insert new element
//        • Remove elements that fall outside window
//
// TIME COMPLEXITY:
//   O(n log n)
//
// SPACE COMPLEXITY:
//   O(k)
// =====================================================
vector<int> maxSlidingWindow(vector<int>& nums, int k) {

    // Max Heap storing {value, index}
    priority_queue<pair<int, int>> pq;

    vector<int> ans;

    // -------------------------------------------------
    // STEP 1: Process first window
    // -------------------------------------------------
    for (int i = 0; i < k; ++i) {
        pq.push({nums[i], i});
    }

    // Maximum of first window
    ans.push_back(pq.top().first);

    // -------------------------------------------------
    // STEP 2: Process remaining windows
    // -------------------------------------------------
    for (int i = k; i < nums.size(); ++i) {

        // Insert new element into heap
        pq.push({nums[i], i});

        // Remove elements outside current window
        while (!pq.empty() && pq.top().second <= i - k) {
            pq.pop();
        }

        // Current window maximum
        ans.push_back(pq.top().first);
    }

    return ans;
}

// =====================================================
// MAIN FUNCTION
// -----------------------------------------------------
// PURPOSE:
//   Demonstrates Sliding Window Maximum problem
// =====================================================
int main() {

    /*
        Input:
        nums = [1,3,-1,-3,5,3,6,7]
        k = 3

        Output:
        [3,3,5,5,6,7]
    */

    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;

    vector<int> result = maxSlidingWindow(nums, k);

    cout << "Sliding Window Maximums:\n";

    for (int x : result) {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}