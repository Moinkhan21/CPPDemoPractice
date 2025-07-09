#include <iostream>
#include <vector>
using namespace std;

/**
 * Function: firstOccurence
 * -------------------------
 * Uses binary search to find the first (leftmost) occurrence of a target value
 * in a sorted vector.
 *
 * Parameters:
 * - v: A sorted vector of integers
 * - target: The value to find
 *
 * Returns:
 * - The index of the first occurrence of the target value, or -1 if not found
 */
int firstOccurence(vector<int> v, int target) {
    int s = 0;                 // Start index
    int e = v.size() - 1;      // End index
    int mid = s + (e - s) / 2; // Initial mid-point (avoids overflow)
    int ans = -1;              // Initialize answer to -1 (not found yet)

    // Standard binary search loop
    while (s <= e) {
        if (v[mid] == target) {
            // Target found, store this index as a potential answer
            ans = mid;

            // Move search space to the left to find earlier occurrence
            e = mid - 1;
        }
        else if (target > v[mid]) {
            // Target is on the right side
            s = mid + 1;
        }
        else { // (target < v[mid])
            // Target is on the left side
            e = mid - 1;
        }

        // Recalculate mid for next iteration
        mid = s + (e - s) / 2;
    }

    // Return the first occurrence index or -1 if not found
    return ans;
}

int main() {
    // Sample sorted vector
    vector<int> v{1, 3, 4, 4, 4, 4, 6, 7};

    // Target value to search for
    int target = 4;

    // Call the function and store the result
    int indexOfFirstOcc = firstOccurence(v, target);

    // Print the result
    cout << "First occurrence of " << target << " is at index: " << indexOfFirstOcc << endl;

    return 0; // Indicate successful execution
}
