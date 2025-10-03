#include <iostream>
#include <vector>
using namespace std;

// Recursive helper function for generating all unique combinations
// candidates: input list of numbers
// target: remaining sum we need to achieve
// v: current combination being built
// ans: stores all valid combinations
// index: current index in candidates array
void combinationSumHelper(vector<int>& candidates, int target, vector<int>& v, vector<vector<int>>& ans, int index) {
    // --- Base Cases ---
    if(target == 0) {
        // Found a valid combination → add it to the answer list
        ans.push_back(v);
        return;
    }
    if(target < 0) {
        // Overshot the target → stop exploring this path
        return;
    }

    // --- Recursive Exploration ---
    for(int i = index; i < candidates.size(); i++) {
        // Skip duplicate values at the same recursive level
        // (This ensures unique combinations in the result)
        if(i > index && candidates[i] == candidates[i - 1]) {
            continue;
        }

        // Choose the current element
        v.push_back(candidates[i]);

        // Explore further with reduced target
        // i + 1 → because each number can only be used once
        combinationSumHelper(candidates, target - candidates[i], v, ans, i + 1);

        // Backtrack → remove the last chosen element
        // (So we can try other candidates in the next iteration)
        v.pop_back();
    }
}

// Main function to generate all unique combinations that sum up to target
vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> ans; // Stores all combinations
    vector<int> v;           // Current combination
    combinationSumHelper(candidates, target, v, ans, 0);
    return ans;
}

int main() {
    vector<int> candidates = {2, 3, 2, 6, 7}; // Input numbers (can contain duplicates)
    int target = 7;                           // Desired target sum

    // Get all valid combinations
    vector<vector<int>> result = combinationSum(candidates, target);

    // Print result
    cout << "Combinations that sum to " << target << ":\n";
    for (const auto& combination : result) {
        cout << "[ ";
        for (int num : combination) {
            cout << num << " ";
        }
        cout << "]\n";
    }

    return 0;
}
