#include <iostream>
#include <vector>
using namespace std;

// Function to find common elements in three sorted arrays
vector<int> findCommonElements(int A[], int B[], int C[], int n1, int n2, int n3) {
    vector<int> commonElements; // Vector to store common elements found

    int i = 0, j = 0, k = 0; // Initialize pointers for traversing arrays A, B, and C

    // Traverse all three arrays using three pointers
    while (i < n1 && j < n2 && k < n3) {

        // Case when elements at all three pointers are equal
        if (A[i] == B[j] && B[j] == C[k]) {

            // To avoid adding duplicate values in result
            if (commonElements.empty() || commonElements.back() != A[i]) {
                commonElements.push_back(A[i]); // Add to result if not already added
            }

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

    return commonElements; // Return the final list of common elements
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
    if (!result.empty()) {
        cout << "Common elements are: ";
        for (int val : result) {
            cout << val << " "; // Print each common element
        }
        cout << endl;
    } else {
        cout << "No common elements found." << endl;
    }

    return 0; // Program executed successfully
}
