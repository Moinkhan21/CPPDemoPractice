#include <iostream>
using namespace std;

void quickSort(int a[], int start, int end) {
    if(start >= end) return; // Base case: single element or invalid range
    int pivot = end; // Choosing the last element as pivot
    int i = start - 1; // Pointer for the smaller element
    int j = start; // Current element pointer

    while(j < end) {
        if(a[j] < a[pivot]) {
            i++;
            swap(a[i], a[j]); // Swap if element is smaller than pivot
        }
        j++;
    }
    i++;
    swap(a[i], a[pivot]); // Place pivot in the correct position
    quickSort(a, start, i - 1); // Recursively sort left subarray
    quickSort(a, i + 1, end); // Recursively sort right subarray
}

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    quickSort(arr, 0, n - 1);
    cout << "Sorted array: \n";
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}