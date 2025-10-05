#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*
    Helper function to generate all unique permutations of nums.
    Uses recursion and backtracking with a hash map to skip duplicates.
*/
void permuteUniqueHelper(vector<int>& nums, vector<vector<int>>& ans, int start) {
    // --- Base case ---
    // If we've reached the end of the array, we have formed a valid permutation
    if(start >= nums.size()) {
        ans.push_back(nums); // Save the current permutation
        return;
    }

    // Hash map to track which elements have been used at the current recursive level
    // This ensures we do not repeat the same number in the same position (skip duplicates)
    unordered_map<int, bool> visited;

    // Iterate over each element that can be swapped into the current position
    for(int i = start; i < nums.size(); i++) {
        // If nums[i] has already been used at this recursion level, skip it
        if(visited.find(nums[i]) != visited.end()) {
            continue; // Skip duplicate element
        }

        // Mark nums[i] as used for this level
        visited[nums[i]] = true;

        // Swap nums[start] with nums[i] to fix nums[i] at the current "start" position
        swap(nums[start], nums[i]);

        // Recurse for the next position
        permuteUniqueHelper(nums, ans, start + 1);

        // Backtrack: undo the swap to restore the original array for the next iteration
        swap(nums[start], nums[i]);
    }
}

/*
    Main function that initializes recursion for generating unique permutations.
*/
vector<vector<int>> permuteUnique(vector<int>& nums) {
    vector<vector<int>> ans;   // To store all unique permutations
    permuteUniqueHelper(nums, ans, 0); // Start recursion from index 0
    return ans;
}

int main() {
    // Example input array with duplicates
    vector<int> nums = {1, 1, 2};

    // Get all unique permutations
    vector<vector<int>> result = permuteUnique(nums);

    // Print the result
    cout << "Unique permutations:\n";
    for(const auto& perm : result) {
        for(int num : perm) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}
