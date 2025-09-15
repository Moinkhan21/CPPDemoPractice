#include <iostream>
#include <vector>
using namespace std;

// Utility function to print all subarrays starting from 'start' and ending at 'end'
void printSubarray_util(vector<int> &nums, int start, int end) {
    // --- Base case ---
    if(end == nums.size()) {
        // If 'end' index goes beyond array size, stop recursion
        return;
    }

    // --- Solve one case ---
    // Print the subarray from index 'start' to 'end'
    for(int i = start; i <= end; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    // --- Recursive call ---
    // Expand the subarray by moving 'end' one step forward
    printSubarray_util(nums, start, end + 1);
}

// Function to generate all subarrays
void printSubarray(vector<int> &nums) {
    // Fix the starting index of subarray
    for(int start = 0; start < nums.size(); start++) {
        // For each start, call utility to expand end index
        int end = start;
        printSubarray_util(nums, start, end);
    }
}

int main() {
    vector<int> nums{1, 2, 3, 4, 5}; // Example input array

    // Print all subarrays
    printSubarray(nums);
    return 0;
}
