#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// =====================================================
// FUNCTION: signum
// -----------------------------------------------------
// PURPOSE:
//   Compares two integers and returns:
//
//   •  0 → if both are equal
//   •  1 → if first is greater than second
//   • -1 → if first is smaller than second
//
// WHY USE signum HERE?
//   • To compare sizes of two heaps
//   • Makes median logic clean using switch-case
// =====================================================
int signum(int a, int b) {
    if (a == b)
        return 0;
    if (a > b)
        return 1;
    if (a < b)
        return -1;
    return 0;   // Safety return
}

// =====================================================
// FUNCTION: callMedian
// -----------------------------------------------------
// PURPOSE:
//   Maintains the running median of a data stream
//   using two heaps.
//
// PARAMETERS:
//   • median   → current median (updated each step)
//   • maxHeap  → stores smaller half (MAX heap)
//   • minHeap  → stores larger half (MIN heap)
//   • element  → new incoming value
//
// KEY IDEA (TWO HEAP TECHNIQUE):
//   • maxHeap contains elements ≤ median
//   • minHeap contains elements ≥ median
//   • Heap size difference is at most 1
//
// MEDIAN RULES:
//   • Equal heap sizes → median = top of heap
//   • Unequal sizes   → median = average of tops
//
// TIME COMPLEXITY:
//   • Each insertion → O(log N)
//
// SPACE COMPLEXITY:
//   • O(N)
// =====================================================
void callMedian(double &median,
                priority_queue<int>& maxHeap,
                priority_queue<int, vector<int>, greater<int>>& minHeap,
                int element) {

    // -------------------------------------------------
    // Decide case based on heap size comparison
    // -------------------------------------------------
    switch (signum(minHeap.size(), maxHeap.size())) {

        // =================================================
        // CASE 0: Both heaps have equal size
        // =================================================
        case 0:
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
            break;

        // =================================================
        // CASE 1: minHeap has more elements than maxHeap
        // =================================================
        case 1:
            // Element belongs to right side
            if (element > median) {
                // Balance heaps
                int minTop = minHeap.top();
                minHeap.pop();

                maxHeap.push(minTop);
                minHeap.push(element);
            }
            // Element belongs to left side
            else {
                maxHeap.push(element);
            }

            // Median is average of two middle values
            median = (minHeap.top() + maxHeap.top()) / 2.0;
            break;

        // =================================================
        // CASE -1: maxHeap has more elements than minHeap
        // =================================================
        case -1:
            // Element belongs to right side
            if (element > median) {
                minHeap.push(element);
            }
            // Element belongs to left side
            else {
                // Balance heaps
                int maxTop = maxHeap.top();
                maxHeap.pop();              // Corrected pop

                minHeap.push(maxTop);
                maxHeap.push(element);
            }

            // Median is average of two middle values
            median = (minHeap.top() + maxHeap.top()) / 2.0;
            break;
    }
}

// =====================================================
// MAIN FUNCTION (TEST CASE)
// =====================================================
int main() {

    /*
        Input Stream:
        [5, 15, 1, 3, 2, 8, 7, 9, 10, 6, 11, 4]

        Output:
        Prints median after each insertion

        Example:
        5  -> median: 5
        15 -> median: 10
        1  -> median: 5
        ...
    */

    int arr[12] = {5, 15, 1, 3, 2, 8, 7, 9, 10, 6, 11, 4};
    int n = 12;

    double median = 0;

    // maxHeap → left side (smaller elements)
    priority_queue<int> maxHeap;

    // minHeap → right side (larger elements)
    priority_queue<int, vector<int>, greater<int>> minHeap;

    // Process stream one element at a time
    for (int i = 0; i < n; i++) {
        callMedian(median, maxHeap, minHeap, arr[i]);
        cout << arr[i] << " -> median: " << median << endl;
    }

    return 0;
}
