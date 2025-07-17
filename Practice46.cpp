#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Input array to be sorted
    vector<int> arr{5, 4, 3, 2, 1};
    int n = arr.size(); // Size of the array

    // ======================================================
    // Selection Sort Algorithm:
    // Sorts the array in ascending order by repeatedly
    // finding the minimum element from the unsorted part
    // and placing it at the beginning.
    // Time Complexity: O(n^2)
    // Space Complexity: O(1) - In-place sorting
    // ======================================================

    // Outer loop: Runs (n - 1) times for each position in the array
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i; // Assume the current index holds the minimum value

        // Inner loop: Search for the actual minimum element in the unsorted part
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j; // Update minIndex if a smaller element is found
            }
        }

        // Swap the smallest element found with the element at current position i
        // This places the correct element at index i in the sorted portion
        swap(arr[i], arr[minIndex]);
    }

    // ======================================================
    // Print the sorted array
    // ======================================================
    cout << "Sorted array in ascending order: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " "; // Output each element followed by a space
    }
    cout << endl; // Print newline for clean output

    return 0; // Successful execution
}
