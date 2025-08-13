#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

static bool myComp(const string& a, const string& b) {
    return a > b;
}

string largestNumber(vector<int>& nums){
    vector<string> snums;
    for(auto n: nums){
        snums.push_back(to_string(n));
    }

    // sort(snums.begin(), snums.end());
    sort(snums.begin(), snums.end(), myComp);

    string result = "";
    // for(int i = snums.size() - 1; i >= 0; i--){
    //     result += snums[i];
    // }

    for(auto& s: snums){
        result += s;
    }

    return result;
}

int main() {
    vector<int> nums = {1, 2, 3, 5, 4};
    cout << largestNumber(nums) << endl;
    return 0;
}