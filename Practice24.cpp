#include <iostream>
using namespace std;

// ==========================================================
// Function: findDuplicate
// Purpose : Finds a duplicate element in the array using the
//           index marking technique (modifies array in-place).
// Time    : O(n), Space: O(1)
// Constraints: Elements must be in range [0, n-1]
// ==========================================================
int findDuplicate(int arr[], int n) {
    int ans = -1;  // Default result if no duplicate found

    // Traverse through the array
    for (int i = 0; i < n; i++) {
        int index = abs(arr[i]);  // Use absolute value to avoid sign confusion

        // Check if the value at this index is already negative
        if (arr[index] < 0) {
            ans = index;  // Found a duplicate
            break;
        }

        // Mark this index as visited by making the value negative
        arr[index] *= -1;
    }

    return ans;  // Return the found duplicate or -1
}

int main() {
    int n;

    // Step 1: Input the number of elements
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n]; // Step 2: Declare array of size n

    // Step 3: Input elements from user
    cout << "Enter " << n << " elements (values from 0 to n-1):" << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Step 4: Display the entered array
    cout << "Array elements: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Step 5: Call the function to find the duplicate
    int duplicate = findDuplicate(arr, n);

    // Step 6: Output the result
    if (duplicate != -1) {
        cout << "Duplicate element found: " << duplicate << endl;
    } else {
        cout << "No duplicate element found." << endl;
    }

    return 0;  // Indicate successful program termination
}
