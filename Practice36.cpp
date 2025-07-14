#include <iostream>
using namespace std;

// ============================================
// Function: binarySearch
// Purpose : Perform binary search on a sorted array
// Params  : arr[] -> sorted array of integers
//           n     -> size of the array
//           target -> the number to find
// Returns : index of target if found, -1 otherwise
// ============================================
int binarySearch(int arr[], int n, int target) {
    int start = 0;          // Start index of search range
    int end = n - 1;        // End index of search range
    int mid = (start + end) / 2;  // Initial midpoint

    // Loop continues as long as start is less than or equal to end
    while(start <= end){
        int element = arr[mid];  // Get the middle element

        if(element == target) {
            // Target found at mid index
            return mid;
        }
        else if(target < element) {
            // Target is in the left half
            end = mid - 1;
        }
        else {
            // Target is in the right half
            start = mid + 1;
        }

        // Update mid after adjusting start or end
        mid = (start + end) / 2;
    }

    // If loop ends, target not found
    return -1;
}

int main() {
    // Sorted array for binary search
    int arr[] = {2, 4, 6, 8, 10, 12, 16};

    // Calculate size of the array
    int n = sizeof(arr) / sizeof(arr[0]);

    // Target element to search
    int target = 8;

    // Call binary search and get index
    int indexOftarget = binarySearch(arr, n, target);

    // Print result
    if (indexOftarget == -1) {
        cout << "Element not found" << endl;
    } else {
        cout << "Element found at index: " << indexOftarget << endl;
    }

    return 0; // Indicate successful execution
}
