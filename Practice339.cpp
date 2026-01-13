#include <iostream>
#include <algorithm>
using namespace std;

// =====================================================
// CLASS: Heap
// -----------------------------------------------------
// Implements a MAX HEAP using an array.
//
// KEY ASSUMPTIONS:
// • Heap uses 1-based indexing
// • arr[0] is a dummy/sentinel value
// • Maximum heap size = 100
// =====================================================
class Heap {
public:
    int arr[101];   // Array to store heap elements
    int size;       // Current number of elements in heap

    // -------------------------------------------------
    // Constructor
    // -------------------------------------------------
    // Initializes an empty heap
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
    // APPROACH (SIFT UP):
    //   1️⃣ Insert the value at the end of heap
    //   2️⃣ Compare it with its parent
    //   3️⃣ Swap if child > parent
    //   4️⃣ Repeat until heap property is restored
    //
    // TIME COMPLEXITY: O(log n)
    // SPACE COMPLEXITY: O(1)
    // =================================================
    void insert(int value) {

        // Step 1: Increase heap size and insert value
        int index = ++size;
        arr[index] = value;

        // -------------------------------------------------
        // Step 2: SIFT UP (Bubble up the element)
        // -------------------------------------------------
        // Continue until we reach root (index > 1)
        while (index > 1) {

            // Find parent index
            int parentIndex = index / 2;

            // If child is greater than parent,
            // heap property is violated → swap
            if (arr[index] > arr[parentIndex]) {
                swap(arr[index], arr[parentIndex]);

                // Move index to parent position
                index = parentIndex;
            }
            else {
                // Heap property satisfied
                break;
            }
        }
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
    // Pre-filled MAX HEAP
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

    cout << "Printing the heap:" << endl;
    for (int i = 0; i <= h.size; i++) {
        cout << h.arr[i] << " ";
    }
    cout << endl;

    // -------------------------------------------------
    // Insert new value into heap
    // -------------------------------------------------
    h.insert(110);

    cout << "\nPrinting the heap after insert:" << endl;
    for (int i = 0; i <= h.size; i++) {
        cout << h.arr[i] << " ";
    }
    cout << endl;

    return 0;
}
