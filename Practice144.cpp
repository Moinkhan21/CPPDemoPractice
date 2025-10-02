#include <iostream>
#include <vector>
using namespace std;

void combinationSumHelper(vector<int>& candidates, int target, vector<int>&v, vector<vector<int>>&ans, int index){
    //Basecase
    if(target == 0){
        ans.push_back(v);
        return;
    }
    if(target < 0) return;

    for(int i = index; i < candidates.size(); i++){
        v.push_back(candidates[i]);
        combinationSumHelper(candidates, target - candidates[i], v, ans, i); // not i+1 because we can reuse same elements
        v.pop_back();
    }
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> ans;
    vector<int> v;
    combinationSumHelper(candidates, target, v, ans, 0);
    return ans;
}

int main() {
    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;
    vector<vector<int>> result = combinationSum(candidates, target);

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