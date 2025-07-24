#include<iostream>
#include <vector>
using namespace std;

/*
 * Function: binarySearch
 * ----------------------
 * Performs standard binary search on a subarray defined by the given `start` and `end` indices.
 * 
 * Parameters:
 *  - a[]: The input sorted array.
 *  - start: The starting index of the subarray.
 *  - end: The ending index of the subarray.
 *  - x: The target element to search for.
 *
 * Returns:
 *  - Index of the element `x` if found.
 *  - -1 if the element is not present in the array.
 */
int binarySearch(int a[], int start, int end, int x) {
    while (start <= end) {
        // Calculate mid to avoid integer overflow
        int mid = start + (end - start) / 2;

        if (a[mid] == x) {
            return mid; // Element found
        }
        else if (a[mid] < x) {
            start = mid + 1; // Move to the right half
        }
        else {
            end = mid - 1;   // Move to the left half
        }
    }
    return -1; // Element not found
}

/*
 * Function: expSearch (Exponential Search)
 * ----------------------------------------
 * Efficiently finds the position of the element `x` in a sorted array using exponential search.
 * First, it identifies the range where the element might exist, then applies binary search in that range.
 * 
 * Parameters:
 *  - a[]: The input sorted array.
 *  - n: Size of the array.
 *  - x: The target element to search for.
 *
 * Returns:
 *  - Index of the element `x` if found.
 *  - -1 if the element is not present.
 */
int expSearch(int a[], int n, int x) {
    // Check if the first element itself is the target
    if (a[0] == x) return 0;

    // Start from index 1 and double the index until we find a range
    int i = 1;
    while (i < n && a[i] <= x) {
        i *= 2;  // i <<= 1 is also valid for doubling
    }

    // Perform binary search in the identified range: [i/2 to min(i, n-1)]
    return binarySearch(a, i / 2, min(i, n - 1), x);
}

/*
 * Function: main
 * --------------
 * Demonstrates the use of exponential search on a sorted array.
 */
int main() {
    int a[] = {3, 4, 5, 6, 11, 13, 14, 15, 56, 70}; // Sorted array
    int n = sizeof(a) / sizeof(a[0]); // Number of elements
    int x = 13; // Element to search

    // Perform exponential search
    int ans = expSearch(a, n, x);

    // Output the result
    if (ans != -1)
        cout << "Element " << x << " is at index: " << ans << endl;
    else
        cout << "Element " << x << " not found in the array." << endl;

    return 0;
}
