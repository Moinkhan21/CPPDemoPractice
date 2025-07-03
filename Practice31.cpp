#include <iostream>
#include <vector>
#include <set> // For using set to track unique elements
using namespace std;

// Function to find common elements in three sorted arrays
vector<int> findCommonElements(int A[], int B[], int C[], int n1, int n2, int n3) {

    vector<int> commonElements;     // Vector to store final common elements
    set<int> uniqueElements;        // Set to track unique common elements (no duplicates)
    
    int i = 0, j = 0, k = 0;         // Initialize pointers for traversing A, B, and C

    // Traverse all three arrays simultaneously using three pointers
    while (i < n1 && j < n2 && k < n3) {

        // Case 1: When elements at all three pointers are equal, it's a common element
        if (A[i] == B[j] && B[j] == C[k]) {
            uniqueElements.insert(A[i]); // Insert into set to avoid duplicates
            i++; j++; k++;               // Move all pointers to the next elements
        }
        // Case 2: A[i] is the smallest among the three, so move pointer i
        else if (A[i] < B[j]) {
            i++;
        }
        // Case 3: B[j] is smaller than C[k], so move pointer j
        else if (B[j] < C[k]) {
            j++;
        }
        // Case 4: C[k] is smallest, so move pointer k
        else {
            k++;
        }
    }

    // Transfer elements from set to vector
    for (auto elem : uniqueElements) {
        commonElements.push_back(elem); // Add unique common elements to result
    }

    return commonElements; // Return the final list of unique common elements
}

int main() {
    // Sample input arrays (MUST BE SORTED for this method to work)
    int A[] = {1, 2, 3, 4, 5};
    int B[] = {2, 3, 5, 6};
    int C[] = {1, 2, 3, 4};

    // Calculate size of each array
    int n1 = sizeof(A) / sizeof(A[0]);
    int n2 = sizeof(B) / sizeof(B[0]);
    int n3 = sizeof(C) / sizeof(C[0]);

    // Call the function to find common elements
    vector<int> result = findCommonElements(A, B, C, n1, n2, n3);

    // Print the result
    cout << "Common elements: ";
    for (int elem : result) {
        cout << elem << " "; // Print each common element
    }
    cout << endl;

    return 0; // Indicate successful execution
}
