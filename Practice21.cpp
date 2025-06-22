#include <iostream>
#include <vector>
using namespace std;

// Function to sort a vector containing only 0s, 1s, and 2s using Dutch National Flag Algorithm
void sortColors(vector<int>& nums) {
    int low = 0;                // Points to the next position to place 0
    int mid = 0;                // Current index being processed
    int high = nums.size() - 1; // Points to the next position to place 2

    // Continue processing until mid crosses high
    while(mid <= high) {
        if(nums[mid] == 0) {
            // Swap the current element with the element at 'low'
            swap(nums[low], nums[mid]);
            low++;  // Move the 'low' pointer forward
            mid++;  // Move to the next element
        }
        else if(nums[mid] == 1) {
            // Leave 1 in the middle and just move forward
            mid++;
        }
        else {
            // nums[mid] == 2
            // Swap current element with the element at 'high'
            swap(nums[mid], nums[high]);
            high--; // Move the 'high' pointer backward
            // Do not move 'mid' here because the swapped element needs to be checked
        }
    }
}

int main() {
    int n;
    cout << "Enter the size of the vector: ";
    cin >> n;  // Input the size of the vector

    vector<int> nums(n);  // Declare a vector of size n

    // Prompt the user to input the values
    cout << "Enter " << n << " elements (only 0s, 1s, and 2s):" << endl;
    for(int i = 0; i < n; i++) {
        cin >> nums[i]; // Store user input in the vector
    }

    // Sort the vector using the Dutch National Flag Algorithm
    sortColors(nums);

    // Output the sorted array
    cout << "Sorted array: ";
    for(int i = 0; i < n; i++) {
        cout << nums[i] << " ";
    }
    cout << endl; // Move to a new line

    return 0; // Return 0 to indicate successful execution
}
