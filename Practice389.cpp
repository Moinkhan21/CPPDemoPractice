#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Comparator
static bool cmp(pair<int, int> a, pair<int, int> b) {
    return a.first < b.first;
}

// Two Sum Function
vector<int> twoSum(vector<int>& nums, int target) {

    vector<pair<int, int>> data;
    vector<int> ans;

    // Store value and index
    for (int i = 0; i < nums.size(); i++) {
        data.push_back({nums[i], i});
    }

    // Sort by value
    sort(data.begin(), data.end(), cmp);

    int start = 0;
    int end = data.size() - 1;

    while (start < end) {

        int sum = data[start].first + data[end].first;

        if (sum == target) {
            ans.push_back(data[start].second);
            ans.push_back(data[end].second);
            break;
        }
        else if (sum > target) {
            end--;
        }
        else {
            start++;
        }
    }

    return ans;
}

// ===============================
// MAIN FUNCTION
// ===============================
int main() {

    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    vector<int> result = twoSum(nums, target);

    if (result.size() == 2) {
        cout << "Indices: " << result[0] << ", " << result[1] << endl;
    } else {
        cout << "No valid pair found" << endl;
    }

    return 0;
}
