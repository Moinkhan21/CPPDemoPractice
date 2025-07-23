#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
 * Function to check if it is possible to place `k` cows in the stalls
 * such that the minimum distance between any two cows is at least `mid`.
 */
bool isPossibleSolution(const vector<int> &stalls, int k, int mid) {
    int count = 1; // Place the first cow in the first stall
    int lastPos = stalls[0]; // Last placed cow's position

    for (int i = 1; i < stalls.size(); i++) {
        // If the current stall is at least 'mid' away from the last placed cow
        if (stalls[i] - lastPos >= mid) {
            count++; // Place another cow
            lastPos = stalls[i]; // Update last position

            if (count == k) {
                return true; // Successfully placed all cows
            }
        }
    }

    // Couldn't place all cows with at least 'mid' distance
    return false;
}

/*
 * Function to solve the Aggressive Cows problem.
 * It returns the largest minimum distance possible between any two cows.
 */
int aggressiveCows(int n, int k, vector<int> &stalls) {
    // Step 1: Sort the stalls to check valid distances
    sort(stalls.begin(), stalls.end());

    int start = 0; // Minimum possible distance
    int end = stalls[n - 1] - stalls[0]; // Maximum possible distance
    int ans = -1; // Store the best answer found so far

    // Step 2: Apply Binary Search on the answer space (distance)
    while (start <= end) {
        int mid = start + (end - start) / 2;

        // Step 3: Check if it's possible to place all cows with at least 'mid' distance
        if (isPossibleSolution(stalls, k, mid)) {
            ans = mid;       // Valid answer found, try to find a better (larger) one
            start = mid + 1; // Try for a bigger distance
        } else {
            end = mid - 1;   // Try for a smaller distance
        }
    }

    return ans; // Return the largest minimum distance found
}

// Example usage
int main() {
    int n = 5; // Number of stalls
    int k = 3; // Number of cows
    vector<int> stalls = {1, 2, 8, 4, 9};

    int result = aggressiveCows(n, k, stalls);
    cout << "The largest minimum distance is: " << result << endl;

    return 0;
}
