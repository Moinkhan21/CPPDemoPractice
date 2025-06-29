#include <iostream>
#include <algorithm> // Required for std::sort
using namespace std;

// ============================
// Function: findDuplicate
// Purpose: Finds and returns the first duplicate element in the array
// ============================
int findDuplicate(int arr[], int n) {
    // Step 1: Sort the array so that duplicates will appear next to each other
    sort(arr, arr + n);

    // Step 2: Traverse the sorted array and compare adjacent elements
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] == arr[i + 1]) {
            return arr[i]; // Found duplicate, return it
        }
    }

    // If no duplicates found, return -1
    return -1;
}

// ============================
// Function: main
// Purpose: Handles user input, calls the duplicate finder, and prints output
// ============================
int main() {
    int n;

    // Ask user to input number of elements
    cout << "Enter number of elements: ";
    cin >> n;

    // Declare array of user-defined size
    int arr[n];

    // Step 1: Input elements from the user
    cout << "Enter " << n << " elements: " << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Step 2: Display the entered array
    cout << "Array elements: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Step 3: Call the function to find a duplicate
    int duplicate = findDuplicate(arr, n);

    // Step 4: Output the result
    if (duplicate != -1) {
        cout << "Duplicate element found: " << duplicate << endl;
    } else {
        cout << "No duplicate element found." << endl;
    }

    // End of program
    return 0;
}
