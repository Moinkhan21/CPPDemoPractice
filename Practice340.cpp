#include <iostream>
#include <algorithm>
using namespace std;

// =====================================================
// CLASS: Heap
// -----------------------------------------------------
// This class implements a MAX HEAP using an array.
//
// IMPORTANT ASSUMPTIONS:
// • Heap uses 1-based indexing
// • arr[0] is a dummy value (sentinel)
// • Maximum heap size = 100
// =====================================================
class Heap {
public:
    int arr[101];   // Array to store heap elements
    int size;       // Current number of elements in heap

    // -------------------------------------------------
    // Constructor
    // -------------------------------------------------
    // Initializes heap size to 0 (empty heap)
    // -------------------------------------------------
    Heap() {
        size = 0;
    }

    // =================================================
    // FUNCTION: insert
    // -------------------------------------------------
    // PURPOSE:
    //   Inserts a new value into the MAX HEAP.
    //
    // APPROACH:
    //   1️⃣ Insert element at the end
    //   2️⃣ Perform SIFT UP to restore heap property
    //
    // TIME COMPLEXITY: O(log n)
    // =================================================
    void insert(int value) {

        // Step 1: Insert element at next available index
        int index = ++size;
        arr[index] = value;

        // Step 2: SIFT UP (bubble up the element)
        while (index > 1) {

            // Find parent index
            int parentIndex = index / 2;

            // If child is greater than parent → swap
            if (arr[index] > arr[parentIndex]) {
                swap(arr[index], arr[parentIndex]);
                index = parentIndex;
            }
            else {
                // Heap property satisfied
                break;
            }
        }
    }

    // =================================================
    // FUNCTION: deleteFromHeap
    // -------------------------------------------------
    // PURPOSE:
    //   Deletes the ROOT element (maximum) from the heap.
    //
    // APPROACH:
    //   1️⃣ Store root value
    //   2️⃣ Replace root with last element
    //   3️⃣ Reduce heap size
    //   4️⃣ Perform SIFT DOWN to restore heap property
    //
    // TIME COMPLEXITY: O(log n)
    // =================================================
    int deleteFromHeap() {

        // Edge case: empty heap
        if (size == 0) {
            cout << "Heap is empty\n";
            return -1;
        }

        // Store root value (max element)
        int ans = arr[1];

        // Replace root with last element
        arr[1] = arr[size];
        size--;

        // SIFT DOWN process
        int index = 1;
        while (index <= size) {

            int left = 2 * index;
            int right = 2 * index + 1;
            int largest = index;

            // Compare with left child
            if (left <= size && arr[largest] < arr[left]) {
                largest = left;
            }

            // Compare with right child
            if (right <= size && arr[largest] < arr[right]) {
                largest = right;
            }

            // If heap property is satisfied
            if (largest == index) {
                break;
            }
            else {
                // Swap and continue sifting down
                swap(arr[index], arr[largest]);
                index = largest;
            }
        }

        return ans;
    }
};

// =====================================================
// MAIN FUNCTION
// =====================================================
int main() {

    Heap h;

    // -------------------------------------------------
    // Sentinel value for 1-based indexing
    // -------------------------------------------------
    h.arr[0] = -1;

    // -------------------------------------------------
    // Pre-filled heap (already a valid Max Heap)
    //
    //              100
    //             /   \
    //           50     60
    //          /  \
    //        40   45
    // -------------------------------------------------
    h.arr[1] = 100;
    h.arr[2] = 50;
    h.arr[3] = 60;
    h.arr[4] = 40;
    h.arr[5] = 45;
    h.size = 5;

    cout << "Initial Heap:\n";
    for (int i = 0; i <= h.size; i++) {
        cout << h.arr[i] << " ";
    }
    cout << endl;

    // -------------------------------------------------
    // Insert operation
    // -------------------------------------------------
    h.insert(110);

    cout << "\nHeap after insert:\n";
    for (int i = 0; i <= h.size; i++) {
        cout << h.arr[i] << " ";
    }
    cout << endl;

    // -------------------------------------------------
    // Delete root operation
    // -------------------------------------------------
    int deleted = h.deleteFromHeap();
    cout << "\nDeleted element: " << deleted << endl;

    cout << "\nHeap after delete:\n";
    for (int i = 0; i <= h.size; i++) {
        cout << h.arr[i] << " ";
    }
    cout << endl;

    return 0;
}
