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
}