#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Recursive helper function to generate and count all valid arrangements
// v       → array representing the current arrangement (1-indexed)
// n       → total numbers to arrange
// ans     → counter for total valid arrangements
// currNum → current number we are trying to place in the arrangement
void coutArrangementHelper(vector<int> &v, int &n, int &ans, int currNum) {
    // --- Base Case ---
    // If we have placed numbers from 1 to n successfully
    if (currNum == n + 1) {
        // Print the valid arrangement
        for (int i = 1; i <= n; i++) {
            cout << v[i] << " ";
        }
        cout << endl;

        // Count this valid arrangement
        ans++;
        return;
    }

    // Try placing currNum at every possible index from 1 to n
    for (int i = 1; i <= n; ++i) {
        // Check if position i is empty (v[i] == 0)
        // AND if it satisfies the divisibility rule:
        //    Rule: either currNum % i == 0 OR i % currNum == 0
        if (v[i] == 0 && (currNum % i == 0 || i % currNum == 0)) {
            // Place currNum at position i
            v[i] = currNum;

            // Recurse for the next number
            coutArrangementHelper(v, n, ans, currNum + 1);

            // Backtrack: remove currNum and make position empty again
            v[i] = 0;
        }
    }
}

// Main function to count total beautiful arrangements for given n
int countArrangement(int n) {
    // Initialize vector with size (n+1) because we are using 1-based indexing
    vector<int> v(n + 1, 0);

    int ans = 0; // Counter for valid arrangements
    coutArrangementHelper(v, n, ans, 1); // Start placing from number 1
    return ans;
}

int main() {
    int n = 3; // You can change this value to test with different n

    // Count and display total number of valid arrangements
    int result = countArrangement(n);
    cout << "Total arrangements for n = " << n << ": " << result << endl;

    return 0;
}
