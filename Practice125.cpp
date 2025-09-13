#include <iostream>
#include <vector>
using namespace std;

int robHelper(vector<int>& nums, int i) {
    //Base case
    if(i >= nums.size()) {
        return 0;
    }

    //solve only one solution
    int robAmt1 = nums[i] + robHelper(nums, i + 2);
    int robAmt2 = 0 + robHelper(nums, i + 1);

    return max(robAmt1, robAmt2);
}

int rob(vector<int>& nums) {
    return robHelper(nums, 0);
}

int main() {
    vector<int> nums{2, 7, 9, 3, 1};
    int ans = rob(nums);
    cout << ans << endl;
    return 0;
}