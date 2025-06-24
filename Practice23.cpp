#include <iostream>
#include <algorithm> // Required for std::sort
using namespace std;

// Function to find a duplicate in an array
int findDuplicate(int arr[], int n) {
    // Sort the array first to bring duplicates together
    sort(arr, arr + n);

    // Traverse the array and compare adjacent elements
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] == arr[i + 1]) {
            return arr[i]; // Found duplicate
        }
    }

    return -1; // No duplicate found
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n]; // Declare array of size n

    // Input elements
    cout << "Enter " << n << " elements: " << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Print array
    cout << "Array elements: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Call function and print duplicate
    int duplicate = findDuplicate(arr, n);
    if (duplicate != -1) {
        cout << "Duplicate element found: " << duplicate << endl;
    } else {
        cout << "No duplicate element found." << endl;
    }

    return 0;
}
