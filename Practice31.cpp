#include <iostream>
#include <vector>
#include <set> // For using set to track unique elements
using namespace std;

// Function to find common elements in three sorted arrays
vector<int> findCommonElements(int A[], int B[], int C[], int n1, int n2, int n3) {

    vector<int> commonElements; // Vector to store common elements found
    set<int> uniqueElements; // Set to track unique elements
    int i = 0, j = 0, k = 0; // Initialize pointers for traversing arrays A, B, and C

    // Traverse all three arrays using three pointers
    while (i < n1 && j < n2 && k < n3) {

        // Case when elements at all three pointers are equal
        if (A[i] == B[j] && B[j] == C[k]) {

            uniqueElements.insert(A[i]); // Insert into set to ensure uniqueness

            // Move all pointers ahead since we found a common match
            i++;
            j++;
            k++;
        }

        // If current element of A is smallest, move pointer i
        else if (A[i] < B[j]) {
            i++;
        }

        // If current element of B is smallest, move pointer j
        else if (B[j] < C[k]) {
            j++;
        }

        // If current element of C is smallest, move pointer k
        else {
            k++;
        }
    }

    for(auto elem : uniqueElements) {
        commonElements.push_back(elem); // Insert into set to ensure uniqueness
    }

    return commonElements; // Return the final list of unique elements
}

int main() {
    // Sample arrays (must be sorted for the algorithm to work)
    int A[] = {1, 2, 3, 4, 5};
    int B[] = {2, 3, 5, 6};
    int C[] = {1, 2, 3, 4};

    // Calculate the size of each array
    int n1 = sizeof(A) / sizeof(A[0]);
    int n2 = sizeof(B) / sizeof(B[0]);
    int n3 = sizeof(C) / sizeof(C[0]);

    // Call the function to get common elements
    vector<int> result = findCommonElements(A, B, C, n1, n2, n3);

    // Output the result
    cout << "Common elements: ";
    for (int elem : result) {
        cout << elem << " ";
    }
    cout << endl;

    return 0; // Indicate successful execution
}