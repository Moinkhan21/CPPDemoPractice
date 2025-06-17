#include <iostream>
#include <vector>
using namespace std;

int main() {

    // Pair Sum Problem
    vector<int> arr{10, 20, 30, 40, 50}; // Initialize a vector with some elements
    int sum = 80; // Initialize a variable to hold the sum of elements

    // Printing all pairs
    // Outer loop will traverse for each element
    for(int i = 0; i < arr.size(); i++) {
            int element = arr[i]; // Get the current element
            for(int j = i + 1; j < arr.size(); j++){
                if(element + arr[j] == sum){
                    cout << "Pair found: (" << element << ", " << arr[j] << ")" << endl; // Print the pair if the condition is met
                }
            }
    }

    // Triplet Sum Problem
    vector<int> arr1{10, 20, 30, 40}; // Initialize another vector with some elements
    int sum1 = 80; // Initialize a variable to hold the sum of elements for triplet

    for(int i = 0; i < arr1.size(); i++) {
        int element1 = arr1[i]; // Get the current element
        for(int j = i + 1; j < arr1.size(); j++) {
            int element2 = arr1[j]; // Get the second element
            for(int k = j + 1; k < arr1.size(); k++) {
                int element3 = arr1[k]; // Get the third element
                if(element1 + element2 + element3 == sum1) {
                    cout << "Triplet found: (" << element1 << ", " << element2 << ", " << element3 << ")" << endl; // Print the triplet if the condition is met
                }
            }
        }
    }

    // Sort 0 & 1 Problem

    vector<int> arr2{0, 1, 0, 1, 1, 0, 1, 0, 1, 1}; // Initialize a vector with 0s and 1s

    int start = 0; // Initialize start index
    int end = arr2.size() - 1; // Initialize end index
    int i = 0; // Initialize index for traversing the array

    while(i != end) {
        if(arr2[i] == 0) {
            // Swap from left
            swap(arr2[start], arr2[i]); // Swap if the element is 0
            start++; // Move start index forward
            i++; // Move to the next index
        } else {
            // Swap from right
            swap(arr2[end], arr2[i]); // Swap if the element is 1
            end--; // Move end index backward
        }
    }

    // Printing the sorted array
    cout << "Sorted array of 0s and 1s: ";
    for(int i = 0; i < arr2.size(); i++) {
        cout << arr2[i] << " "; // Output each element in the sorted array
    }
}