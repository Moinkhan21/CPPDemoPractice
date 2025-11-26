#include <iostream>
#include <deque>
#include <vector>
using namespace std;

// =================================================================================================
// FUNCTION: maxSlidingWindow
// PURPOSE:
//   Computes the maximum value in every sliding window of size k across the array.
//
// HOW IT WORKS:
//   Uses a **Monotonic Deque** to keep track of the indices of useful elements.
//   The deque always stores indices in such a way that:
//       • Their corresponding values are in **decreasing order**.
//       • The **front** of the deque always represents the index of the **current maximum**.
//
// WHY DEQUE?
//   • pop_front()  → remove elements that slide out of window
//   • pop_back()   → maintain decreasing order by removing smaller values
//   • O(n) time   → each element is inserted & removed at most once
// =================================================================================================
vector<int> maxSlidingWindow(vector<int>& nums, int k) {

    if (nums.empty() || k == 0) return {};  // Edge case: empty input

    deque<int> dq;     // stores indices of useful elements
    vector<int> ans;   // result array

    // -------------------------------------------------
    // STEP 1: Process the first window of size k
    // -------------------------------------------------
    for (int i = 0; i < k; i++) {

        // Remove from back: elements smaller than current element
        // They cannot be the maximum in this or future windows
        while (!dq.empty() && nums[i] >= nums[dq.back()]) {
            dq.pop_back();
        }

        // Store index of current element
        dq.push_back(i);
    }

    // First maximum (at deque front)
    ans.push_back(nums[dq.front()]);

    // -------------------------------------------------
    // STEP 2: Process the rest of the windows
    // -------------------------------------------------
    for (int i = k; i < nums.size(); i++) {

        // A. Remove elements that are now outside the window
        // Window range: [i-k+1, i]
        if (!dq.empty() && dq.front() <= i - k) {
            dq.pop_front();
        }

        // B. Remove all elements smaller than current element
        // Because they won't contribute to future maximums
        while (!dq.empty() && nums[i] >= nums[dq.back()]) {
            dq.pop_back();
        }

        // C. Push current element index
        dq.push_back(i);

        // D. Maximum for this window
        ans.push_back(nums[dq.front()]);
    }

    return ans;
}

// =================================================================================================
// MAIN FUNCTION — Tests the Sliding Window Maximum Function
// =================================================================================================
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
