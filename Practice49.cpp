#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

// ---------------------------------------------
// Function: binarySearch
// Searches for element 'x' in the vector 'nums'
// starting from index 'start' to the end of vector.
// Returns index if found, otherwise -1.
// ---------------------------------------------
int binarySearch(const vector<int>& nums, int start, int x) {
    int end = nums.size() - 1;

    while (start <= end) {
        int mid = start + (end - start) / 2;

        if (nums[mid] == x) {
            return mid; // Element found
        } else if (x > nums[mid]) {
            start = mid + 1; // Move to right sub-array
        } else {
            end = mid - 1; // Move to left sub-array
        }
    }

    return -1; // Element not found
}

// ---------------------------------------------
// Function: findUniqueKDiffPairs
// Purpose: Finds the number of unique k-diff pairs
//          in the array. A k-diff pair is a pair (i, j)
//          such that i != j and abs(nums[i] - nums[j]) == k.
// Params: 
//   nums - input array
//   k - target difference value
//   uniquePairs - a reference to a set to store result pairs
// Returns: number of unique k-diff pairs
// ---------------------------------------------
int findUniqueKDiffPairs(vector<int>& nums, int k, set<pair<int, int>>& uniquePairs) {
    sort(nums.begin(), nums.end()); // Sort the array to enable binary search

    for (int i = 0; i < nums.size(); i++) {
        // Look for nums[i] + k in the sub-array to the right of i
        if (binarySearch(nums, i + 1, nums[i] + k) != -1) {
            // If found, insert into set to ensure uniqueness
            uniquePairs.insert({nums[i], nums[i] + k});
        }
    }

    return uniquePairs.size(); // Return total number of unique pairs
}

// ---------------------------------------------
// Main function to test the logic
// ---------------------------------------------
int main() {
    vector<int> nums = {3, 1, 4, 1, 5}; // Input array
    int k = 2; // Desired difference

    set<pair<int, int>> uniquePairs; // Set to store unique pairs
    int result = findUniqueKDiffPairs(nums, k, uniquePairs); // Find result

    cout << "Number of unique k-diff pairs: " << result << endl;

    // Display the unique pairs found
    cout << "The unique pairs are: ";
    for (const auto& pair : uniquePairs) {
        cout << "(" << pair.first << ", " << pair.second << ") ";
    }
    cout << endl;

    return 0;
}
