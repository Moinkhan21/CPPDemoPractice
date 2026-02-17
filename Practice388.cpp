#include <iostream>
#include <vector>
#include <deque>
using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {

    deque<int> dq; // stores indices
    vector<int> ans;

    // Edge cases
    if (nums.empty() || k == 0 || k > nums.size())
        return ans;

    // Process first window
    for (int i = 0; i < k; i++) {
        while (!dq.empty() && nums[dq.back()] < nums[i])
            dq.pop_back();

        dq.push_back(i);
    }

    // Store result for first window
    ans.push_back(nums[dq.front()]);

    // Process remaining windows
    for (int i = k; i < nums.size(); i++) {

        // Remove elements out of window
        if (!dq.empty() && dq.front() <= i - k)
            dq.pop_front();

        // Remove smaller elements
        while (!dq.empty() && nums[dq.back()] < nums[i])
            dq.pop_back();

        dq.push_back(i);

        // Store result
        ans.push_back(nums[dq.front()]);
    }

    return ans;
}

// ===============================
// MAIN FUNCTION
// ===============================
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
