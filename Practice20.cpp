#include <iostream>
#include <vector>
using namespace std;

// Function to sort the colors (Dutch National Flag problem)
void sortColors(vector<int>& nums){
    // Count the number of 0s, 1s, and 2s
    int zeros = 0, ones = 0, twos = 0;

    for(int i = 0; i < nums.size(); i++){
        if(nums[i] == 0){
            zeros++;
        } else if(nums[i] == 1){
            ones++;
        } else {
            twos++;
        }
    }

    // Overwrite nums based on the counts
    int i = 0;
    while(zeros--) nums[i++] = 0;
    while(ones--)  nums[i++] = 1;
    while(twos--)  nums[i++] = 2;
}

int main(){
    int n;
    cout << "Enter the size of the vector: ";
    cin >> n;

    vector<int> nums(n); // Resize the vector to size n

    cout << "Enter " << n << " elements (only 0s, 1s, and 2s):" << endl;
    for(int i = 0; i < n; i++){
        cin >> nums[i]; // Take input elements
    }

    cout << "Original array: ";
    for(int i = 0; i < n; i++){
        cout << nums[i] << " ";
    }
    cout << endl;

    // Sort the colors
    sortColors(nums);

    // Output the sorted array
    cout << "Sorted array: ";
    for(int i = 0; i < n; i++){
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}
