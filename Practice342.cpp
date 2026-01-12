#include <iostream>
#include <algorithm>
using namespace std;

// =====================================================
// FUNCTION: heapify
// -----------------------------------------------------
// PURPOSE:
//   Maintains the MAX-HEAP property for a subtree
//   rooted at index `i`.
//
// PARAMETERS:
//   • arr[] → heap array (1-based indexing)
//   • n     → size of heap
//   • i     → index to heapify
//
// MAX-HEAP PROPERTY:
//   Parent node ≥ left child
//   Parent node ≥ right child
//
// TIME COMPLEXITY: O(log n)
// =====================================================
void heapify(int arr[], int n, int i) {

    // Current node index
    int index = i;

    // Left and right child indices (1-based indexing)
    int leftIndex = 2 * i;
    int rightIndex = 2 * i + 1;

    // Assume current index holds the largest value
    int largest = index;

    // -------------------------------------------------
    // Check left child
    // -------------------------------------------------
    if (leftIndex <= n && arr[largest] < arr[leftIndex]) {
        largest = leftIndex;
    }

    // -------------------------------------------------
    // Check right child
    // -------------------------------------------------
    if (rightIndex <= n && arr[largest] < arr[rightIndex]) {
        largest = rightIndex;
    }

    // -------------------------------------------------
    // If parent is NOT the largest
    // -------------------------------------------------
    if (index != largest) {

        // Swap parent with the largest child
        swap(arr[index], arr[largest]);

        // Move index to the largest child
        index = largest;

        // Recursively heapify affected subtree
        heapify(arr, n, index);
    }
}

// =====================================================
// FUNCTION: buildHeap
// -----------------------------------------------------
// PURPOSE:
//   Converts an UNSORTED array into a MAX HEAP.
//
// LOGIC:
//   • Start heapifying from last non-leaf node
//   • Last non-leaf node = n / 2
//
// TIME COMPLEXITY: O(n)
// =====================================================
void buildHeap(int arr[], int n) {

    // Start from last non-leaf node
    for (int i = n / 2; i > 0; i--) {
        heapify(arr, n, i);
    }
}

// =====================================================
// FUNCTION: heapSort
// -----------------------------------------------------
// PURPOSE:
//   Sorts the array using HEAP SORT algorithm.
//
// STEPS:
//   1️⃣ Swap root (largest) with last element
//   2️⃣ Reduce heap size
//   3️⃣ Heapify root again
//
// TIME COMPLEXITY: O(n log n)
// SPACE COMPLEXITY: O(1)
// =====================================================
void heapSort(int arr[], int n) {

    // Index represents last element in heap
    int index = n;

    // Continue until heap size reduces to 1
    while (n != 1) {

        // Move maximum element to the end
        swap(arr[1], arr[index]);

        // Reduce heap size
        index--;
        n--;

        // Restore max-heap property
        heapify(arr, n, 1);
    }
}

// =====================================================
// MAIN FUNCTION
// =====================================================
int main() {

    /*
        NOTE:
        We are using 1-based indexing for heap.
        Index 0 is a dummy value (-1).
        
        Original Array:
        Index:  0   1   2   3   4   5
        Value: -1   1  15  13  11  14
    */
    int arr[] = {-1, 1, 15, 13, 11, 14};
    int n = 5;

    // Build Max Heap
    buildHeap(arr, n);

    cout << "Printing the heap (Max Heap): " << endl;
    for (int i = 0; i <= n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Perform Heap Sort
    heapSort(arr, n);

    cout << endl;
    cout << "Printing the heap after Heap Sort: " << endl;
    for (int i = 0; i <= n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
