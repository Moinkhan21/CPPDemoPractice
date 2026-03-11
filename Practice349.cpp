#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

// =====================================================
// CLASS: node
// -----------------------------------------------------
// PURPOSE:
//   Represents an element inside the heap.
//
// MEMBERS:
//   data → value of element
//   row  → which list (row) the element came from
//   col  → index inside that list
//
// WHY STORE row & col?
//   So we can push the next element from the same list
//   when this element is removed from the heap.
// =====================================================
class node {
public:
    int data;
    int row;
    int col;

    node(int d, int r, int c) {
        data = d;
        row = r;
        col = c;
    }
};

// =====================================================
// CLASS: compare
// -----------------------------------------------------
// PURPOSE:
//   Custom comparator for priority_queue.
//
// FUNCTIONALITY:
//   Creates a MIN HEAP based on node->data.
//
// WHY MIN HEAP?
//   We need the smallest element among all lists
//   to maintain the current range.
// =====================================================
class compare {
public:
    bool operator()(node* a, node* b) {
        return a->data > b->data;   // Min heap
    }
};

// =====================================================
// FUNCTION: smallestRange
// -----------------------------------------------------
// PROBLEM:
//   Given k sorted lists of integers,
//   find the smallest range that includes at least
//   one number from each of the k lists.
//
// EXAMPLE:
//
//   Input:
//   [
//     [4,10,15,24,26],
//     [0,9,12,20],
//     [5,18,22,30]
//   ]
//
//   Output:
//   [20,24]
//
// APPROACH (MIN HEAP + GREEDY):
//
//   1️⃣ Insert the first element of each list into
//      a min heap.
//
//   2️⃣ Track:
//        mini → smallest element
//        maxi → largest element
//
//   3️⃣ Current range = maxi - mini
//
//   4️⃣ Pop the minimum element from heap.
//
//   5️⃣ Insert the next element from the same list.
//
//   6️⃣ Update maxi and check if new range is smaller.
//
//   7️⃣ Stop when any list is exhausted.
//
// TIME COMPLEXITY:
//   O(N log K)
//
//   N → total elements
//   K → number of lists
//
// SPACE COMPLEXITY:
//   O(K)
// =====================================================
vector<int> smallestRange(vector<vector<int>>& nums) {

    int mini = INT_MAX;
    int maxi = INT_MIN;

    // Min Heap storing node pointers
    priority_queue<node*, vector<node*>, compare> minHeap;

    int k = nums.size();

    // -------------------------------------------------
    // STEP 1: Insert first element of each list
    // -------------------------------------------------
    for (int i = 0; i < k; i++) {

        int element = nums[i][0];

        maxi = max(maxi, element);
        mini = min(mini, element);

        minHeap.push(new node(element, i, 0));
    }

    // Initial range
    int ansStart = mini;
    int ansEnd = maxi;

    // -------------------------------------------------
    // STEP 2: Process heap
    // -------------------------------------------------
    while (!minHeap.empty()) {

        node* top = minHeap.top();
        minHeap.pop();

        int topelement = top->data;
        int topRow = top->row;
        int topCol = top->col;

        // Update minimum element
        mini = topelement;

        // Current range
        int currRange = maxi - mini;
        int ansRange = ansEnd - ansStart;

        // Update answer if better range found
        if (currRange < ansRange) {
            ansStart = mini;
            ansEnd = maxi;
        }

        // -------------------------------------------------
        // STEP 3: Insert next element from same list
        // -------------------------------------------------
        if (topCol + 1 < nums[topRow].size()) {

            int nextVal = nums[topRow][topCol + 1];

            maxi = max(maxi, nextVal);

            minHeap.push(new node(nextVal, topRow, topCol + 1));
        }
        else {
            // If one list finishes, we cannot cover all lists
            break;
        }
    }

    return {ansStart, ansEnd};
}

// =====================================================
// MAIN FUNCTION
// -----------------------------------------------------
// PURPOSE:
//   Demonstrates smallest range covering elements
//   from all lists.
// =====================================================
int main() {

    /*
        Input:
        [
          [4,10,15,24,26],
          [0,9,12,20],
          [5,18,22,30]
        ]

        Output:
        Smallest Range = [20, 24]
    */

    vector<vector<int>> nums = {
        {4, 10, 15, 24, 26},
        {0, 9, 12, 20},
        {5, 18, 22, 30}
    };

    vector<int> result = smallestRange(nums);

    cout << "Smallest Range is: ["
         << result[0] << ", " << result[1] << "]" << endl;

    return 0;
}