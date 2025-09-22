#include <iostream>
using namespace std;

// ---------------- FUNCTION: partition ----------------
// Purpose: Partition the array into two parts based on pivot element.
//          - All elements <= pivot are placed to the left.
//          - All elements > pivot are placed to the right.
//          - Pivot element is placed at its correct sorted position.
//
// Parameters:
//   arr[] -> array of integers
//   s     -> starting index of the segment
//   e     -> ending index of the segment
//
// Returns:
//   Final index of the pivot element after correct placement.
int partition(int arr[], int s, int e){
    // ---------- STEP 1: Choose pivot element ----------
    int pivotIndex = s;        // Select first element as pivot
    int pivotElement = arr[s]; // Store pivot value

    // ---------- STEP 2: Count how many elements are <= pivot ----------
    int count = 0;
    for(int i = s + 1; i <= e; i++){
        if(arr[i] <= pivotElement){
            count++;
        }
    }

    // Now we know the correct index of pivot in sorted array
    int rightIndex = s + count;

    // Place pivot at its correct position
    swap(arr[pivotIndex], arr[rightIndex]);

    // Update pivotIndex to new position
    pivotIndex = rightIndex;

    // ---------- STEP 3: Place smaller on left & larger on right ----------
    int i = s; // pointer starting from left
    int j = e; // pointer starting from right

    // Continue until both pointers cross the pivot index
    while(i < pivotIndex && j > pivotIndex){

        // Move left pointer forward until an element > pivot is found
        while(arr[i] <= pivotElement){
            i++;
        }

        // Move right pointer backward until an element < pivot is found
        while(arr[j] > pivotElement){
            j--;
        }

        // Two possibilities:
        // A => Found out-of-place elements (swap them)
        // B => Otherwise, loop continues
        if(i < pivotIndex && j > pivotIndex)
            swap(arr[i], arr[j]);
    }

    // Return pivot's final index
    return pivotIndex;
}

// ---------------- FUNCTION: quickSort ----------------
// Purpose: Sort array using QuickSort algorithm (Divide & Conquer).
//
// Parameters:
//   arr[] -> array of integers
//   s     -> starting index of the segment
//   e     -> ending index of the segment
void quickSort(int arr[], int s, int e){
    // ---------- BASE CASE ----------
    // If subarray has 0 or 1 element, it’s already sorted
    if(s >= e){
        return;
    }

    // ---------- STEP 1: Partition ----------
    // Place pivot element at correct position and get its index
    int p = partition(arr, s, e);

    // ---------- STEP 2: Recursively sort subarrays ----------
    // Sort left subarray (elements before pivot)
    quickSort(arr, s, p - 1);

    // Sort right subarray (elements after pivot)
    quickSort(arr, p + 1, e);
}

int main() {
    // ---------- INPUT SECTION ----------
    int arr[] = {8, 1, 3, 4, 20, 50, 30}; // Example array
    int n = 7;                            // Number of elements

    int s = 0;          // Start index
    int e = n - 1;      // End index

    // ---------- FUNCTION CALL ----------
    quickSort(arr, s, e);

    // ---------- OUTPUT SECTION ----------
    cout << "Sorted Array: ";
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
