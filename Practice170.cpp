#include <iostream>
#include <vector>
using namespace std;

/*
    Function: merge
    ----------------
    Merges two sorted halves of the array (arr[start...mid] and arr[mid+1...end])
    while counting the number of "inversions".

    Definition of inversion:
        A pair (i, j) is an inversion if i < j and arr[i] > arr[j].

    This function uses the merge step of merge sort and counts how many times
    an element from the right half (arr[j]) is smaller than an element
    from the left half (arr[i]).
*/
long merge(vector<int>& arr, vector<int>& temp, int start, int mid, int end) {
    int i = start;      // Pointer for left half
    int j = mid + 1;    // Pointer for right half
    int k = start;      // Pointer for temporary merged array
    long count = 0;     // Variable to store number of inversions found

    // Merge both halves while counting inversions
    while (i <= mid && j <= end) {
        if (arr[i] <= arr[j]) {
            // No inversion: left element smaller or equal
            temp[k++] = arr[i++];
        } else {
            // Inversion case: arr[i] > arr[j]
            temp[k++] = arr[j++];

            /*
                Since arr[i] > arr[j], all remaining elements from arr[i] to arr[mid]
                will also be greater than arr[j] because both halves are sorted.

                Hence, total inversions added = (mid - i + 1)
            */
            count += mid - i + 1;
        }
    }

    // Copy remaining elements from left half (if any)
    while (i <= mid)
        temp[k++] = arr[i++];

    // Copy remaining elements from right half (if any)
    while (j <= end)
        temp[k++] = arr[j++];

    // Copy merged elements back into original array
    while (start <= end) {
        arr[start] = temp[start];
        ++start;
    }

    // Return total inversion count found in this merge step
    return count;
}

/*
    Function: mergeSort
    --------------------
    Recursively divides the array into halves, sorts them, and counts inversions.

    Parameters:
        arr  - input array
        temp - temporary array used for merging
        start, end - current subarray boundaries

    Returns:
        Total inversion count within arr[start...end].
*/
long mergeSort(vector<int>& arr, vector<int>& temp, int start, int end) {
    // Base case: if the subarray has one or no elements, no inversion possible
    if (start >= end)
        return 0;

    int mid = start + (end - start) / 2; // Avoid overflow
    long count = 0;

    // Recursively count inversions in left half
    count += mergeSort(arr, temp, start, mid);

    // Recursively count inversions in right half
    count += mergeSort(arr, temp, mid + 1, end);

    // Count inversions while merging two sorted halves
    count += merge(arr, temp, start, mid, end);

    return count;
}

/*
    Function: countInversion
    -------------------------
    Wrapper function that initializes necessary data structures
    and calls mergeSort to get the total inversion count.

    Parameters:
        arr - input array

    Returns:
        Total number of inversions in the array.
*/
long countInversion(vector<int> arr) {
    long count = 0;  // Total inversion count
    vector<int> temp(arr.size(), 0); // Temporary array for merging
    count = mergeSort(arr, temp, 0, arr.size() - 1);
    return count;
}

int main() {
    // Example input array
    vector<int> arr = {8, 4, 3, 2};

    // Count total inversions
    long long result = countInversion(arr);

    // Display result
    cout << "Number of inversions: " << result << endl;

    /*
        Explanation for this input:
        Array: [8, 4, 3, 2]
        Inversions: (8,4), (8,3), (8,2), (4,3), (4,2), (3,2)
        Total = 6 inversions
    */
    return 0;
}
