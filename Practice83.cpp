#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

static bool myComp(const string& a, const string& b) {
    string t1 = a + b;
    string t2 = b + a;
    return t1 > t2;
}

string largestNumber(vector<int>& nums){
    vector<string> snums;
    for(auto n: nums){
        snums.push_back(to_string(n));
    }

    // sort(snums.begin(), snums.end());
    sort(snums.begin(), snums.end(), myComp);

    if(snums[0] == "0") return "0"; // Handle case where all numbers are zero

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
    vector<int> nums = { 3, 30, 34, 5, 9 };
    cout << largestNumber(nums) << endl;
    return 0;
}