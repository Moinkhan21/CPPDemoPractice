#include <iostream>
#include <climits> // For INT_MIN and INT_MAX
using namespace std;

int main() {

    // ==========================
    // 1. Count number of 0s and 1s in an array
    // ==========================
    int arr[] = {0, 1, 1, 1, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1};
    int size = 15;

    int numZero = 0;  // Counter for number of 0s
    int numOne = 0;   // Counter for number of 1s

    // Loop through each element to count 0s and 1s
    for(int i = 0; i < size; i++) {
        if(arr[i] == 0) {
            numZero++; // Increment zero counter
        }
        if(arr[i] == 1) {
            numOne++; // Increment one counter
        }
    }

    // Output the counts
    cout << "Number of 0s: " << numZero << endl;
    cout << "Number of 1s: " << numOne << endl;

    // ==========================
    // 2. Find maximum element in an array
    // ==========================
    int arr1[] = {2, 4, 6, 1, 3, 7, 9, 12, 56, 43, 21};
    int size1 = 11;

    int maxi = INT_MIN; // Initialize with smallest integer value

    for(int i = 0; i < size1; i++) {
        if(arr1[i] > maxi) {
            maxi = arr1[i]; // Update max if current element is larger
        }
    }

    cout << "Maximum value in arr1: " << maxi << endl;

    // ==========================
    // 3. Find minimum element in another array
    // ==========================
    int arr2[] = {2, 4, 6, 1, 3, 7, 9, 12, 56, 43, 21};
    int size2 = 11;

    int mini = INT_MAX; // Initialize with largest integer value

    for(int i = 0; i < size2; i++) {
        if(arr2[i] < mini) {
            mini = arr2[i]; // Update min if current element is smaller
        }
    }

    cout << "Minimum value in arr2: " << mini << endl;

    // Return 0 to indicate successful execution
    return 0;
}
