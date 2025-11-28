#include <iostream>
#include <deque>
#include <vector>
using namespace std;

// =====================================================================
// FUNCTION: sumOfMinMaxAllWindowOfSizek
// ---------------------------------------------------------------------
// PURPOSE:
//   For every sliding window of size 'k', compute:
//       window_max + window_min
//   and then return the SUM of these values for all windows.
//
// APPROACH:
//   We maintain TWO deques:
//     • dq1 → Monotonic decreasing deque (stores indices of MAX values)
//     • dq2 → Monotonic increasing deque (stores indices of MIN values)
//
//   These deques store indices such that:
//     - dq1.front() always contains index of maximum element of window
//     - dq2.front() always contains index of minimum element of window
//
//   For each window:
//       result += max + min
//
// COMPLEXITY:
//     Time:  O(n)       (each element enters & exits deque once)
//     Space: O(k)       (size of each deque)
// =====================================================================
int sumOfMinMaxAllWindowOfSizek(vector<int>& nums, int k) {

    deque<int> dq1, dq2;   // dq1 → max deque, dq2 → min deque
    int ans = 0;

    // -------------------------------------------------------
    // STEP 1: Process the FIRST WINDOW of size 'k'
    // -------------------------------------------------------
    for (int i = 0; i < k; i++) {

        // Maintain decreasing order for dq1 (largest at front)
        while (!dq1.empty() && nums[i] >= nums[dq1.back()]) {
            dq1.pop_back();  // remove smaller values from back
        }

        // Maintain increasing order for dq2 (smallest at front)
        while (!dq2.empty() && nums[i] <= nums[dq2.back()]) {
            dq2.pop_back();  // remove larger values from back
        }

        // Insert current index
        dq1.push_back(i);
        dq2.push_back(i);
    }

    // Add first window result (max + min)
    ans += nums[dq1.front()] + nums[dq2.front()];

    // -------------------------------------------------------
    // STEP 2: Process REMAINING WINDOWS
    // -------------------------------------------------------
    for (int i = k; i < nums.size(); i++) {

        // ---- REMOVE OUT-OF-WINDOW ELEMENTS ----
        if (!dq1.empty() && i - dq1.front() >= k) {
            dq1.pop_front();
        }
        if (!dq2.empty() && i - dq2.front() >= k) {
            dq2.pop_front();
        }

        // ---- INSERT NEW ELEMENT (maintain monotonicity) ----

        // For max deque (dq1)
        while (!dq1.empty() && nums[i] >= nums[dq1.back()]) {
            dq1.pop_back();
        }

        // For min deque (dq2)
        while (!dq2.empty() && nums[i] <= nums[dq2.back()]) {
            dq2.pop_back();
        }

        // Insert current index
        dq1.push_back(i);
        dq2.push_back(i);

        // ---- ADD RESULT OF CURRENT WINDOW ----
        ans += nums[dq1.front()] + nums[dq2.front()];
    }

    return ans;
}

// =====================================================================
// MAIN FUNCTION — TESTING
// =====================================================================
int main() {

    vector<int> v{2, 5, -1, 7, -3, -1, -2};
    int k = 4;

    // Expected calculation per window:
    // Window [2,5,-1,7]     → max = 7,  min = -1   → 6
    // Window [5,-1,7,-3]    → max = 7,  min = -3   → 4
    // Window [-1,7,-3,-1]   → max = 7,  min = -3   → 4
    // Window [7,-3,-1,-2]   → max = 7,  min = -3   → 4
    // Total = 6 + 4 + 4 + 4 = 18

    cout << sumOfMinMaxAllWindowOfSizek(v, k);

    return 0;
}
