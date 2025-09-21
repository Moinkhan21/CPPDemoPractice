#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// ---------------- FUNCTION: solve ----------------
// Purpose: Find the minimum number of elements (from the array `arr`)
// required to sum up to a given `target`.  
// 
// Approach: Recursive exploration of all possibilities
//   - If target == 0 → solution found (0 elements needed).
//   - If target < 0 → invalid case (return large number to ignore).
//   - Otherwise, try subtracting each element from target recursively
//     and find the minimum count.
//
// Parameters:
//   arr    -> reference to vector containing available numbers
//   target -> the remaining sum we want to achieve
//
// Returns:
//   Minimum number of elements needed to reach `target`
//   (returns INT_MAX if it's not possible).
int solve(vector<int>& arr, int target) {

    // ---------- BASE CASE 1 ----------
    // If target becomes 0, no more elements are required.
    if(target == 0) {
        return 0;
    }

    // ---------- BASE CASE 2 ----------
    // If target becomes negative, this path is invalid.
    // Return INT_MAX to signal impossibility.
    if(target < 0) {
        return INT_MAX;
    }

    // ---------- RECURSIVE EXPLORATION ----------
    // Initialize mini as INT_MAX (acts as "infinity")
    // It will store the minimum number of elements among all possibilities.
    int mini = INT_MAX;

    // Try each element from arr as a candidate
    for(int i = 0; i < arr.size(); i++) {

        // Recursive call:
        // Try reducing target by arr[i]
        int ans = solve(arr, target - arr[i]);

        // If ans is valid (not INT_MAX),
        // then update mini with the minimum count found so far.
        // Add +1 because we are using one element (arr[i]).
        if(ans != INT_MAX)
            mini = min(mini, ans + 1);
    }

    // Return the minimum count found for this target
    return mini;
}

int main() {
    // ---------- INPUT SECTION ----------
    // Array of numbers we can use to sum up
    vector<int> arr{1, 2};

    // Target sum we want to achieve
    int target = 5;

    // ---------- FUNCTION CALL ----------
    // Call the recursive function to compute result
    int ans = solve(arr, target);

    // ---------- OUTPUT SECTION ----------
    // Print the answer
    // If ans == INT_MAX → no solution possible
    cout << "Answer: " << ans << endl;

    return 0;
}
