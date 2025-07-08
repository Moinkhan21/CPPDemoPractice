#include <iostream>
#include <vector>
using namespace std;

/**
 * Function to find the peak index in a mountain array.
 * A mountain array increases and then decreases, and this function finds the peak element index.
 */
int findPeakIndex(const vector<int>& arr) {
    int s = 0;
    int e = arr.size() - 1;

    while (s < e) {
        int mid = s + (e - s) / 2;

        if (arr[mid] < arr[mid + 1]) {
            // We are in the increasing part of the mountain
            s = mid + 1;
        } else {
            // We are in the decreasing part, or at the peak
            e = mid;
        }
    }

    // s (or e) will point to the peak index
    return s;
}

/**
 * Wrapper function for compatibility with problem format (e.g., Leetcode style)
 */
int peakIndexInMountainArray(const vector<int>& arr) {
    return findPeakIndex(arr);
}

// ---------- MAIN FUNCTION FOR TESTING ----------
int main() {
    vector<int> arr = {1, 3, 5, 7, 6, 4, 2}; // Sample mountain array

    int peakIndex = peakIndexInMountainArray(arr);

    cout << "Peak Index in Mountain Array: " << peakIndex << endl;
    cout << "Peak Element: " << arr[peakIndex] << endl;

    return 0;
}
