#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// =====================================================
// FUNCTION: callMedian
// -----------------------------------------------------
// PURPOSE:
//   Maintains the median of a running stream of numbers
//   using two heaps.
//
// PARAMETERS:
//   • median   → current median (updated after each insert)
//   • maxHeap  → stores smaller half of numbers (MAX heap)
//   • minHeap  → stores larger half of numbers (MIN heap)
//   • element  → new incoming element from the stream
//
// KEY IDEA (TWO HEAPS):
//   • maxHeap keeps elements ≤ median
//   • minHeap keeps elements ≥ median
//   • Size difference between heaps is at most 1
//
// MEDIAN RULES:
//   • Equal sizes → median = top of heap containing element
//   • Unequal sizes → median = average of both heap tops
//
// TIME COMPLEXITY:
//   • Each insertion → O(log N)
//
// SPACE COMPLEXITY:
//   • O(N)
// =====================================================
void callMedian(
    int &median,
    priority_queue<int>& maxHeap,
    priority_queue<int, vector<int>, greater<int>>& minHeap,
    int element
) {

    // -------------------------------------------------
    // CASE 1: Both heaps have equal size
    // -------------------------------------------------
    if (minHeap.size() == maxHeap.size()) {

        // If element belongs to right side
        if (element > median) {
            minHeap.push(element);
            median = minHeap.top();
        }
        // If element belongs to left side
        else {
            maxHeap.push(element);
            median = maxHeap.top();
        }
    }

    // -------------------------------------------------
    // CASE 2: maxHeap has more elements than minHeap
    // -------------------------------------------------
    else if (maxHeap.size() > minHeap.size()) {

        // Element belongs to right side
        if (element > median) {
            minHeap.push(element);
            median = (minHeap.top() + maxHeap.top()) / 2;
        }
        // Element belongs to left side
        else {
            // Balance the heaps
            int maxTop = maxHeap.top();
            maxHeap.pop();

            minHeap.push(maxTop);
            maxHeap.push(element);

            median = (minHeap.top() + maxHeap.top()) / 2;
        }
    }

    // -------------------------------------------------
    // CASE 3: minHeap has more elements than maxHeap
    // -------------------------------------------------
    else {
        // Element belongs to right side
        if (element > median) {
            // Balance the heaps
            int minTop = minHeap.top();
            minHeap.pop();

            maxHeap.push(minTop);
            minHeap.push(element);

            median = (minHeap.top() + maxHeap.top()) / 2;
        }
        // Element belongs to left side
        else {
            maxHeap.push(element);
            median = (minHeap.top() + maxHeap.top()) / 2;
        }
    }
}

// =====================================================
// MAIN FUNCTION (TEST CASE)
// =====================================================
int main() {

    /*
        Input stream:
        [5, 7, 2, 9, 3, 8]

        Running medians:
        5 → 6 → 5 → 6 → 5 → 6

        Explanation:
        • Median is updated after every insertion
        • Uses two heaps for efficient balancing
    */

    int arr[6] = {5, 7, 2, 9, 3, 8};
    int n = 6;

    int median = 0;

    // maxHeap → left half (smaller elements)
    priority_queue<int> maxHeap;

    // minHeap → right half (larger elements)
    priority_queue<int, vector<int>, greater<int>> minHeap;

    // Process stream elements one by one
    for (int i = 0; i < n; i++) {
        int element = arr[i];

        callMedian(median, maxHeap, minHeap, element);

        cout << "-> " << median << " ";
    }

    cout << endl;
    return 0;
} 
