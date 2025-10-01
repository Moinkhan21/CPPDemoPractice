#include <iostream>
#include <vector>
using namespace std;

/*
    Function: mergeInPlace
    ----------------------
    Merges two sorted halves of an array in-place using the "Gap method".
    
    Parameters:
        arr   : The array to be sorted
        start : Starting index of the subarray
        mid   : Middle index (end of first half)
        end   : Ending index of the subarray
    
    Explanation:
        - Instead of using extra space (like in normal merge), we compare elements
          using a "gap" between indices.
        - Initially, gap = ceil(length/2).
        - Compare arr[i] and arr[j] (where j = i + gap).
        - If arr[i] > arr[j], swap them.
        - Keep reducing the gap (gap = ceil(gap/2)) until gap becomes 0.
        - This ensures the subarray becomes fully sorted in-place.
*/
void mergeInPlace(vector<int>& arr, int start, int mid, int end){
    int total_len = end - start + 1; 
    int gap = total_len / 2 + total_len % 2; // Initial gap = ceil(total_len/2)

    while(gap > 0) {
        int i = start, j = start + gap;

        // Compare elements with gap distance
        while(j <= end){
            if(arr[i] > arr[j]){
                swap(arr[i], arr[j]);  // Swap if out of order
            }
            i++;
            j++;
        }

        // Reduce gap (similar to Shell Sort)
        gap = gap <= 1 ? 0 : (gap / 2) + (gap % 2); // ceil(gap/2)
    }
}

/*
    Function: mergeSort
    -------------------
    Standard merge sort function that:
        - Recursively divides the array into two halves
        - Calls mergeInPlace to merge them without extra space
    
    Parameters:
        arr   : The array to be sorted
        start : Starting index
        end   : Ending index
*/
void mergeSort(vector<int>& arr, int start, int end){
    // Base case: single element or invalid range → already sorted
    if(start >= end) return;

    // Find mid point safely (avoids overflow compared to (start+end)/2)
    int mid = start + (end - start) / 2;

    // Recursively sort left half
    mergeSort(arr, start, mid);

    // Recursively sort right half
    mergeSort(arr, mid + 1, end);

    // Merge the two sorted halves in-place
    mergeInPlace(arr, start, mid, end);
}

/*
    Function: sortArray
    -------------------
    Wrapper function to sort the given array using merge sort.
    
    Parameters:
        arr : The input unsorted array
    
    Returns:
        The sorted array
*/
vector<int> sortArray(vector<int>& arr) {
    mergeSort(arr, 0, (int)arr.size() - 1);
    return arr;
}

int main() {
    // Example input
    vector<int> arr = {5, 2, 3, 1};

    // Sort the array
    vector<int> sortedArr = sortArray(arr);

    // Print result
    cout << "Sorted array: ";
    for(int num : sortedArr) {
        cout << num << " ";
    }
    cout << endl; // Expected Output: 1 2 3 5

    return 0;
}
