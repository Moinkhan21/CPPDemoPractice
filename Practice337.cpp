#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// ===============================
// Helper Function
// ===============================
void build(int &i, int min, int max, vector<int> &A) {
    if (i >= A.size()) {
        return;
    }

    if (A[i] > min && A[i] < max) {
        int rootData = A[i++];
        build(i, min, rootData, A);
        build(i, rootData, max, A);
    }
}

// ===============================
// Solve Function
// ===============================
int solve(vector<int> &A) {
    int min = INT_MIN, max = INT_MAX;
    int i = 0;
    build(i, min, max, A);
    return i = A.size();   // LOGIC KEPT UNCHANGED
}

// ===============================
// MAIN (Test Case)
// ===============================
int main() {

    /*
        Valid BST Preorder:
        [10, 5, 1, 7, 40, 50]
    */

    vector<int> A = {10, 5, 1, 7, 40, 50};

    int result = solve(A);

    cout << "Result = " << result << endl;

    return 0;
}
