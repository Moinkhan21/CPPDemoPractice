#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

// ---------------------------------------------
// Function: Binary Search
// Searches for element 'x' in the vector 'nums'
// starting from index 'start' to the end.
// Returns index if found, otherwise -1.
// ---------------------------------------------
int binarySearch(const vector<int>& nums, int start, int x) {
    int end = nums.size() - 1;

    while (start <= end) {
        int mid = start + (end - start) / 2;

        if (nums[mid] == x) {
            return mid; // Found x
        } else if (x > nums[mid]) {
            start = mid + 1; // Go to right half
        } else {
            end = mid - 1; // Go to left half
        }
    }

    return -1; // Not found
}

// ---------------------------------------------
// Function: findUniqueKDiffPairs
// Finds the number of unique k-diff pairs in the array.
// A k-diff pair is a pair (i, j) such that i != j and
// abs(nums[i] - nums[j]) == k.
// ---------------------------------------------
int findUniqueKDiffPairs(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end()); // Sort input array
    set<pair<int, int>> uniquePairs; // To store unique pairs

    for (int i = 0; i < nums.size(); i++) {
        // Look for nums[i] + k in the remaining part of the array
        if (binarySearch(nums, i + 1, nums[i] + k) != -1) {
            // If found, insert the pair into the set
            uniquePairs.insert({nums[i], nums[i] + k});
        }
    }

    return uniquePairs.size(); // Total unique pairs found
}

// ---------------------------------------------
// Main function to test the code
// ---------------------------------------------
int main() {
    vector<int> nums = {3, 1, 4, 1, 5};
    int k = 2;

    int result = findUniqueKDiffPairs(nums, k);
    cout << "Number of unique k-diff pairs: " << result << endl;

    return 0;
}
