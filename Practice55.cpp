#include <iostream>
#include <numeric> // for accumulate
using namespace std;

/*
 * Function: isPossibleSolution
 * ----------------------------
 * Checks whether it's possible to paint all boards within the given maximum time (`mid`)
 * by at most `k` painters.
 */
bool isPossibleSolution(int a[], int n, int k, long long mid) {
    long long timeSum = 0;  // Time taken by the current painter
    int c = 1;              // Number of painters required so far

    for(int i = 0; i < n; i++) {
        if(a[i] > mid) {
            // If a single board takes more time than `mid`, it's not a valid solution
            return false;
        }

        if(timeSum + a[i] > mid) {
            // Assign board to the next painter
            c++;
            timeSum = a[i];

            if(c > k) {
                // If painters exceed the limit `k`, return false
                return false;
            }
        } else {
            // Accumulate time for the current painter
            timeSum += a[i];
        }
    }

    return true; // If all boards can be painted with `k` or fewer painters within `mid` time
}

/*
 * Function: minTime
 * -----------------
 * Returns the minimum amount of time required to paint all boards using `k` painters.
 */
long long minTime(int arr[], int n, int k) {
    long long start = 0;
    long long end = 0;

    // Calculate the sum of all board lengths to determine the upper bound
    for (int i = 0; i < n; i++) {
        end += arr[i];
    }

    long long ans = -1;

    // Apply Binary Search to minimize the maximum time
    while(start <= end) {
        long long mid = start + (end - start) / 2;

        if (isPossibleSolution(arr, n, k, mid)) {
            ans = mid;       // A valid solution found, store it
            end = mid - 1;   // Try to find a smaller maximum time
        } else {
            start = mid + 1; // Try with larger time
        }
    }

    return ans;
}

// ----------------------
// Example Usage
// ----------------------
int main() {
    int arr[] = {10, 20, 30, 40}; // Length of boards
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 2; // Number of painters

    cout << "Minimum time to paint all boards: " << minTime(arr, n, k) << endl;

    return 0;
}
