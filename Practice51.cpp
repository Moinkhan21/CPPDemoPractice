#include <iostream>
#include <vector>
#include <cmath>    // for abs() function to calculate absolute difference
using namespace std;

/*
---------------------------------------------------------
Function: twoPointerMethod
Purpose : Finds k closest elements to target x using the
          two-pointer shrinking window approach.
Params  :
    - arr : sorted input array
    - k   : number of closest elements to find
    - x   : target value
Returns :
    A vector containing k closest elements to x
---------------------------------------------------------
*/
vector<int> twoPointerMethod(vector<int>& arr, int k, int x) {
    // Initialize two pointers at the start and end of the array
    int left = 0;
    int right = arr.size() - 1;

    // Keep reducing the window size until we are left with exactly k elements
    while (right - left >= k) {
        // Compare absolute difference between x and values at the boundaries
        if (abs(x - arr[left]) > abs(arr[right] - x)) {
            // If the left value is farther from x, move the left pointer forward
            left++;
        } else {
            // Else, the right value is farther from x, move the right pointer backward
            right--;
        }
    }

    // Once the loop ends, the window between left and right (inclusive) has exactly k closest elements
    // Return that window as a new vector
    return vector<int>(arr.begin() + left, arr.begin() + right + 1);
}

/*
---------------------------------------------------------
Function: findClosestElements
Purpose : Wrapper function to call the actual method
---------------------------------------------------------
*/
vector<int> findClosestElements(vector<int>& arr, int k, int x) {
    // Simply calls the twoPointerMethod
    return twoPointerMethod(arr, k, x);
}

/*
---------------------------------------------------------
Main Function
Purpose : Demonstrates the working of the above function
---------------------------------------------------------
*/
int main() {
    // Sample input: sorted array of integers
    vector<int> arr = {12, 16, 22, 30, 35, 39, 40, 42, 45, 48, 50, 53, 55, 56};

    // Number of closest elements to find
    int k = 4;

    // Target value to find closest elements to
    int x = 35;

    // Call the function to find k closest elements
    vector<int> result = findClosestElements(arr, k, x);

    // Output the result
    cout << "The " << k << " closest elements to " << x << " are:\n";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
