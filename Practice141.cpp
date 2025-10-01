#include <iostream>
#include <vector>
using namespace std;

/*
    Function: mergeCount
    --------------------
    Merges two sorted halves of the array while counting inversions.

    Parameters:
        arr   : The array being processed
        temp  : Temporary array used for merging
        start : Starting index of the left half
        mid   : Ending index of the left half
        end   : Ending index of the right half

    Returns:
        The number of inversions found during merging.

    Explanation:
        - An inversion occurs when arr[i] > arr[j] and i < j.
        - During merge:
            * If arr[i] <= arr[j], no inversion → copy arr[i].
            * If arr[i] > arr[j], then all elements from arr[i] to arr[mid]
              are greater than arr[j], so they all form inversions.
*/
long long mergeCount(vector<int>& arr, vector<int>& temp, int start, int mid, int end) {
    int i = start;     // Pointer for left half
    int j = mid + 1;   // Pointer for right half
    int k = start;     // Pointer for temp array
    long long invCount = 0; // Stores inversion count

    // Merge both halves while counting inversions
    while (i <= mid && j <= end) {
        if (arr[i] <= arr[j]) {
            // No inversion, place left element in sorted array
            temp[k++] = arr[i++];
        } else {
            // Inversion found:
            // arr[i] > arr[j], so all elements from arr[i..mid] > arr[j]
            temp[k++] = arr[j++];
            invCount += (long long)(mid - i + 1);
        }
    }

    // Copy remaining elements from left half (if any)
    while (i <= mid) temp[k++] = arr[i++];

    // Copy remaining elements from right half (if any)
    while (j <= end) temp[k++] = arr[j++];

    // Copy merged elements back into the original array
    for (int idx = start; idx <= end; ++idx) arr[idx] = temp[idx];

    return invCount;
}

/*
    Function: mergeSortCount
    ------------------------
    Recursively applies merge sort while counting inversions.

    Parameters:
        arr   : The array being processed
        temp  : Temporary array used for merging
        start : Starting index
        end   : Ending index

    Returns:
        Total number of inversions in the current subarray.
*/
long long mergeSortCount(vector<int>& arr, vector<int>& temp, int start, int end) {
    if (start >= end) return 0; // Base case: single element → no inversion

    int mid = start + (end - start) / 2;
    long long count = 0;

    // Recursively count inversions in left half
    count += mergeSortCount(arr, temp, start, mid);

    // Recursively count inversions in right half
    count += mergeSortCount(arr, temp, mid + 1, end);

    // Count inversions across left and right halves
    count += mergeCount(arr, temp, start, mid, end);

    return count;
}

/*
    Function: countInversions
    -------------------------
    Main function to count inversions in an array.

    Parameters:
        arr : The input array (passed by value to avoid modifying original)

    Returns:
        Total number of inversions in the array.
*/
long long countInversions(vector<int> arr) {
    if (arr.empty()) return 0; // Edge case: empty array

    vector<int> temp(arr.size()); // Temporary array for merging
    return mergeSortCount(arr, temp, 0, (int)arr.size() - 1);
}

int main() {
    // Example input
    vector<int> arr = {2, 4, 1, 3, 5};

    // Count inversions
    long long result = countInversions(arr);

    // Output result
    cout << "Number of inversions: " << result << endl; // Expected: 3

    return 0;
}
