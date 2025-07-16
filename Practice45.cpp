#include <iostream>
#include <vector>
using namespace std;

// ============================================
// Function: findPivot
// Purpose : Finds the index of the largest element (pivot)
//           in a rotated sorted array. Pivot is the point 
//           where the rotation occurs.
// ============================================
int findPivot(vector<int> arr) {
    int s = 0;
    int e = arr.size() - 1;
    int mid = s + (e - s) / 2;

    while (s <= e) {
        if (s == e) {
            // Only one element left — that’s the pivot
            return s;
        }

        // Check if mid is pivot (i.e., greater than its next element)
        if (mid <= e && arr[mid] > arr[mid + 1]) {
            return mid;
        }

        // Check if mid-1 is pivot (i.e., greater than mid)
        if (mid - 1 >= s && arr[mid - 1] > arr[mid]) {
            return mid - 1;
        }

        // Decide which half to search in
        if (arr[s] > arr[mid]) {
            // Pivot lies in the left half
            e = mid - 1;
        } else {
            // Pivot lies in the right half
            s = mid + 1;
        }

        // Recalculate mid
        mid = s + (e - s) / 2;
    }

    return -1; // Not a rotated array (shouldn’t happen in correct input)
}

// ============================================
// Function: binarySearch
// Purpose : Standard binary search algorithm to find
//           target in subarray from index s to e.
// ============================================
int binarySearch(vector<int> arr, int s, int e, int target) {
    int mid = s + (e - s) / 2;

    while (s <= e) {
        if (arr[mid] == target) {
            return mid; // Target found
        }

        if (arr[mid] > target) {
            e = mid - 1; // Search left half
        } else {
            s = mid + 1; // Search right half
        }

        // Recalculate mid
        mid = s + (e - s) / 2;
    }

    return -1; // Target not found
}

// ============================================
// Function: search
// Purpose : Searches for the target in rotated sorted array
// Logic   : Find pivot, then apply binary search on the
//           appropriate half of the array
// ============================================
int search(vector<int>& nums, int target) {
    // Step 1: Find the index of the pivot (largest element)
    int pivotIndex = findPivot(nums);
    int ans = 0;

    // Step 2: Based on target value, search left or right part
    if (target >= nums[0] && target <= nums[pivotIndex]) {
        // Target lies in the left subarray (from start to pivot)
        ans = binarySearch(nums, 0, pivotIndex, target);
    } else {
        // Target lies in the right subarray (from pivot+1 to end)
        ans = binarySearch(nums, pivotIndex + 1, nums.size() - 1, target);
    }

    return ans;
}

// ============================================
// Main Function
// Purpose : Test the search function with sample input
// ============================================
int main() {
    // Input rotated sorted array
    vector<int> arr = {4, 5, 6, 7, 0, 1, 2};
    int target = 0;

    // Search for the target in the array
    int result = search(arr, target);

    // Output the result
    if (result != -1) {
        cout << "Element found at index: " << result << endl;
    } else {
        cout << "Element not found in the array." << endl;
    }

    return 0;
}
