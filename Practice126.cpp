#include <iostream>
#include <climits>   // For INT_MAX (to initialize min comparisons)
#include <cmath>     // For sqrt function
using namespace std;

// Recursive helper function to find the minimum number of perfect squares that sum to 'n'
int numSquareHelper(int n) {
    // --- Base cases ---
    if(n == 0) return 1; // If n becomes 0, it means no more squares are needed → return 1 (we subtract later in wrapper)
    if(n < 0) return 0;  // If n becomes negative, this is an invalid case → return 0

    // Initialize the minimum count as infinity (INT_MAX)
    int ans = INT_MAX;

    // Try all perfect squares less than or equal to n
    int i = 1;
    int end = sqrt(n); // Only need to check perfect squares up to sqrt(n)
    while(i <= end) {
        int perfectSquare = i * i; // Current perfect square to try

        // Recursive call: choose this perfect square and reduce n
        // Add 1 to count the current square
        int numberOfPerfectSquares = 1 + numSquareHelper(n - perfectSquare);

        // Update ans if we found a smaller count
        if(numberOfPerfectSquares < ans) {
            ans = numberOfPerfectSquares;
        }
        ++i; // Try next perfect square
    }

    // Return the minimum number of perfect squares needed for n
    return ans;
}

// Wrapper function for clean interface
int numSquares(int n) {
    // Subtract 1 to adjust for the "extra 1" returned when n == 0 in base case
    return numSquareHelper(n) - 1;
}

int main() {
    int n;

    // Input number from user
    cout << "Enter a number: ";
    cin >> n;

    // Output the minimum number of perfect squares
    cout << "Minimum number of perfect squares: " << numSquares(n) << endl;
    return 0;
}
