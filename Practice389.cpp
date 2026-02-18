#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// =====================================================
// FUNCTION: cmp (Comparator)
// -----------------------------------------------------
// PURPOSE:
//   Sort pairs based on their value (first element)
//
// WHY NEEDED?
//   • We convert array into (value, index)
//   • Then sort by value to apply two-pointer technique
// =====================================================
static bool cmp(pair<int, int> a, pair<int, int> b) {
    return a.first < b.first;
}

// =====================================================
// FUNCTION: twoSum
// -----------------------------------------------------
// PROBLEM:
//   Given an array nums and a target value,
//   return indices of two numbers such that:
//
//       nums[i] + nums[j] == target
//
// IMPORTANT:
//   • Return original indices (not sorted indices)
//
// APPROACH (SORT + TWO POINTER):
//   1️⃣ Store (value, index) pairs
//   2️⃣ Sort based on value
//   3️⃣ Use two pointers (start & end)
//   4️⃣ Move pointers based on sum comparison
//
// WHY THIS WORKS?
//   • Sorting allows efficient two-pointer traversal
//
// TIME COMPLEXITY:
//   • O(N log N) → due to sorting
//
// SPACE COMPLEXITY:
//   • O(N) → for storing pairs
// =====================================================
vector<int> twoSum(vector<int>& nums, int target) {

    vector<pair<int, int>> data;   // {value, original index}
    vector<int> ans;               // Stores result indices

    // -------------------------------------------------
    // STEP 1: Store value and index
    // -------------------------------------------------
    for (int i = 0; i < nums.size(); i++) {
        data.push_back({nums[i], i});
    }

    // -------------------------------------------------
    // STEP 2: Sort based on values
    // -------------------------------------------------
    sort(data.begin(), data.end(), cmp);

    // Two pointers
    int start = 0;
    int end = data.size() - 1;

    // -------------------------------------------------
    // STEP 3: Two Pointer Traversal
    // -------------------------------------------------
    while (start < end) {

        int sum = data[start].first + data[end].first;

        // Case 1: Found the target
        if (sum == target) {
            ans.push_back(data[start].second);
            ans.push_back(data[end].second);
            break;
        }

        // Case 2: Sum too large → decrease end
        else if (sum > target) {
            end--;
        }

        // Case 3: Sum too small → increase start
        else {
            start++;
        }
    }

    return ans;
}

// =====================================================
// MAIN FUNCTION
// =====================================================
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
