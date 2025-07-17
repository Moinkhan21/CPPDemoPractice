#include <iostream>
#include <vector>
using namespace std;

int main() {

    vector<int> arr{10, 1, 7, 6, 14, 9};

    int n = arr.size();

    // Bubble sort algorithm
    for(int round = 1; round < n; round++) {

            bool swapped = false; // Flag to check if any swapping occurred in this round
        // Traverse through the array up to the last unsorted element
        for(int i = 0; i < n - round; i++) {
            if(arr[i] > arr[i + 1]) {
                swapped = true; // Set the flag if a swap occurs
                swap(arr[i], arr[i + 1]); // Swap if the current element is greater than the next
            }
        }
        if(!swapped) {
            break; // If no swaps occurred, the array is sorted
        }
    }

    // Printing the sorted array
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }   
    cout << endl;

    return 0;
}

