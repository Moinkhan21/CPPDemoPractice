#include <iostream>   // For input/output (cin, cout)
#include <vector>     // For using std::vector
using namespace std;

/*
 Function: robHelper
 -------------------
 A recursive helper function to solve the "House Robber" problem.

 Parameters:
 - nums : reference to a vector containing the money in each house
 - i    : current index (house number)

 Idea:
 - At each house, you have 2 choices:
   1. Rob this house → you get nums[i] + rob from (i + 2)
   2. Skip this house → you get rob from (i + 1)
 - The maximum of these two choices is the optimal answer.

 Base case:
 - If 'i' goes out of bounds (>= nums.size()), return 0 (no houses left).
*/
int robHelper(vector<int>& nums, int i) {
    // ✅ Base case: no houses left to rob
    if(i >= nums.size()) {
        return 0;
    }

    // ✅ Choice 1: Rob current house and move to i + 2 (skip adjacent house)
    int robAmt1 = nums[i] + robHelper(nums, i + 2);

    // ✅ Choice 2: Skip current house and move to i + 1
    int robAmt2 = 0 + robHelper(nums, i + 1);

    // ✅ Take the maximum profit between robbing or skipping this house
    return max(robAmt1, robAmt2);
}

/*
 Function: rob
 -------------
 Wrapper function that starts recursion from the first house.
*/
int rob(vector<int>& nums) {
    return robHelper(nums, 0);
}

int main() {
    // Example: money in each house
    vector<int> nums{2, 7, 9, 3, 1};

    // Call the rob function
    int ans = rob(nums);

    // Print the maximum amount that can be robbed
    cout << "Maximum money robbed: " << ans << endl;

    return 0;
}
