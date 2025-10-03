#include <iostream>
#include <vector>
using namespace std;

// Recursive helper function to generate all combinations
// candidates: input array of numbers
// target: the remaining sum we want to achieve
// v: current combination being formed
// ans: stores all valid combinations
// index: current index in the candidates array
void combinationSumHelper(vector<int>& candidates, int target, vector<int>& v, vector<vector<int>>& ans, int index) {
    // --- Base Cases ---
    if (target == 0) {
        // Found a valid combination → store it in result
        ans.push_back(v);
        return;
    }
    if (target < 0) {
        // Overshot the target → stop this path
        return;
    }

    // --- Recursive Exploration ---
    for (int i = index; i < candidates.size(); i++) {
        // Choose the current element
        v.push_back(candidates[i]);

        // Recursive call:
        // - Reduce target by candidates[i]
        // - Pass 'i' again instead of 'i+1'
        //   because we are allowed to reuse the same element multiple times
        combinationSumHelper(candidates, target - candidates[i], v, ans, i);

        // Backtrack: remove last chosen element to try other options
        v.pop_back();
    }
}

// Main function to find all combinations that sum to the target
vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> ans; // Stores final list of combinations
    vector<int> v;           // Temporary list for current combination
    combinationSumHelper(candidates, target, v, ans, 0);
    return ans;
}

int main() {
    vector<int> candidates = {2, 3, 6, 7}; // Input numbers
    int target = 7;                        // Desired sum

    // Get all possible combinations
    vector<vector<int>> result = combinationSum(candidates, target);

    // Print the result
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
