#include <iostream>
#include <unordered_map>
using namespace std;

int firstRepeated(int *a, int n) {
    
    unordered_map<int, int>hash;
    for(int i = 0; i < n; i++) {
        hash[a[i]]++; // Count occurrences of each element
    }
    for(int i = 0; i < n; i++) {
        if(hash[a[i]] > 1) {
            return i + 1; // Return the 1-based index of the first repeated element
        }
    }
    return -1; // Return -1 if no repeated element is found
}

int main() {
    // Sample array with repeated elements
    int a[] = {1, 2, 3, 4, 2, 5};

    // Calculate the size of the array
    int n = sizeof(a) / sizeof(int);

    // Call function to find the first repeated element
    int result = firstRepeated(a, n);

    if (result != -1) {
        cout << "First repeated element is at index: " << result << endl;
    } else {
        cout << "No repeated elements found." << endl;
    }

    return 0; // Successful execution
}