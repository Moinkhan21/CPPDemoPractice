#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
----------------------------------------------------------------------
Function: lowerBound
Purpose:  Implements binary search to find the first position where
          an element greater than or equal to 'x' appears.
Params:
    arr - Sorted array to search
    x   - Target value to find the lower bound for
Returns:
    The index of the first element ≥ x (lower bound)
----------------------------------------------------------------------
*/
int lowerBound(const vector<int>& arr, int x) {
    int start = 0, end = arr.size() - 1;
    int ans = end;  // Default to end index in case no element >= x

    while (start <= end) {
        int mid = start + (end - start) / 2;

        if (arr[mid] >= x) {
            ans = mid;        // Found a candidate index
            end = mid - 1;    // Try to find a smaller index on the left
        } else {
            start = mid + 1;  // Move right
        }
    }

    return ans;
}

/*
----------------------------------------------------------------------
Function: binarySearchMethod
Purpose:  Finds k closest elements to x using binary search logic.
Approach:
    - Locate the lower bound (first element ≥ x)
    - Use two pointers to expand around this position
    - Add elements closer to x (based on absolute difference)
Params:
    arr - Sorted input array
    k   - Number of closest elements to find
    x   - Target element
Returns:
    A vector containing k closest elements to x
----------------------------------------------------------------------
*/
vector<int> binarySearchMethod(const vector<int>& arr, int k, int x) {
    int right = lowerBound(arr, x);
    int left = right - 1;

    while (k--) {
        // If left pointer is out of bounds, move right
        if (left < 0) {
            right++;
        }
        // If right pointer is out of bounds, move left
        else if (right >= arr.size()) {
            left--;
        }
        // Choose closer element based on absolute difference
        else if (abs(arr[left] - x) <= abs(arr[right] - x)) {
            left--;
        }
        else {
            right++;
        }
    }

    // Return subarray from left + 1 to right (exclusive)
    return vector<int>(arr.begin() + left + 1, arr.begin() + right);
}

/*
----------------------------------------------------------------------
Function: twoPointerMethod
Purpose:  Shrinks the window from both sides until exactly k closest
          elements remain, using two-pointer technique.
Approach:
    - Start with full array [left, right]
    - Move pointers inward depending on which side is farther from x
Params:
    arr - Sorted input array
    k   - Number of closest elements to find
    x   - Target value
Returns:
    A vector containing k closest elements to x
----------------------------------------------------------------------
*/
vector<int> twoPointerMethod(const vector<int>& arr, int k, int x) {
    int left = 0, right = arr.size() - 1;

    // Shrink the window from either end until window size becomes k
    while (right - left >= k) {
        if (abs(arr[left] - x) > abs(arr[right] - x)) {
            left++;  // Left element is farther, move left pointer
        } else {
            right--; // Right element is farther, move right pointer
        }
    }

    // Return the subarray of size k
    return vector<int>(arr.begin() + left, arr.begin() + right + 1);
}

/*
----------------------------------------------------------------------
Function: findClosestElements
Purpose:  Main interface function that delegates the solution to one
          of the two functional approaches (binary search or two-pointer).
Params:
    arr - Sorted input array
    k   - Number of closest elements
    x   - Target value
Returns:
    A vector with k closest integers to x
----------------------------------------------------------------------
*/
vector<int> findClosestElements(vector<int> arr, int k, int x) {
    // Uncomment the preferred method:

    // return twoPointerMethod(arr, k, x); // Method 1: Two-Pointer approach
    return binarySearchMethod(arr, k, x);  // Method 2: Binary Search approach
}

/*
----------------------------------------------------------------------
Main Function
Tests the findClosestElements function
----------------------------------------------------------------------
*/
int main() {
    vector<int> arr = {1, 2, 3, 4, 5};  // Example sorted array
    int k = 4;
    int x = 3;

    vector<int> closest = findClosestElements(arr, k, x);

    cout << "The " << k << " closest elements to " << x << " are:\n";
    for (int num : closest) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
