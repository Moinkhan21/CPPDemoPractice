#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

// =====================================================
// MAIN FUNCTION
// -----------------------------------------------------
// PROBLEM:
//   Given an array of packets where each packet contains
//   some chocolates, and m students:
//
//   👉 Each student must get exactly one packet
//   👉 We need to minimize the difference between
//      maximum and minimum chocolates given
//
// GOAL:
//   Find minimum (max - min) among chosen packets
//
// EXAMPLE:
//   arr = {3, 4, 1, 9, 56, 7, 9, 12}
//   m = 5
//
//   Output = 6
//
// APPROACH: GREEDY + SORTING + SLIDING WINDOW
//
// IDEA:
//   1️⃣ Sort the array
//   2️⃣ Take window of size m
//   3️⃣ Compute difference between last & first
//   4️⃣ Slide window and keep minimum difference
//
// WHY SORT?
//   • Best group will be in contiguous sorted order
//
// TIME COMPLEXITY:
//   • O(N log N) → sorting
//
// SPACE COMPLEXITY:
//   • O(1)
// =====================================================
int main() {

    int n = 8;   // number of packets
    int m = 5;   // number of students

    int arr[] = {3, 4, 1, 9, 56, 7, 9, 12};

    // -------------------------------------------------
    // STEP 1: Sort the array
    // -------------------------------------------------
    // Sorted array:
    // {1, 3, 4, 7, 9, 9, 12, 56}
    sort(arr, arr + n);

    // -------------------------------------------------
    // STEP 2: Sliding window of size m
    // -------------------------------------------------
    int i = 0;        // Start of window
    int j = m - 1;    // End of window

    int diff = INT_MAX;  // Minimum difference

    // -------------------------------------------------
    // STEP 3: Slide window
    // -------------------------------------------------
    while (j < n) {

        // Calculate difference of current window
        int newDiff = arr[j] - arr[i];

        // Update minimum difference
        diff = min(diff, newDiff);

        // Move window forward
        i++;
        j++;
    }

    // -------------------------------------------------
    // FINAL ANSWER
    // -------------------------------------------------
    cout << "Answer is: " << diff << endl;

    return 0;
}
