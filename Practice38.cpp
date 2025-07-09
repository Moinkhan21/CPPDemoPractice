#include <iostream>
#include <vector>
using namespace std;

/**
 * Function: lastOcc
 * ------------------
 * Uses binary search to find the last (rightmost) occurrence of a target value in a sorted vector.
 *
 * Parameters:
 *  - v: The input vector of integers (must be sorted)
 *  - target: The value to find
 *
 * Returns:
 *  - The index of the last occurrence of the target, or -1 if not found
 */
int lastOcc(vector<int> v, int target) {
    int s = 0; // Start index of search
    int e = v.size() - 1; // End index of search
    int mid = s + (e - s) / 2; // Calculate mid-point to avoid overflow
    int ans = -1; // Initialize answer variable to -1 (not found)

    // Binary search loop
    while (s <= e) {
        // If the middle element is equal to the target
        if (v[mid] == target) {
            ans = mid;         // Store the index as a potential answer
            s = mid + 1;       // Move right to find a later occurrence
        }
        // If target is greater, ignore the left half
        else if (target > v[mid]) {
            s = mid + 1;
        }
        // If target is smaller, ignore the right half
        else {
            e = mid - 1;
        }

        // Recalculate mid for the next iteration
        mid = s + (e - s) / 2;
    }

    // Return the last occurrence index or -1 if not found
    return ans;
}

int main() {
    // Sample input vector (must be sorted for binary search to work)
    vector<int> v{1, 3, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 9};
    int target = 7;

    // Call the function and store result
    int ans = lastOcc(v, target);

    // Print the result
    cout << "Last occurrence of " << target << " is at index: " << ans << endl;

    return 0; // Indicate successful execution
}
