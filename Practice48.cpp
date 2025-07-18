#include <iostream>
#include <vector>
using namespace std;

int main() {

    // Input array to be sorted
    vector<int> arr{10, 1, 7, 6, 14, 9};
    int n = arr.size(); // Get size of the array

    // ============================================================
    // Insertion Sort Algorithm:
    // - We assume the first element is already sorted.
    // - We pick the next element (from index 1 onwards) and
    //   insert it into the correct position in the sorted part.
    // ============================================================

    for (int round = 1; round < n; round++) {
        // ----------------------
        // Step A: Fetch the value to be inserted
        // ----------------------
        int val = arr[round]; // Current element to insert into sorted part

        // ----------------------
        // Step B: Compare and shift elements in sorted part
        // from right to left as long as they are greater than 'val'
        // ----------------------
        int j = round - 1; // Start comparing from the last sorted index

        for (; j >= 0; j--) {
            if (arr[j] > val) {
                // ----------------------
                // Step C: Shift the larger element to the right
                // ----------------------
                arr[j + 1] = arr[j]; // Move current element to the next index
            }
            else {
                // If current element is smaller or equal to 'val',
                // then stop shifting
                break;
            }
        }

        // ----------------------
        // Step D: Place the fetched value at its correct position
        // ----------------------
        arr[j + 1] = val; // Insert 'val' at the correct sorted position
    }

    // ============================================================
    // Print the sorted array
    // ============================================================
    cout << "Sorted array in ascending order: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " "; // Output each element
    }
    cout << endl; // Newline after printing all elements

    return 0; // Indicate successful execution
}
