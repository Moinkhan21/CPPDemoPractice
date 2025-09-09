#include <iostream>     // For standard input/output
#include <vector>       // For using vector container
#include <climits>      // For INT_MIN (smallest integer value)
using namespace std;

// Recursive function to find the maximum sum of non-adjacent elements
int solve(vector<int>& arr, int i, int sum, int &maxi) {
    // Base case: if index goes out of array bounds
    if (i >= arr.size()) {
        // Update the global maximum if current sum is greater
        maxi = max(sum, maxi);
        return maxi;
    }

    // ----------------------
    // Choice 1: Include arr[i]
    // If we include arr[i], we must skip the next element (move by 2 steps)
    solve(arr, i + 2, sum + arr[i], maxi);

    // Choice 2: Exclude arr[i]
    // If we don't include arr[i], simply move to the next element
    solve(arr, i + 1, sum, maxi);

    // Note: Function updates maxi reference, so no need to return explicitly here.
}

int main() {
    // Input array
    vector<int> arr{2, 1, 4, 9};

    int sum = 0;                // Keeps track of current sum during recursion
    int maxi = INT_MIN;         // Stores the maximum sum found (initialized to minimum possible)

    int i = 0;                  // Start recursion from index 0
    solve(arr, i, sum, maxi);   // Recursive call to solve the problem

    // Print final result
    cout << "Maximum sum of non-adjacent elements is: " << maxi << endl;

    return 0; // End of program
}
