#include <iostream>
#include <vector>
using namespace std;

// ============================================
// Function: solve
// Purpose : To find the index of the single element
//           in a sorted array where every other
//           element appears exactly twice.
// Logic   : Uses modified binary search.
//           Works only if the array is sorted such
//           that pairs appear consecutively.
// ============================================
int solve(vector<int> arr) {
    int s = 0;                          // Start pointer
    int e = arr.size() - 1;            // End pointer
    int mid = s + (e - s) / 2;         // Mid-point to avoid overflow

    while (s <= e) {
        // Case 1: Only one element remains — this is the unique one
        if (s == e) {
            return s;
        }

        // Case 2: Check parity of mid index
        if (mid % 2 == 0) {
            // If mid is even and the pair is correctly aligned
            if (arr[mid] == arr[mid + 1]) {
                s = mid + 2;           // Unique element must be in the right half
            } else {
                e = mid;               // Unique element is at mid or in left half
            }
        } else {
            // If mid is odd and the pair is correctly aligned
            if (arr[mid] == arr[mid - 1]) {
                s = mid + 1;           // Unique element must be in the right half
            } else {
                e = mid - 1;           // Unique element is in the left half
            }
        }

        // Recalculate mid after updating the search space
        mid = s + (e - s) / 2;
    }

    return -1; // Should never reach here if input is valid
}

// ============================================
// Main function
// ============================================
int main() {
    // Input array where every element appears exactly twice, except one
    vector<int> arr{1, 1, 2, 2, 3, 3, 4, 4, 3, 600, 600, 4, 4};

    // Call the solve function to find the index of the unique element
    int ans = solve(arr);

    // Output the result
    cout << "The answer is: " << ans << endl;
    cout << "The element is: " << arr[ans] << endl;

    return 0; // Successful execution
}
