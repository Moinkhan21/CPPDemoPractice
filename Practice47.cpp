#include <iostream>
#include <vector>
using namespace std;

int main() {

    // Input array to be sorted
    vector<int> arr{10, 1, 7, 6, 14, 9};
    int n = arr.size(); // Store size of the array

    // ============================================================
    // Bubble Sort Algorithm:
    // This algorithm repeatedly compares adjacent elements and
    // swaps them if they are in the wrong order (ascending here).
    //
    // With each round, the largest unsorted element is "bubbled up"
    // to its correct position.
    // ============================================================

    // Outer loop represents the number of rounds
    // Total rounds needed = n - 1
    for (int round = 1; round < n; round++) {

        // Flag to detect whether any swap occurred in the current round
        // If no swap happens, the array is already sorted — early termination
        bool swapped = false;

        // Inner loop goes up to the last unsorted element
        // With each round, the last (round - 1) elements are already sorted
        for (int i = 0; i < n - round; i++) {

            // Compare current element with next element
            if (arr[i] > arr[i + 1]) {
                // If elements are in the wrong order, swap them
                swap(arr[i], arr[i + 1]);
                swapped = true; // Mark that a swap occurred
            }
        }

        // Optimization: If no swap occurred in this round,
        // the array is already sorted — exit early
        if (!swapped) {
            break;
        }
    }

    // ============================================================
    // Print the sorted array after Bubble Sort
    // ============================================================
    cout << "Sorted array in ascending order: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " "; // Print each element with space
    }
    

    return 0; // Indicate successful program execution
}
