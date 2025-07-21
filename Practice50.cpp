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
          - Each pair must be unique (no duplicates)
Params:
    nums - the input array of integers
    k    - the target difference between two numbers
Returns:
    A set of unique pairs where the absolute difference is k
--------------------------------------------------------------
*/
set<pair<int, int>> findUniqueKDiffPairs(vector<int>& nums, int k) {
    set<pair<int, int>> uniquePairs;

    if (k < 0) return uniquePairs; // Negative difference is not allowed

    // Step 1: Sort the array to allow efficient two-pointer traversal
    sort(nums.begin(), nums.end());

    // Step 2: Use two pointers
    int i = 0, j = 1;
    int n = nums.size();

    while (j < n) {
        int diff = nums[j] - nums[i];

        if (diff == k) {
            // Found a valid pair with difference k
            uniquePairs.insert({nums[i], nums[j]});
            i++;
            j++;
        } else if (diff > k) {
            // Too large, move the left pointer to reduce difference
            i++;
        } else {
            // Too small, move the right pointer to increase difference
            j++;
        }

        // Ensure j is always ahead of i to avoid comparing the same element
        if (i == j) {
            j++;
        }
    }

    return uniquePairs; // Return the set of valid unique pairs
}

/*
--------------------------------------------------------------
Main Function
Tests the findUniqueKDiffPairs function and displays pairs
--------------------------------------------------------------
*/
int main() {
    vector<int> nums = {3, 1, 4, 1, 5}; // Sample array
    int k = 2; // Target k-diff

    // Call the function and get all unique k-diff pairs
    set<pair<int, int>> resultPairs = findUniqueKDiffPairs(nums, k);

    // Display the number of pairs found
    cout << "Number of unique k-diff pairs: " << resultPairs.size() << endl;

    // Display each unique pair
    cout << "Pairs with difference " << k << ":" << endl;
    for (const auto& p : resultPairs) {
        cout << "(" << p.first << ", " << p.second << ")" << endl;
    }

    return 0;
}
