#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// ===============================
// Max Sliding Window Function
// ===============================
vector<int> maxSlidingWindow(vector<int>& nums, int k) {

    priority_queue<pair<int, int>> pq; // {value, index}
    vector<int> ans;

    // First window
    for (int i = 0; i < k; ++i) {
        pq.push({nums[i], i});
    }

    // Max of first window
    ans.push_back(pq.top().first);

    // Remaining windows
    for (int i = k; i < nums.size(); ++i) {
        pq.push({nums[i], i});

        // Remove elements outside current window
        while (!pq.empty() && pq.top().second <= i - k) {
            pq.pop();
        }

        ans.push_back(pq.top().first);
    }
    return ans;
}

// ===============================
// MAIN FUNCTION
// ===============================
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
