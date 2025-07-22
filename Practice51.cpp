#include <iostream>
#include <vector>
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
    int left = 0;
    int right = arr.size() - 1;

    // Shrink the window size until it becomes exactly size k
    while (right - left >= k) {
        if (abs(x - arr[left]) > abs(arr[right] - x)) {
            left++;  // Left element is farther, discard it
        } else {
            right--; // Right element is farther, discard it
        }
    }

    // Copy the resulting subarray of size k
    return vector<int>(arr.begin() + left, arr.begin() + right + 1);
}

/*
---------------------------------------------------------
Function: findClosestElements
Purpose : Wrapper function to call the actual method
---------------------------------------------------------
*/
vector<int> findClosestElements(vector<int>& arr, int k, int x) {
    return twoPointerMethod(arr, k, x);
}

/*
---------------------------------------------------------
Main Function: Demonstrates working of the function
---------------------------------------------------------
*/
int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    int k = 4;
    int x = 3;

    vector<int> result = findClosestElements(arr, k, x);

    cout << "The " << k << " closest elements to " << x << " are:\n";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
