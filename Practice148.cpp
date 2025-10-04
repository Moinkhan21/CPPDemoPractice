#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

bool canDistributeHelper(vector<int>& counts, vector<int>& quantity, int ithCustomer) {
    //Base case
    if(ithCustomer == quantity.size()) {
        return true; // All customers have been successfully served
    }

    for(int i = 0; i < counts.size(); ++i){
        if(counts[i] >= quantity[ithCustomer]){
            counts[i] -= quantity[ithCustomer]; // Serve this customer
            if(canDistributeHelper(counts, quantity, ithCustomer + 1)) {
                return true; // Successfully served all customers
            }
            counts[i] += quantity[ithCustomer]; // Backtrack
        }
    }
    return false; // Unable to serve this customer with current distribution
}

bool canDistribute(vector<int>& nums, vector<int>& quantity){
    unordered_map<int, int> countMap;
    for(int num : nums) {
        countMap[num]++;
    }
    vector<int> counts;
    for(auto& entry : countMap) {
        counts.push_back(entry.second);
    }
    sort(quantity.rbegin(), quantity.rend()); // Sort in descending order for optimization
    return canDistributeHelper(counts, quantity, 0);
}

int main() {
    vector<int> nums = {1, 2, 3, 4}; // Available items
    vector<int> quantity = {2, 1};   // Required quantities for each customer

    if(canDistribute(nums, quantity)) {
        cout << "All customers can be served with the available items." << endl;
    } else {
        cout << "Not all customers can be served with the available items." << endl;
    }

    return 0;
}