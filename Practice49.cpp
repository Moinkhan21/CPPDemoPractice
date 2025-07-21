#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

// ----------------------------------------------------------
// Function: binarySearch
// Purpose: Performs binary search to find element 'x' in a
//          sorted vector 'nums' starting from index 'start'.
// Input:
//    - nums: The sorted vector to search in
//    - start: The starting index to search from
//    - x: The element to be found
// Returns:
//    - Index of 'x' if found, otherwise -1
// ----------------------------------------------------------
int binarySearch(const vector<int>& nums, int start, int x) {
    int end = nums.size() - 1;  // Set the search boundary to the end of the vector

    while (start <= end) {
        int mid = start + (end - start) / 2;  // Prevent integer overflow

        if (nums[mid] == x) {
            return mid;  // Element found at index 'mid'
        } else if (x > nums[mid]) {
            start = mid + 1;  // Move to right half if target is greater
        } else {
            end = mid - 1;  // Move to left half if target is smaller
        }
    }

    return -1;  // Element not found
}

// -------------------------------------------------------------------
// Function: findUniqueKDiffPairs
// Purpose: Finds all unique k-diff pairs in the array.
// A k-diff pair is defined as (a, b) such that:
//     1. a and b are elements of the array
//     2. a != b
//     3. |a - b| == k
// Parameters:
//    - nums: The input array of integers
//    - k: The difference value to look for
//    - uniquePairs: A reference to a set that stores the unique pairs
// Returns:
//    - Total number of unique k-diff pairs found
// -------------------------------------------------------------------
int findUniqueKDiffPairs(vector<int>& nums, int k, set<pair<int, int>>& uniquePairs) {
    // Step 1: Sort the array to make binary search feasible
    sort(nums.begin(), nums.end());

    // Step 2: Traverse the sorted array
    for (int i = 0; i < nums.size(); i++) {
        // Step 3: Check if nums[i] + k exists in the right side of the array
        // This avoids counting same elements and duplicates
        if (binarySearch(nums, i + 1, nums[i] + k) != -1) {
            // Step 4: If found, insert the pair into set to ensure uniqueness
            uniquePairs.insert({nums[i], nums[i] + k});
        }
    }

    // Step 5: Return the total number of unique k-diff pairs
    return uniquePairs.size();
}

// ----------------------------------------------------------
// Main Function: Entry point of the program
// Demonstrates how to use the above functions
// ----------------------------------------------------------
int main() {
    // Input array containing duplicate and unordered values
    vector<int> nums = {3, 1, 4, 1, 5};

    // The required difference between pair elements
    int k = 2;

    // Set to store all unique (a, b) pairs with |a - b| == k
    set<pair<int, int>> uniquePairs;

    // Call the function to find total number of unique k-diff pairs
    int result = findUniqueKDiffPairs(nums, k, uniquePairs);

    // Output the number of pairs found
    cout << "Number of unique k-diff pairs: " << result << endl;

    // Display each unique pair found
    cout << "The unique pairs are: ";
    for (const auto& pair : uniquePairs) {
        cout << "(" << pair.first << ", " << pair.second << ") ";
    }
    cout << endl;

    return 0;  // Indicate successful execution
}
