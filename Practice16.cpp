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
}