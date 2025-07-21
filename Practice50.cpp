#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

/*
--------------------------------------------------------------
Function: findUniqueKDiffPairs
Purpose:  Finds the number of unique k-diff pairs in the array.
          A k-diff pair is defined as (nums[i], nums[j]) where:
          - i ≠ j
          - abs(nums[i] - nums[j]) == k
          - Each pair must be unique and unordered duplicates are ignored.
Params:
    nums - the input array of integers
    k    - the target difference between two numbers
Returns:
    The number of unique k-diff pairs in the array.
--------------------------------------------------------------
*/
int findUniqueKDiffPairs(vector<int>& nums, int k) {
    if (k < 0) return 0; // No valid pair if k is negative (abs() ensures positive diff)

    // Step 1: Sort the array to make it easier to find pairs and skip duplicates
    sort(nums.begin(), nums.end());

    // Step 2: Set to store unique pairs (automatically handles duplicate pairs)
    set<pair<int, int>> uniquePairs;

    // Step 3: Two-pointer approach
    int i = 0, j = 1;
    int n = nums.size();

    while (j < n) {
        int diff = nums[j] - nums[i];

        if (diff == k) {
            // Valid k-diff pair found
            uniquePairs.insert({nums[i], nums[j]});
            i++;
            j++;
        } else if (diff > k) {
            // If difference is greater than k, move the left pointer to reduce the diff
            i++;
        } else {
            // If difference is smaller than k, move the right pointer to increase the diff
            j++;
        }

        // Ensure that j is always ahead of i
        if (i == j) {
            j++;
        }
    }

    // Step 4: Return the total count of unique k-diff pairs
    return uniquePairs.size();
}

/*
--------------------------------------------------------------
Main Function
Tests the findUniqueKDiffPairs function with sample input
--------------------------------------------------------------
*/
int main() {
    vector<int> nums = {3, 1, 4, 1, 5}; // Sample array
    int k = 2; // Target difference value

    int result = findUniqueKDiffPairs(nums, k); // Call functional method

    cout << "Number of unique k-diff pairs: " << result << endl;

    return 0;
}
