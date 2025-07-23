#include <iostream>
#include <numeric> // For accumulate (if used)
using namespace std;

/*
 * Function: isPossibleSolution
 * ----------------------------
 * This function checks if it's possible to paint all boards using at most 'k' painters
 * such that the maximum time taken by any painter does not exceed 'mid'.
 *
 * Parameters:
 * - a[]: Array representing lengths of boards
 * - n: Number of boards
 * - k: Number of painters
 * - mid: Maximum allowed time per painter (we're trying to minimize this)
 *
 * Returns:
 * - true if it's possible to paint all boards under the 'mid' time limit using <= k painters
 * - false otherwise
 */
bool isPossibleSolution(int a[], int n, int k, long long mid) {
    long long timeSum = 0;  // Tracks the current total time assigned to a single painter
    int c = 1;              // Counter for the number of painters used (starts with the first painter)

    for(int i = 0; i < n; i++) {
        // If a board is longer than 'mid', then it's impossible to assign it under the current mid constraint
        if(a[i] > mid) {
            return false;
        }

        // If adding the current board exceeds the allowed time (mid) for this painter
        if(timeSum + a[i] > mid) {
            c++;            // We need an additional painter
            timeSum = a[i]; // Assign the current board to the new painter

            // If painters required exceed the limit 'k', this setup isn't feasible
            if(c > k) {
                return false;
            }
        } else {
            // If it doesn't exceed the time, assign the board to current painter
            timeSum += a[i];
        }
    }

    // All boards can be painted within the given constraints
    return true;
}

/*
 * Function: minTime
 * -----------------
 * Uses binary search to find the minimum amount of time needed to paint all boards using 'k' painters.
 *
 * The idea is to minimize the maximum time taken by any painter by trying out mid-values using binary search.
 * 
 * Parameters:
 * - arr[]: Array representing lengths of boards
 * - n: Number of boards
 * - k: Number of painters
 *
 * Returns:
 * - The minimum time in which all boards can be painted using 'k' painters
 */
long long minTime(int arr[], int n, int k) {
    long long start = 0;  // Lower bound of time
    long long end = 0;    // Upper bound of time (sum of all board lengths)

    // Compute the total sum of all board lengths
    for (int i = 0; i < n; i++) {
        end += arr[i]; // This is the maximum time if one painter paints all boards
    }

    long long ans = -1; // Store the best (minimum possible) time

    // Binary Search for the optimal (minimum) max-time allocation
    while(start <= end) {
        long long mid = start + (end - start) / 2; // Mid-point of current range

        // Check if we can paint all boards with this mid-time using at most k painters
        if (isPossibleSolution(arr, n, k, mid)) {
            ans = mid;       // Valid time found, try to find smaller one
            end = mid - 1;   // Narrow the search to smaller range
        } else {
            start = mid + 1; // Too little time, need more time, increase mid
        }
    }

    return ans; // Minimum time found using binary search
}

// ----------------------
// Example Usage
// ----------------------
int main() {
    int arr[] = {10, 20, 30, 40}; // Lengths of boards
    int n = sizeof(arr) / sizeof(arr[0]); // Number of boards
    int k = 2; // Number of painters available

    // Display the minimum time needed to paint all boards
    cout << "Minimum time to paint all boards: " << minTime(arr, n, k) << endl;

    return 0;
}
