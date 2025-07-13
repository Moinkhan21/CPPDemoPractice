#include <iostream>
#include <vector>
using namespace std;

// ===============================================================
// Function: binarySearch
// Purpose : To find the target in a nearly sorted array where 
//           every element may be misplaced by at most 1 index.
// Time    : O(log n)
// Input   : arr - vector of integers, target - value to search
// Output  : Index of target if found, else -1
// ===============================================================
int binarySearch(vector<int> arr, int target) {
    int s = 0;                    // Start index
    int e = arr.size() - 1;       // End index

    int mid = s + (e - s) / 2;    // Calculate mid to avoid overflow

    while (s <= e) {
        // Case 1: Target is found at mid
        if (arr[mid] == target)
            return mid;

        // Case 2: Target might be just one position left of mid
        if (mid - 1 >= 0 && arr[mid - 1] == target)
            return mid - 1;

        // Case 3: Target might be just one position right of mid
        if (mid + 1 < arr.size() && arr[mid + 1] == target)
            return mid + 1;

        // Case 4: Search in the right half by skipping mid and mid+1
        if (arr[mid] < target) {
            s = mid + 2;
        }
        // Case 5: Search in the left half by skipping mid and mid-1
        else {
            e = mid - 2;
        }

        // Update mid for next iteration
        mid = s + (e - s) / 2;
    }

    return -1; // If target is not found
}

// ===============================================================
// Main Function: Entry point of the program
// ===============================================================
int main() {
    // Nearly sorted array: each element is at most 1 position away
    vector<int> arr{10, 3, 40, 20, 50, 80, 70};

    int target = 40; // Element to be searched

    // Call binary search function
    int ans = binarySearch(arr, target);

    // Output result
    cout << "Index of " << target << " is: " << ans << endl;

    return 0; // Successful execution
}
