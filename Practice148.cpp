#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

// Helper function: tries to serve customers one by one using backtracking
// counts    → frequencies of each unique number available
// quantity  → array of required quantities for each customer
// ithCustomer → index of the current customer we are trying to serve
bool canDistributeHelper(vector<int>& counts, vector<int>& quantity, int ithCustomer) {
    // --- Base Case ---
    // If we've reached beyond the last customer,
    // it means all customers have been served successfully.
    if (ithCustomer == quantity.size()) {
        return true;
    }

    // Try to serve the ith customer using each available count
    for (int i = 0; i < counts.size(); ++i) {
        // If we have enough items of this type to serve this customer
        if (counts[i] >= quantity[ithCustomer]) {
            // Choose: allocate items to this customer
            counts[i] -= quantity[ithCustomer];

            // Recurse: try to serve the next customer
            if (canDistributeHelper(counts, quantity, ithCustomer + 1)) {
                return true; // Found a valid distribution
            }

            // Backtrack: undo the allocation and try another option
            counts[i] += quantity[ithCustomer];
        }
    }

    // If no allocation worked, return false
    return false;
}

// Main function to check if all customers can be served
bool canDistribute(vector<int>& nums, vector<int>& quantity) {
    unordered_map<int, int> countMap;

    // Step 1: Count frequency of each unique number in nums
    // Example: nums = {1,2,2,3} → countMap = {1:1, 2:2, 3:1}
    for (int num : nums) {
        countMap[num]++;
    }

    // Step 2: Store frequencies in a vector
    vector<int> counts;
    for (auto& entry : countMap) {
        counts.push_back(entry.second);
    }

    // Step 3: Sort customer demands in descending order
    // Why? → Serve larger demands first (optimization: prune early if impossible)
    sort(quantity.rbegin(), quantity.rend());

    // Step 4: Try to distribute using backtracking
    return canDistributeHelper(counts, quantity, 0);
}

int main() {
    // Example input:
    // We have items {1,2,3,4} → frequencies = {1:1, 2:1, 3:1, 4:1}
    // Customers want quantities {2,1}
    vector<int> nums = {1, 2, 3, 4}; // Available items
    vector<int> quantity = {2, 1};   // Required quantities for each customer

    // Check if distribution is possible
    if (canDistribute(nums, quantity)) {
        cout << "All customers can be served with the available items." << endl;
    } else {
        cout << "Not all customers can be served with the available items." << endl;
    }

    return 0;
}
