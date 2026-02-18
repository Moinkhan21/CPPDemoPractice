#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

// =====================================================
// FUNCTION: minSubArrayLen
// -----------------------------------------------------
// PROBLEM:
//   Given an array of positive integers nums and a target,
//   find the minimal length of a contiguous subarray
//   such that sum ≥ target.
//
//   If no such subarray exists, return 0.
//
// EXAMPLE:
//   nums = [2,3,1,2,4,3], target = 7
//   Output = 2   (subarray [4,3])
//
// APPROACH: SLIDING WINDOW (VARIABLE SIZE)
//
// IDEA:
//   • Expand window by moving 'j'
//   • Once sum >= target → shrink window from 'i'
//   • Maintain minimum length
//
// WHY SLIDING WINDOW?
//   • All elements are positive → sum always increases
//   • So we can safely shrink window when condition met
//
// TIME COMPLEXITY:
//   • O(N) → each element visited at most twice
//
// SPACE COMPLEXITY:
//   • O(1)
// =====================================================
int minSubArrayLen(int target, vector<int>& nums) {

    int i = 0;            // Left pointer (start of window)
    int j = 0;            // Right pointer (end of window)
    int sum = 0;          // Current window sum
    int len = INT_MAX;    // Minimum length

    // -------------------------------------------------
    // Expand window using j pointer
    // -------------------------------------------------
    while (j < nums.size()) {

        // Add current element into window
        sum += nums[j];

        // -------------------------------------------------
        // If condition satisfied, shrink window
        // -------------------------------------------------
        while (sum >= target) {

            // Update minimum length
            len = min(len, j - i + 1);

            // Remove left element and shrink window
            sum -= nums[i];
            i++;
        }

        // Move right pointer
        j++;
    }

    // If no valid subarray found
    if (len == INT_MAX)
        return 0;
    else
        return len;
}

// =====================================================
// MAIN FUNCTION
// =====================================================
int main() {

    vector<int> nums = {2, 3, 1, 2, 4, 3};
    int target = 7;

    int result = minSubArrayLen(target, nums);

    cout << "Minimum length subarray: " << result << endl;

    return 0;
}
