#include <iostream>
using namespace std;

// Function to find a duplicate in the array using index marking technique
int findDuplicate(int arr[], int n) {
    int ans = -1;  // Initialize answer to -1 (no duplicate found by default)

    // Traverse each element in the array
    for (int i = 0; i < n; i++) {
        int index = abs(arr[i]);  // Use absolute value to get original index

        // Check if the element at this index is already negative (visited before)
        if (arr[index] < 0) {
            ans = index;  // If yes, this index is the duplicate number
            break;
        }

        // Otherwise, mark this index as visited by making it negative
        arr[index] *= -1;
    }

    return ans;  // Return the duplicate value if found, otherwise -1
}

int main() {
    int n;

    // Ask user for number of elements
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];  // Declare array of size n

    // Input elements from user
    cout << "Enter " << n << " elements (values should be from 0 to n-1):" << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Display the entered array
    cout << "Array elements: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Find the duplicate using the function
    int duplicate = findDuplicate(arr, n);

    // Output the result
    if (duplicate != -1) {
        cout << "Duplicate element found: " << duplicate << endl;
    } else {
        cout << "No duplicate element found." << endl;
    }

    return 0; // Indicate successful execution
}
