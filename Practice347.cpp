#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// =====================================================
// CLASS: info
// -----------------------------------------------------
// PURPOSE:
//   Stores information about an element taken from
//   one of the K sorted arrays.
//
// MEMBERS:
//   data → actual value
//   row  → index of the array from which value came
//   col  → index inside that array
//
// WHY NEEDED?
//   When we extract the smallest element from heap,
//   we must know which array it came from so we can
//   insert the next element from the same array.
// =====================================================
class info {
public:
    int data;
    int row;
    int col;

    // Constructor
    info(int val, int r, int c) {
        data = val;
        row  = r;
        col  = c;
    }
};

// =====================================================
// CLASS: compare
// -----------------------------------------------------
// PURPOSE:
//   Custom comparator for priority_queue.
//
// NOTE:
//   priority_queue by default creates a MAX HEAP.
//
//   We reverse the condition so that the smallest
//   element appears at the top (MIN HEAP).
//
// RULE:
//   Node with smaller data gets higher priority.
// =====================================================
class compare {
public:
    bool operator() (info* a, info* b) {
        return a->data > b->data;  // MIN HEAP condition
    }
};

// =====================================================
// FUNCTION: mergeKSortedArrays
// -----------------------------------------------------
// PROBLEM:
//   Merge K sorted arrays (each of size N)
//   into a single sorted array.
//
// APPROACH (MIN HEAP):
//
//   Step 1:
//     Insert the first element of each array
//     into the min heap.
//
//   Step 2:
//     Extract the smallest element from heap.
//
//   Step 3:
//     Insert the next element from the same array.
//
//   Step 4:
//     Repeat until heap becomes empty.
//
// WHY HEAP?
//   Heap efficiently gives the smallest element
//   among K arrays in O(log K) time.
//
// TIME COMPLEXITY:
//   O(K * N * log K)
//
// SPACE COMPLEXITY:
//   O(K)
// =====================================================
vector<int> mergeKSortedArrays(int arr[][4], int k, int n) {

    // Min heap storing pointers to info objects
    priority_queue<info*, vector<info*>, compare> minHeap;

    // -------------------------------------------------
    // STEP 1: Insert first element of each array
    // -------------------------------------------------
    for (int i = 0; i < k; i++) {

        info* temp = new info(arr[i][0], i, 0);

        minHeap.push(temp);
    }

    vector<int> ans;

    // -------------------------------------------------
    // STEP 2: Process heap until it becomes empty
    // -------------------------------------------------
    while (!minHeap.empty()) {

        // Extract smallest element
        info* temp = minHeap.top();
        minHeap.pop();

        int topElement = temp->data;
        int topRow     = temp->row;
        int topCol     = temp->col;

        // Add smallest element to result array
        ans.push_back(topElement);

        // -------------------------------------------------
        // STEP 3: Insert next element from same array
        // -------------------------------------------------
        if (topCol + 1 < n) {

            info* newInfo =
                new info(arr[topRow][topCol + 1], topRow, topCol + 1);

            minHeap.push(newInfo);
        }
    }

    return ans;
}

// =====================================================
// MAIN FUNCTION
// -----------------------------------------------------
// PURPOSE:
//   Demonstrates merging of K sorted arrays
// =====================================================
int main() {

    /*
        Input arrays:

        { 2, 4, 6, 8 }
        { 1, 3, 5, 7 }
        { 0, 9, 10, 11 }

        Expected Output:

        0 1 2 3 4 5 6 7 8 9 10 11
    */

    int arr[][4] = {
        {2, 4, 6, 8},
        {1, 3, 5, 7},
        {0, 9, 10, 11}
    };

    int k = 3;  // number of arrays
    int n = 4;  // size of each array

    vector<int> ans = mergeKSortedArrays(arr, k, n);

    // Print merged sorted array
    for (auto i : ans) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}