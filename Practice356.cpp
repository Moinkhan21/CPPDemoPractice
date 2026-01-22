#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// =====================================================
// CLASS: Solution
// -----------------------------------------------------
// PURPOSE:
//   Provides utilities to merge two Max Heaps
//   into a single valid Max Heap.
// =====================================================
class Solution {
public:

    // =================================================
    // FUNCTION: heapify
    // -------------------------------------------------
    // PURPOSE:
    //   Restores the Max-Heap property for a subtree
    //   rooted at index `i`.
    //
    // PARAMETERS:
    //   • v → reference to heap array
    //   • i → index to heapify from
    //   • n → total size of heap
    //
    // MAX-HEAP PROPERTY:
    //   • Parent must be greater than both children
    //
    // APPROACH (ITERATIVE):
    //   1️⃣ Compare parent with left child
    //   2️⃣ Compare current largest with right child
    //   3️⃣ Swap with the largest child if needed
    //   4️⃣ Continue until heap property is restored
    //
    // TIME COMPLEXITY:
    //   • O(log N)
    // =================================================
    void heapify(vector<int>& v, int i, int n) {

        while (true) {

            // Calculate child indices (0-based indexing)
            int left  = 2 * i + 1;
            int right = 2 * i + 2;

            // Assume parent is the largest initially
            int swapindex = i;

            // Check left child
            if (left < n && v[left] > v[swapindex]) {
                swapindex = left;
            }

            // Check right child
            if (right < n && v[right] > v[swapindex]) {
                swapindex = right;
            }

            // If parent is already the largest → stop
            if (swapindex == i) {
                break;
            }

            // Swap parent with largest child
            swap(v[i], v[swapindex]);

            // Move down to continue heapifying
            i = swapindex;
        }
    }

    // =================================================
    // FUNCTION: mergeHeaps
    // -------------------------------------------------
    // PURPOSE:
    //   Merge two Max Heaps into one valid Max Heap.
    //
    // PARAMETERS:
    //   • a → pointer to first heap
    //   • b → reference to second heap
    //   • n → size of first heap
    //   • m → size of second heap
    //
    // STRATEGY:
    //   1️⃣ Merge both arrays into one vector
    //   2️⃣ Build Max Heap using bottom-up heapify
    //
    // WHY BOTTOM-UP HEAPIFY?
    //   • More efficient than inserting one by one
    //   • Builds heap in O(N) time
    //
    // TIME COMPLEXITY:
    //   • Merging arrays → O(n + m)
    //   • Heap construction → O(n + m)
    //
    // SPACE COMPLEXITY:
    //   • O(n + m)
    // =================================================
    vector<int> mergeHeaps(vector<int>* a,
                           vector<int>& b,
                           int n,
                           int m) {

        // -------------------------------------------------
        // Step 1: Merge both heaps into a single vector
        // -------------------------------------------------
        vector<int> c(a->begin(), a->end());
        c.insert(c.end(), b.begin(), b.end());

        // -------------------------------------------------
        // Step 2: Convert merged vector into Max Heap
        // -------------------------------------------------
        // Start heapifying from last non-leaf node
        for (int i = (c.size() / 2) - 1; i >= 0; --i) {
            heapify(c, i, c.size());
        }

        return c;
    }
};

// =====================================================
// MAIN FUNCTION (TEST CASE)
// =====================================================
int main() {

    /*
        First Max Heap:
        [10, 5, 6, 2]

        Second Max Heap:
        [12, 7, 9]

        After merging & heapifying:
        One possible valid Max Heap:
        [12, 10, 9, 5, 7, 6, 2]
    */

    vector<int> a = {10, 5, 6, 2};
    vector<int> b = {12, 7, 9};

    Solution sol;

    vector<int> mergedHeap =
        sol.mergeHeaps(&a, b, a.size(), b.size());

    cout << "Merged Max Heap: ";
    for (int x : mergedHeap) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
