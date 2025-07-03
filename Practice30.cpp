#include <iostream>
#include <vector>
using namespace std;

// Function to find common elements in three sorted arrays
vector<int> findCommonElements(int A[], int B[], int C[], int n1, int n2, int n3) {
    vector<int> commonElements; // Vector to store common elements

    int i = 0, j = 0, k = 0; // Initialize pointers for A, B, and C

    // Traverse all three arrays
    while (i < n1 && j < n2 && k < n3) {
        // If all three elements are equal, add to result
        if (A[i] == B[j] && B[j] == C[k]) {
            // Avoid duplicates in result
            if (commonElements.empty() || commonElements.back() != A[i]) {
                commonElements.push_back(A[i]);
            }
            i++;
            j++;
            k++;
        }
        // Increment pointer for the smallest element
        else if (A[i] < B[j]) {
            i++;
        } else if (B[j] < C[k]) {
            j++;
        } else {
            k++;
        }
    }

    return commonElements; // Return the list of common elements
}

int main() {
    // Sample arrays
    int A[] = {1, 2, 3, 4, 5};
    int B[] = {2, 3, 5, 6};
    int C[] = {1, 2, 3, 4};

    // Get the sizes of the arrays
    int n1 = sizeof(A) / sizeof(A[0]);
    int n2 = sizeof(B) / sizeof(B[0]);
    int n3 = sizeof(C) / sizeof(C[0]);

    // Call the function
    vector<int> result = findCommonElements(A, B, C, n1, n2, n3);

    // Output the result
    if (!result.empty()) {
        cout << "Common elements are: ";
        for (int val : result) {
            cout << val << " ";
        }
        cout << endl;
    } else {
        cout << "No common elements found." << endl;
    }

    return 0; // Successful execution
}
