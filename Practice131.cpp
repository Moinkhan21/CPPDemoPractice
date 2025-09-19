#include <iostream>
using namespace std;

// Function to merge two sorted halves of an array into a single sorted array
void merge(int *arr, int s, int e) {

    // Find the midpoint of the array
    int mid = (s + e) / 2;
    
    // Length of left subarray
    int len1 = mid - s + 1;

    // Length of right subarray
    int len2 = e - mid;

    // Dynamically create temporary arrays for left and right halves
    int* left = new int[len1];
    int* right = new int[len2];

    // ----------------- COPY DATA INTO LEFT ARRAY -----------------
    int k = s;  // Start copying from index `s`
    for (int i = 0; i < len1; i++) {
        left[i] = arr[k];
        k++;
    }

    // ----------------- COPY DATA INTO RIGHT ARRAY -----------------
    k = mid + 1;  // Start copying from index `mid+1`
    for (int i = 0; i < len2; i++) {
        right[i] = arr[k];
        k++;
    }

    // ----------------- MERGE THE TWO SORTED ARRAYS -----------------
    int leftIndex = 0;       // Index for traversing left array
    int rightIndex = 0;      // Index for traversing right array
    int mainArrayIndex = s;  // Index for placing sorted elements in original array

    // Compare elements of left[] and right[] and copy the smaller one
    while (leftIndex < len1 && rightIndex < len2) {
        if (left[leftIndex] < right[rightIndex]) {
            arr[mainArrayIndex++] = left[leftIndex++];
        } else {
            arr[mainArrayIndex++] = right[rightIndex++];
        }
    }

    // ----------------- COPY REMAINING ELEMENTS -----------------
    // Copy remaining elements of left[] (if any)
    while (leftIndex < len1) {
        arr[mainArrayIndex++] = left[leftIndex++];
    }

    // Copy remaining elements of right[] (if any)
    while (rightIndex < len2) {
        arr[mainArrayIndex++] = right[rightIndex++];
    }

    // Free dynamically allocated memory (to prevent memory leaks)
    delete[] left;
    delete[] right;
}

// Recursive function to perform merge sort
void mergeSort(int* arr, int s, int e) {
    // ----------------- BASE CASE -----------------
    // If array has 1 or 0 elements, it is already sorted
    if (s >= e)
        return;

    // Find the midpoint
    int mid = (s + e) / 2;

    // ----------------- DIVIDE STEP -----------------
    // Sort left half recursively
    mergeSort(arr, s, mid);

    // Sort right half recursively
    mergeSort(arr, mid + 1, e);

    // ----------------- MERGE STEP -----------------
    // Merge two sorted halves
    merge(arr, s, e);
}

int main() {
    // Input array
    int arr[] = {4, 5, 13, 2, 12};
    int n = 5;
    int s = 0;
    int e = n - 1;

    // Call mergeSort on the entire array
    mergeSort(arr, s, e);

    // Print the sorted array
    cout << "Sorted Array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
