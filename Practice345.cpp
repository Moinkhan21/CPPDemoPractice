#include <iostream>
#include <queue>
using namespace std;

// ======================================================================
// FUNCTION: getKthGreatestElement()
// ----------------------------------------------------------------------
// PURPOSE:
//   Finds the K-th GREATEST element in an array using a MIN HEAP.
//
// WHY MIN HEAP?
//   • We keep only the TOP K greatest elements seen so far.
//   • The smallest among them (heap top) represents
//     the K-th greatest element.
//
// APPROACH:
//   1️⃣ Create a MIN HEAP of size K
//   2️⃣ Insert first K elements
//   3️⃣ For remaining elements:
//        - If element > heap top:
//            → remove top
//            → insert element
//   4️⃣ Heap top is the answer
//
// TIME COMPLEXITY:
//   • O(n log k)
//
// SPACE COMPLEXITY:
//   • O(k)
// ======================================================================
int getKthGreatestElement(int arr[], int n, int k) {

    // --------------------------------------------------
    // Create MIN HEAP
    // priority_queue with greater<int> comparator
    // --------------------------------------------------
    priority_queue<int, vector<int>, greater<int>> pq;

    // --------------------------------------------------
    // STEP 1: Insert first K elements into heap
    // --------------------------------------------------
    for (int i = 0; i < k; i++) {
        pq.push(arr[i]);
    }

    // --------------------------------------------------
    // STEP 2: Process remaining elements
    // --------------------------------------------------
    for (int i = k; i < n; i++) {

        int element = arr[i];

        // If current element is greater than heap top
        if (element > pq.top()) {

            // Remove smallest element
            pq.pop();

            // Insert new larger element
            pq.push(element);
        }
    }

    // --------------------------------------------------
    // Heap top is the K-th greatest element
    // --------------------------------------------------
    int ans2 = pq.top();
    return ans2;
}

// ======================================================================
// FUNCTION: getKthSmallestElement()
// ----------------------------------------------------------------------
// PURPOSE:
//   Finds the K-th SMALLEST element in an array using a MAX HEAP.
//
// WHY MAX HEAP?
//   • We keep only the TOP K smallest elements.
//   • The largest among them (heap top) represents
//     the K-th smallest element.
//
// APPROACH:
//   1️⃣ Create a MAX HEAP of size K
//   2️⃣ Insert first K elements
//   3️⃣ For remaining elements:
//        - If element < heap top:
//            → remove top
//            → insert element
//   4️⃣ Heap top is the answer
//
// TIME COMPLEXITY:
//   • O(n log k)
//
// SPACE COMPLEXITY:
//   • O(k)
// ======================================================================
int getKthSmallestElement(int arr[], int n, int k) {

    // --------------------------------------------------
    // Create MAX HEAP
    // --------------------------------------------------
    priority_queue<int> pq;

    // --------------------------------------------------
    // STEP 1: Insert first K elements into heap
    // --------------------------------------------------
    for (int i = 0; i < k; i++) {
        pq.push(arr[i]);
    }

    // --------------------------------------------------
    // STEP 2: Process remaining elements
    // --------------------------------------------------
    for (int i = k; i < n; i++) {

        int element = arr[i];

        // If current element is smaller than heap top
        if (element < pq.top()) {

            // Remove largest element
            pq.pop();

            // Insert smaller element
            pq.push(element);
        }
    }

    // --------------------------------------------------
    // Heap top is the K-th smallest element
    // --------------------------------------------------
    int ans1 = pq.top();
    return ans1;
}

// ======================================================================
// MAIN FUNCTION
// ----------------------------------------------------------------------
// PURPOSE:
//   Demonstrates finding:
//   • K-th Smallest element
//   • K-th Greatest element
//
// ARRAY:
//   {10, 5, 20, 4, 15}
//
// SORTED:
//   {4, 5, 10, 15, 20}
//
// K = 2
//   • 2nd smallest → 5
//   • 2nd greatest → 15
// ======================================================================
int main() {

    int arr[] = {10, 5, 20, 4, 15};
    int n = 5;
    int k = 2;

    // Find K-th Smallest
    int ans1 = getKthSmallestElement(arr, n, k);
    cout << "K-th Smallest Element: " << ans1 << endl;

    // Find K-th Greatest
    int ans2 = getKthGreatestElement(arr, n, k);
    cout << "K-th Greatest Element: " << ans2 << endl;

    return 0;
}
