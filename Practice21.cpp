#include <iostream>
#include <vector>
using namespace std;  

// Function to sort a vector containing only 0s, 1s, and 2s
void sortColors(vector<int>& nums) {
    int low = 0, mid = 0, high = nums.size() - 1;

    while(mid <= high){
        if(nums[mid] == 0){
            swap(nums[low], nums[mid]);
            low++;
            mid++;
        }
        else if(nums[mid] == 1){
            mid++;
        }
        else {
            swap(nums[mid], nums[high]);
            high--;
        }
    }
}


int main() {
    int n;
    cout << "Enter the size of the vector: ";
    cin >> n; // Input the size of the vector

    vector<int> nums(n); // Create a vector of size n
    cout << "Enter " << n << " elements (only 0s, 1s, and 2s):" << endl;

    // Taking input from the user
    for(int i = 0; i < n; i++) {
        cin >> nums[i]; // Store each element in the vector
    }

    // Call the function to sort colors
    sortColors(nums);

    // Output the sorted array
    cout << "Sorted array: ";
    for(int i = 0; i < n; i++) {
        cout << nums[i] << " "; // Output each element in the sorted vector
    }
    
    cout << endl; // New line after printing all elements

    // Return 0 to indicate successful execution
    return 0;   
}