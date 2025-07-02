#include <iostream>
#include <unordered_map> // For using hash map
using namespace std;

// ========================================================
// Function: firstRepeated
// Purpose : Find the first repeated element in an array
// Approach: 
//   1. Count occurrences of each element using unordered_map
//   2. Traverse again to return index of first element with count > 1
// Return  : 1-based index of the first repeated element
//           or -1 if no duplicate is found
// ========================================================
int firstRepeated(int *a, int n) {
    
    unordered_map<int, int> hash; // Hash map to store frequency

    // Step 1: Count frequency of each element
    for (int i = 0; i < n; i++) {
        hash[a[i]]++;
    }

    // Step 2: Find first element with frequency > 1
    for (int i = 0; i < n; i++) {
        if (hash[a[i]] > 1) {
            return i + 1; // Return 1-based index
        }
    }

    // If no repeated element is found
    return -1;
}

int main() {
    // Sample array with repeated elements
    int a[] = {1, 2, 3, 4, 2, 5};

    // Calculate the number of elements in the array
    int n = sizeof(a) / sizeof(int);

    // Call the function to find the first repeated element
    int result = firstRepeated(a, n);

    // Output the result
    if (result != -1) {
        cout << "First repeated element is at index (1-based): " << result << endl;
    } else {
        cout << "No repeated elements found." << endl;
    }

    return 0; // Indicate successful execution
}
