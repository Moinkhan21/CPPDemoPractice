#include <iostream>
#include <vector>
using namespace std;

// Function to sort a vector containing only 0s, 1s, and 2s
void sortColors(vector<int>& nums){
    // Step 1: Count the number of 0s, 1s, and 2s
    int zeros = 0, ones = 0, twos = 0;

    // Traverse the input vector and count occurrences
    for(int i = 0; i < nums.size(); i++){
        if(nums[i] == 0){
            zeros++; // Increment count of 0s
        } else if(nums[i] == 1){
            ones++;  // Increment count of 1s
        } else {
            twos++;  // Increment count of 2s
        }
    }

    // Step 2: Overwrite the vector based on the counts
    int i = 0;

    // Fill in 0s
    while(zeros--){
        nums[i++] = 0;
    }

    // Fill in 1s
    while(ones--){
        nums[i++] = 1;
    }

    // Fill in 2s
    while(twos--){
        nums[i++] = 2;
    }
}

int main(){
    int n;
    
    // Step 1: Input the size of the vector
    cout << "Enter the size of the vector: ";
    cin >> n;

    // Step 2: Initialize a vector with size 'n'
    vector<int> nums(n);

    // Step 3: Input elements into the vector
    cout << "Enter " << n << " elements (only 0s, 1s, and 2s):" << endl;
    for(int i = 0; i < n; i++){
        cin >> nums[i]; // Store user input into vector
    }

    // Step 4: Display the original array before sorting
    cout << "Original array: ";
    for(int i = 0; i < n; i++){
        cout << nums[i] << " ";
    }
    cout << endl;

    // Step 5: Sort the vector using the counting approach
    sortColors(nums);

    // Step 6: Display the sorted array
    cout << "Sorted array: ";
    for(int i = 0; i < n; i++){
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0; // Successful execution
}
