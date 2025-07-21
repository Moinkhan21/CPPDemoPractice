#include <iostream>     // For standard input/output stream
#include <vector>       // For using std::vector container
#include <algorithm>    // For std::sort function
#include <set>          // For using std::set to store unique pairs
using namespace std;

/*
--------------------------------------------------------------
Function: findUniqueKDiffPairs
Purpose:
    Finds all unique pairs (i, j) such that:
        - i ≠ j
        - abs(nums[i] - nums[j]) == k
        - Each pair is unique
Parameters:
    nums - a reference to the input vector of integers
    k    - the difference between the pair elements
Returns:
    A set of unique pairs with absolute difference k
--------------------------------------------------------------
*/
set<pair<int, int>> findUniqueKDiffPairs(vector<int>& nums, int k) {
    set<pair<int, int>> uniquePairs; // To store unique pairs with difference k

    // Edge Case: No valid pairs if k is negative
    if (k < 0) return uniquePairs;

    // Step 1: Sort the array to enable two-pointer technique
    sort(nums.begin(), nums.end());

    // Step 2: Initialize two pointers for scanning
    int i = 0, j = 1;
    int n = nums.size(); // Total number of elements in the array

    // Step 3: Use two-pointer technique to find valid pairs
    while (j < n) {
        int diff = nums[j] - nums[i]; // Calculate the difference between elements

        if (diff == k) {
            // Valid k-diff pair found, insert into set
            uniquePairs.insert({nums[i], nums[j]});
            i++;
            j++;
        } else if (diff > k) {
            // Difference is too large, move left pointer to reduce difference
            i++;
        } else {
            // Difference is too small, move right pointer to increase difference
            j++;
        }

        // Ensure i and j are not pointing to the same index
        if (i == j) j++;
    }

    // Step 4: Return the set containing all unique valid pairs
    return uniquePairs;
}

/*
--------------------------------------------------------------
Main Function
Purpose:
    Demonstrates how findUniqueKDiffPairs works
    Prints all valid pairs and their total count
--------------------------------------------------------------
*/
int main() {
    // Sample input array and target difference
    vector<int> nums = {3, 1, 4, 1, 5}; 
    int k = 2;

    // Call the function to find unique k-diff pairs
    set<pair<int, int>> resultPairs = findUniqueKDiffPairs(nums, k);

    // Output the count of unique pairs
    cout << "Number of unique k-diff pairs: " << resultPairs.size() << endl;

    // Output each unique pair from the result set
    cout << "Pairs with difference " << k << ":" << endl;
    for (const auto& p : resultPairs) {
        cout << "(" << p.first << ", " << p.second << ")" << endl;
    }

    return 0;
}
