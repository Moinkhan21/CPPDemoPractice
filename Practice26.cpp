#include <iostream>
using namespace std;

// ======================================================
// Function: findMissing
// Purpose : Finds the missing element from 1 to n in the
//           given array using the index marking technique.
//           This approach assumes elements range from 1 to n,
//           and modifies the array in-place.
// ======================================================
void findMissing(int *a, int n) {
    
    // Step 1: Mark the indices corresponding to elements as visited
    for (int i = 0; i < n; i++) {
        int index = abs(a[i]); // Take absolute value to avoid negative sign issues

        // Mark the value at index-1 as negative to show it's been visited
        // Only mark if it's currently positive to avoid double-negation
        if (a[index - 1] > 0) {
            a[index - 1] *= -1;
        }
    }

    // Step 2: Scan the array again to find the first positive value
    // The index (i + 1) of that value is the missing number
    for (int i = 0; i < n; i++) {
        if (a[i] > 0) {
            cout << "Missing element: " << i + 1 << endl;
            return;
        }
    }

    // If all elements are negative, then nothing is missing in the 1 to n range
    cout << "No element is missing from 1 to " << n << "." << endl;
}

int main() {
    // Sample input array (1 to 5, missing 2, but 3 appears twice)
    int a[] = {1, 3, 5, 3, 4};

    // Calculate number of elements
    int n = sizeof(a) / sizeof(int);

    // Call function to find the missing element
    findMissing(a, n);

    return 0; // Successful execution
}
