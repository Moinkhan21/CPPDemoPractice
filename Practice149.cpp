#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

void permuteUniqueHelper(vector<int>& nums, vector<vector<int>>& ans, int start) {
    // Base case
    if(start >= nums.size()) {
        ans.push_back(nums);
        return;
    }

    unordered_map<int, bool> visited;
    for(int i = start; i < nums.size(); i++) {
        if(visited.find(nums[i]) != visited.end()) {
            continue; // Skip duplicates
        }
        visited[nums[i]] = true;
        swap(nums[start], nums[i]);
        permuteUniqueHelper(nums, ans, start + 1);
        swap(nums[start], nums[i]); // Backtrack
    }
}

vector<vector<int>> permuteUnique(vector<int>& nums) {
    vector<vector<int>> ans;
    permuteUniqueHelper(nums, ans, 0);
    return ans;
}

int main() {
    vector<int> nums = {1, 1, 2}; // Input array (can contain duplicates)
    vector<vector<int>> result = permuteUnique(nums);

    // Print result
    cout << "Unique permutations:\n";
    for(const auto& perm : result) {
        for(int num : perm) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}