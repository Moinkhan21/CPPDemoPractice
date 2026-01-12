#include <iostream>
#include <algorithm>
using namespace std;

// =====================================================
// FUNCTION: heapify
// -----------------------------------------------------
// PURPOSE:
//   Ensures that the subtree rooted at index `i`
//   satisfies the MAX-HEAP property.
//
// MAX-HEAP PROPERTY:
//   Parent node ≥ Left child
//   Parent node ≥ Right child
//
// PARAMETERS:
//   • arr[] → array representing heap (1-based indexing)
//   • n     → number of elements in heap
//   • i     → index of current node to heapify
//
// TIME COMPLEXITY:
//   O(log n)  (height of heap)
// =====================================================
void heapify(int arr[], int n, int i) {

    // Store current index
    int index = i;

    // Calculate left and right child indices
    // (valid because we are using 1-based indexing)
    int leftIndex = 2 * i;
    int rightIndex = 2 * i + 1;

    // Assume current node is the largest
    int largest = index;

    // -------------------------------------------------
    // Check if left child exists and is greater
    // -------------------------------------------------
    if (leftIndex <= n && arr[largest] < arr[leftIndex]) {
        largest = leftIndex;
    }

    // -------------------------------------------------
    // Check if right child exists and is greater
    // -------------------------------------------------
    if (rightIndex <= n && arr[largest] < arr[rightIndex]) {
        largest = rightIndex;
    }

    // -------------------------------------------------
    // If the largest element is NOT the current node
    // -------------------------------------------------
    if (index != largest) {

        // Swap current node with the larger child
        // (Heap property is violated here)
        swap(arr[index], arr[largest]);

        // Move index to where the swap happened
        index = largest;

        // Recursively heapify the affected subtree
        heapify(arr, n, index);
    }
}

// =====================================================
// FUNCTION: buildHeap
// -----------------------------------------------------
// PURPOSE:
//   Converts an unsorted array into a MAX HEAP.
//
// LOGIC:
//   • Leaf nodes already satisfy heap property
//   • Last non-leaf node is at index n/2
//   • Heapify from n/2 down to 1
//
// TIME COMPLEXITY:
//   O(n)
// =====================================================
void buildHeap(int arr[], int n) {

    // Start heapifying from the last non-leaf node
    for (int i = n / 2; i > 0; i--) {
        heapify(arr, n, i);
    }
}

// =====================================================
// MAIN FUNCTION
// =====================================================
int main() {

    /*
        NOTE:
        Heap uses 1-based indexing.
        Index 0 is a dummy value (-1).

        Initial array:
        Index:  0   1   2   3   4   5
        Value: -1   1  15  13  11  14
    */
    int arr[] = {-1, 1, 15, 13, 11, 14};
    int n = 5;

    // Convert array into a Max Heap
    buildHeap(arr, n);

    cout << "Printing the heap:" << endl;

    // Print heap elements
    for (int i = 0; i <= n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
