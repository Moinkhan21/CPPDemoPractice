#include <iostream>
#include <vector>
using namespace std;

// ---------------- FUNCTION: checkSorted ----------------
// Purpose: Check if a given array is sorted in ascending order
// using recursion.
//
// Parameters:
//   arr -> reference to the vector of integers
//   n   -> size of the array
//   i   -> current index being checked
//
// Returns:
//   true  -> if the array is sorted
//   false -> if any element is found unsorted
bool checkSorted(vector<int> &arr, int& n, int i){

    // ---------- BASE CASE ----------
    // If we reach the last element (index = n-1),
    // there are no further elements to compare.
    // Hence, array is sorted till the end.
    if(i == n-1){
        return true;
    }

    // ---------- PROCESS ONE CASE ----------
    // Compare current element with the next one.
    // If next element is smaller, array is not sorted.
    if(arr[i+1] < arr[i])
        return false;

    // ---------- RECURSIVE CALL ----------
    // Move forward and check the next pair
    return checkSorted(arr, n, i+1);
}

int main() {
    // Example array
    vector<int> v{10, 20, 30, 50, 60};

    int n = v.size();   // Size of the array
    int i = 0;          // Start checking from index 0

    // Call recursive function to check if sorted
    bool isSorted = checkSorted(v, n, i);

    // Print the result
    if(isSorted) {
        cout << "Array is sorted" << endl;
    }
    else {
        cout << "Array is not sorted" << endl;
    }
}
