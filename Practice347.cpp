#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// =====================================================
// CLASS: info
// -----------------------------------------------------
// PURPOSE:
//   This class stores information about an element
//   coming from a particular array.
//
// MEMBERS:
//   • data → actual value
//   • row  → which array the value came from
//   • col  → index inside that array
// =====================================================
class info {
public:
    int data;
    int row;
    int col;

    // Constructor to initialize values
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
//   Custom comparator for priority_queue (min heap).
//
// NOTE:
//   By default, priority_queue is a MAX heap.
//   We reverse comparison to make it a MIN heap.
//
// RULE:
//   Smaller data value gets higher priority.
// =====================================================
class compare {
public:
    bool operator() (info* a, info* b) {
        return a->data > b->data;
    }
};

// =====================================================
// FUNCTION: mergeKSortedArrays
// -----------------------------------------------------
// PURPOSE:
//   Merge K sorted arrays of size N into one sorted array.
//
// APPROACH (MIN HEAP):
//   1️⃣ Push first element of each array into heap
//   2️⃣ Pop smallest element
//   3️⃣ Insert next element from same array
//   4️⃣ Repeat until heap becomes empty
//
// TIME COMPLEXITY: O(K * N * log K)
// SPACE COMPLEXITY: O(K)
// =====================================================
vector<int> mergeKSortedArrays(int arr[][4], int k, int n) {

    // Min heap storing pointers of type info*
    priority_queue<info*, vector<info*>, compare> minHeap;

    // -------------------------------------------------
    // Step 1: Insert first element of every array
    // -------------------------------------------------
    for (int i = 0; i < k; i++) {
        info* temp = new info(arr[i][0], i, 0);
        minHeap.push(temp);
    }

    vector<int> ans;

    // -------------------------------------------------
    // Step 2: Process heap until empty
    // -------------------------------------------------
    while (!minHeap.empty()) {

        // Get smallest element
        info* temp = minHeap.top();
        minHeap.pop();

        int topElement = temp->data;
        int topRow     = temp->row;
        int topCol     = temp->col;

        // Add smallest element to answer
        ans.push_back(topElement);

        // -------------------------------------------------
        // Step 3: Push next element from same array
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
// =====================================================
int main() {

    /*
        Input arrays:
        { 2, 4, 6, 8 }
        { 1, 3, 5, 7 }
        { 0, 9, 10, 11 }

        Output:
        0 1 2 3 4 5 6 7 8 9 10 11
    */

    int arr[][4] = {
        {2, 4, 6, 8},
        {1, 3, 5, 7},
        {0, 9, 10, 11}
    };

    int k = 3;  // Number of arrays
    int n = 4;  // Size of each array

    vector<int> ans = mergeKSortedArrays(arr, k, n);

    // Print result
    for (auto i : ans) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
