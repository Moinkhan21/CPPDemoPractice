#include <iostream>
using namespace std;

// ========================================================
// Function: findMissing
// Purpose : To find all missing elements from the array
//           using the **cyclic sort** technique.
// Logic   : Each element is placed at its correct index,
//           i.e., element `x` should be at index `x - 1`.
//           After arranging, the element at index `i`
//           should be `i + 1`. If not, it's missing.
// ========================================================
void findMissing(int *a, int n) {
    
    int i = 0;

    // Step 1: Place each element at its correct index
    while (i < n) {
        int index = a[i] - 1; // Convert value to zero-based index

        // Only swap if current element is not at correct position
        // and target position doesn't already hold the correct value
        if (a[i] >= 1 && a[i] <= n && a[i] != a[index]) {
            swap(a[i], a[index]); // Place the current element at the right index
        } else {
            i++; // Move to next element if already placed correctly
        }
    }

    // Step 2: Identify missing elements
    cout << "Missing element(s): ";
    bool found = false;
    for (int i = 0; i < n; i++) {
        // If the value at index i is not i + 1, that means i + 1 is missing
        if (a[i] != i + 1) {
            cout << i + 1 << " ";
            found = true;
        }
    }

    // If all elements are present
    if (!found) {
        cout << "None";
    }

    cout << endl;
}

int main() {
    // Sample array with a missing number
    int a[] = {1, 3, 5, 3, 4};

    // Calculate the size of the array
    int n = sizeof(a) / sizeof(int);

    // Function call to find missing numbers
    findMissing(a, n);

    return 0; // Indicate successful program execution
}
