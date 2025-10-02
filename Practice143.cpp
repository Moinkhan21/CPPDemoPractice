#include <iostream>
#include <vector>
#include <climits> // For INT_MIN
using namespace std;

/*
    Function: maxSumArrayHelper
    ---------------------------
    Uses divide and conquer to calculate the maximum subarray sum
    within a given range [start..end] of the array.

    Parameters:
        v     : The input array
        start : Starting index of the subarray
        end   : Ending index of the subarray

    Returns:
        The maximum sum of any contiguous subarray in v[start..end]
*/
int maxSumArrayHelper(vector<int>& v, int start, int end) {
    // Base case: if the subarray has only one element, 
    // that element is the maximum sum
    if(start == end) return v[start];

    // Initialize variables to track maximum sums across the border
    int maxLeftBorderSum = INT_MIN, maxRightBorderSum = INT_MIN;

    // Find the middle index to divide the array into two halves
    int mid = start + ((end - start) / 2);

    // Recursively find the maximum subarray sum in the left half
    int maxLeftSum = maxSumArrayHelper(v, start, mid);

    // Recursively find the maximum subarray sum in the right half
    int maxRightSum = maxSumArrayHelper(v, mid + 1, end);

    // ---------------------------------------------------------
    // Find the maximum subarray sum that crosses the mid-point
    // ---------------------------------------------------------

    // Traverse leftwards from mid to find best "left border sum"
    int leftBorderSum = 0;
    for(int i = mid; i >= start; i--) {
        leftBorderSum += v[i];
        if(leftBorderSum > maxLeftBorderSum) 
            maxLeftBorderSum = leftBorderSum;
    }

    // Traverse rightwards from mid+1 to find best "right border sum"
    int rightBorderSum = 0;
    for(int i = mid + 1; i <= end; i++) {
        rightBorderSum += v[i];
        if(rightBorderSum > maxRightBorderSum) 
            maxRightBorderSum = rightBorderSum;
    }

    // Combine left and right border sums to get the "crossing sum"
    int maxCrossBorderSum = maxLeftBorderSum + maxRightBorderSum;

    // The maximum subarray sum for this range is the maximum of:
    // 1. Entirely in left half
    // 2. Entirely in right half
    // 3. Crossing the midpoint
    return max(maxLeftSum, max(maxRightSum, maxCrossBorderSum));
}

/*
    Function: maxSumArray
    ---------------------
    Wrapper function that calls the helper on the full array.
*/
int maxSumArray(vector<int>& v) {
    return maxSumArrayHelper(v, 0, v.size() - 1);
}

int main() {
    // Example input array
    vector<int> v = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    // Expected output = 6 (subarray [4, -1, 2, 1])
    cout << "Maximum Subarray Sum: " << maxSumArray(v) << endl;

    return 0;
}
