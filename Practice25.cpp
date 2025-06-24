#include <iostream>
using namespace std;

/*
  Function to find the duplicate element in the array using 
  in-place cyclic sort based logic. Assumes values range from 0 to n-1.
*/
int findDuplicate(int arr[], int n) {
    // Continue swapping until the value at index 0 equals the value at its correct position
    while (arr[0] != arr[arr[0]]) {
        // Swap arr[0] with arr[arr[0]] to move elements to their correct positions
        swap(arr[0], arr[arr[0]]);
    }

    // Once duplicate is found (same value found at two correct positions)
    return arr[0];
}

int main() {
    int n;

    // Prompt user to enter number of elements
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n]; // Declare an array of size n

    // Input elements from the user
    cout << "Enter " << n << " elements (values must be in range 0 to n-1 with one duplicate):" << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Display the original array
    cout << "Array elements: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Call function to find duplicate
    int duplicate = findDuplicate(arr, n);

    // Display result
    if (duplicate != -1) {
        cout << "Duplicate element found: " << duplicate << endl;
    } else {
        cout << "No duplicate element found." << endl;
    }

    return 0; // End of program
}
