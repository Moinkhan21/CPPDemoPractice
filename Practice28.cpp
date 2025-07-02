#include <iostream>
using namespace std;

// =========================================================
// Function: firstRepeated
// Purpose : To find the first repeated element in the array
// Logic   : Use two nested loops:
//           - Outer loop picks each element
//           - Inner loop checks if it repeats later
// Return  : 1-based index of the first repeated element
//           or -1 if no duplicate is found
// =========================================================
int firstRepeated(int *a, int n) {
    // Traverse each element in the array
    for (int i = 0; i < n; i++) {
        // Flag to indicate if current element is repeated
        bool isRepeated = false;

        // Check for repetition in the remaining array
        for (int j = i + 1; j < n; j++) {
            if (a[i] == a[j]) {
                isRepeated = true;         // Mark as repeated
                return i + 1;              // Return 1-based index
            }
        }
    }

    // If no repeated element is found
    return -1;
}

int main() {
    // Initialize array with some repeated values
    int a[] = {1, 2, 3, 4, 2, 5};

    // Calculate the number of elements in the array
    int n = sizeof(a) / sizeof(int);

    // Call the function to find the first repeated element
    int result = firstRepeated(a, n);

    // Print the result
    if (result != -1) {
        cout << "First repeated element is at index (1-based): " << result << endl;
    } else {
        cout << "No repeated elements found." << endl;
    }

    return 0; // Indicate successful program execution
}
