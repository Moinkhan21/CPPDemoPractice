#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

// =====================================
// Function: Minimum Size Subarray Sum
// =====================================
int minSubArrayLen(int target, vector<int>& nums) {

    int i = 0;
    int j = 0;
    int sum = 0;
    int len = INT_MAX;

    while (j < nums.size()) {

        // Include current element
        sum += nums[j];

        // Shrink window while sum >= target
        while (sum >= target) {
            len = min(len, j - i + 1);
            sum -= nums[i];
            i++;
        }

        j++;
    }

    if (len == INT_MAX)
        return 0;
    else
        return len;
}

// ===============================
// MAIN FUNCTION
// ===============================
int main() {

    vector<int> nums = {2, 3, 1, 2, 4, 3};
    int target = 7;

    int result = minSubArrayLen(target, nums);

    cout << "Minimum length subarray: " << result << endl;

    return 0;
}
