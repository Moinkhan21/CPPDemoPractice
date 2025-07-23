#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
 * Function: isPossibleSolution
 * ----------------------------
 * Checks whether it is possible to place 'k' cows in the stalls such that the 
 * minimum distance between any two cows is at least 'mid'.
 *
 * Parameters:
 * - stalls: sorted positions of the stalls
 * - k: number of cows to place
 * - mid: the minimum distance to be maintained between any two cows
 *
 * Returns:
 * - true if possible to place all k cows with at least 'mid' distance
 * - false otherwise
 */
bool isPossibleSolution(const vector<int> &stalls, int k, int mid) {
    int count = 1; // Place the first cow in the first stall
    int lastPos = stalls[0]; // Store the position of the last placed cow

    // Loop through the rest of the stalls to place remaining cows
    for (int i = 1; i < stalls.size(); i++) {
        // If the distance between current stall and last placed cow is >= mid
        if (stalls[i] - lastPos >= mid) {
            count++;            // Place another cow
            lastPos = stalls[i]; // Update the last cow's position

            // If we have successfully placed all cows, return true
            if (count == k) {
                return true;
            }
        }
    }

    // If not all cows could be placed with at least 'mid' distance
    return false;
}

/*
 * Function: aggressiveCows
 * ------------------------
 * Solves the "Aggressive Cows" problem using binary search.
 * The goal is to place 'k' cows in 'n' stalls such that the minimum distance 
 * between any two cows is as large as possible.
 *
 * Parameters:
 * - n: number of stalls
 * - k: number of cows
 * - stalls: vector containing positions of the stalls
 *
 * Returns:
 * - The largest possible minimum distance between any two cows
 */
int aggressiveCows(int n, int k, vector<int> &stalls) {
    // Step 1: Sort the stalls to make it easier to calculate distances
    sort(stalls.begin(), stalls.end());

    int start = 0; // Minimum possible value of the answer (smallest distance)
    int end = stalls[n - 1] - stalls[0]; // Maximum possible distance
    int ans = -1; // Initialize answer to store the best possible distance

    // Step 2: Apply binary search on the answer space
    while (start <= end) {
        int mid = start + (end - start) / 2; // Midpoint of current range

        // Step 3: Check if it's possible to place all cows with at least 'mid' distance
        if (isPossibleSolution(stalls, k, mid)) {
            ans = mid;         // Update answer as mid is a valid solution
            start = mid + 1;   // Try to find a larger minimum distance
        } else {
            end = mid - 1;     // Try to find a feasible smaller distance
        }
    }

    return ans; // Return the largest minimum distance found
}

/*
 * Main function:
 * --------------
 * Demonstrates the usage of the aggressiveCows function.
 */
int main() {
    int n = 5; // Number of stalls
    int k = 3; // Number of cows to place
    vector<int> stalls = {1, 2, 8, 4, 9}; // Stall positions (unsorted)

    // Call the function and store the result
    int result = aggressiveCows(n, k, stalls);

    // Output the result
    cout << "The largest minimum distance is: " << result << endl;

    return 0;
}
