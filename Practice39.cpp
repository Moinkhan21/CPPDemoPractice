#include <iostream>
#include <vector>
using namespace std;

/**
 * Function: findPeakIndex
 * ------------------------
 * This function finds the index of the peak element in a mountain array.
 * A mountain array is one that strictly increases to a peak element and then strictly decreases.
 *
 * Parameters:
 *  - arr: a reference to the vector of integers representing the mountain array.
 *
 * Returns:
 *  - The index of the peak element.
 */
int findPeakIndex(const vector<int>& arr) {
    int s = 0;                    // Start of the search range
    int e = arr.size() - 1;       // End of the search range

    // Binary search to find the peak
    while (s < e) {
        int mid = s + (e - s) / 2; // Prevents integer overflow compared to (s + e)/2

        // If mid element is less than the next one, we are in the increasing part
        if (arr[mid] < arr[mid + 1]) {
            s = mid + 1; // Move start to mid+1 since peak is on the right
        } else {
            // We are in the decreasing part, or at the peak
            e = mid; // Keep mid as it could be the peak
        }
    }

    // When s == e, we have found the peak index
    return s;
}

/**
 * Function: peakIndexInMountainArray
 * ----------------------------------
 * A wrapper function to find the peak index in a mountain array.
 * This mimics typical function names in online coding platforms (e.g., LeetCode).
 *
 * Parameters:
 *  - arr: a reference to the vector of integers representing the mountain array.
 *
 * Returns:
 *  - The index of the peak element.
 */
int peakIndexInMountainArray(const vector<int>& arr) {
    return findPeakIndex(arr);
}

/**
 * Main function to test the peak-finding logic with a sample array.
 */
int main() {
    // Sample mountain array: strictly increasing then strictly decreasing
    vector<int> arr = {1, 3, 5, 7, 6, 4, 2};

    // Call function to get the peak index
    int peakIndex = peakIndexInMountainArray(arr);

    // Display the result
    cout << "Peak Index in Mountain Array: " << peakIndex << endl;
    cout << "Peak Element: " << arr[peakIndex] << endl;

    return 0; // Exit successfully
}
