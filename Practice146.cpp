#include <iostream>
using namespace std;

// QuickSort function: sorts an array using divide and conquer approach
void quickSort(int a[], int start, int end) {
    // Base case: if the range has 0 or 1 element, it's already sorted
    if(start >= end) return;

    // --- Partitioning Step ---
    int pivot = end;       // Choosing the last element as the pivot
    int i = start - 1;     // Pointer for the boundary of smaller elements
    int j = start;         // Iterator pointer to check each element

    // Traverse the array from 'start' to 'end - 1'
    while(j < end) {
        if(a[j] < a[pivot]) {    // If current element is smaller than pivot
            i++;                 // Move boundary forward
            swap(a[i], a[j]);    // Place element in the correct left partition
        }
        j++; // Move to next element
    }

    // After loop, place pivot in its correct sorted position
    i++; 
    swap(a[i], a[pivot]);

    // --- Recursive Steps ---
    // Sort the left subarray (elements smaller than pivot)
    quickSort(a, start, i - 1);

    // Sort the right subarray (elements greater than pivot)
    quickSort(a, i + 1, end);
}

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};     // Sample unsorted array
    int n = sizeof(arr)/sizeof(arr[0]);  // Calculate number of elements

    // Call QuickSort on the full array
    quickSort(arr, 0, n - 1);

    // Print the sorted array
    cout << "Sorted array: \n";
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";   // Output elements one by one
    return 0;
}
