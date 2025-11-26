#include <iostream>
#include <deque>
#include <vector>
using namespace std;

// =============================================================
// FUNCTION: maxSlidingWindow
// Purpose:
//   Find maximum in each sliding window of size k
// Approach:
//   Use a DEQUE to store indices of useful elements.
//   Maintain the deque in decreasing order of values.
//   The front of deque always contains the index of the maximum.
// =============================================================
vector<int> maxSlidingWindow(vector<int>& nums, int k) {

    if (nums.empty() || k == 0) return {};

    deque<int> dq;     // will store indices
    vector<int> ans;

    // ---------------------------
    // Step 1: Process first window
    // ---------------------------
    for (int i = 0; i < k; i++) {

        // Remove indices whose values are <= current element
        while (!dq.empty() && nums[i] >= nums[dq.back()]) {
            dq.pop_back();
        }

        dq.push_back(i);  // Push index
    }

    // Maximum of first window
    ans.push_back(nums[dq.front()]);

    // ------------------------------------------------------
    // Step 2: Process remaining windows (i = k to nums.size)
    // ------------------------------------------------------
    for (int i = k; i < nums.size(); i++) {

        // Remove elements out of this window
        if (!dq.empty() && dq.front() <= i - k) {
            dq.pop_front();
        }

        // Remove all smaller elements from the back
        while (!dq.empty() && nums[i] >= nums[dq.back()]) {
            dq.pop_back();
        }

        dq.push_back(i);

        // Front holds index of max element of current window
        ans.push_back(nums[dq.front()]);
    }

    return ans;
}

// =============================================================
// MAIN FUNCTION — Testing the Sliding Window Maximum
// =============================================================
int main() {
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    int k = 3;

    vector<int> result = maxSlidingWindow(nums, k);

    cout << "Sliding Window Maximums: ";
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
