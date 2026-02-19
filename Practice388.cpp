#include <iostream>
#include <vector>
#include <deque>
using namespace std;

// =====================================================
// FUNCTION: maxSlidingWindow
// -----------------------------------------------------
// PROBLEM:
//   Given an array nums and an integer k,
//   return the maximum element of every
//   contiguous subarray of size k.
//
// EXAMPLE:
//   nums = [1,3,-1,-3,5,3,6,7]
//   k = 3
//
//   Output:
//   [3,3,5,5,6,7]
//
// APPROACH: MONOTONIC DEQUE (OPTIMAL)
//
// IDEA:
//   • Use a deque to store INDICES of elements
//   • Maintain deque in DECREASING ORDER of values
//   • Front always contains the MAX element index
//
// WHY DEQUE?
//   • Insert/remove from both ends in O(1)
//
// TIME COMPLEXITY:
//   • O(N) → each element pushed & popped once
//
// SPACE COMPLEXITY:
//   • O(K)
// =====================================================
vector<int> maxSlidingWindow(vector<int>& nums, int k) {

    deque<int> dq;     // Stores indices of useful elements
    vector<int> ans;   // Stores final result

    // -------------------------------------------------
    // EDGE CASES
    // -------------------------------------------------
    if (nums.empty() || k == 0 || k > nums.size())
        return ans;

    // =================================================
    // STEP 1: PROCESS FIRST WINDOW
    // =================================================
    for (int i = 0; i < k; i++) {

        // Remove all smaller elements from back
        // They cannot be maximum if current is bigger
        while (!dq.empty() && nums[dq.back()] < nums[i])
            dq.pop_back();

        // Add current index
        dq.push_back(i);
    }

    // First window maximum
    ans.push_back(nums[dq.front()]);

    // =================================================
    // STEP 2: PROCESS REMAINING WINDOWS
    // =================================================
    for (int i = k; i < nums.size(); i++) {

        // ---------------------------------------------
        // Remove elements OUTSIDE the window
        // Window range: [i-k+1 ... i]
        // ---------------------------------------------
        if (!dq.empty() && dq.front() <= i - k)
            dq.pop_front();

        // ---------------------------------------------
        // Maintain decreasing order in deque
        // Remove all smaller elements from back
        // ---------------------------------------------
        while (!dq.empty() && nums[dq.back()] < nums[i])
            dq.pop_back();

        // Add current index
        dq.push_back(i);

        // ---------------------------------------------
        // Front of deque = MAX element index
        // ---------------------------------------------
        ans.push_back(nums[dq.front()]);
    }

    return ans;
}

// =====================================================
// MAIN FUNCTION
// =====================================================
int main() {

    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;

    vector<int> result = maxSlidingWindow(nums, k);

    cout << "Sliding Window Maximum: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
