#include <iostream>
#include <vector>
using namespace std;

// =====================================================
// Recursion + Memoisation (Top-Down DP)
// =====================================================
int topDownSolve(int n, vector<int>& dp) {
    // Base case
    if (n == 0 || n == 1) {
        return n;
    }

    // Step 3: If already computed, return stored value
    if (dp[n] != -1) {
        return dp[n];
    }

    // Step 2: Store the computed answer in dp array
    dp[n] = topDownSolve(n - 1, dp) + topDownSolve(n - 2, dp);
    return dp[n];
}

// =====================================================
// Fibonacci function
// =====================================================
int fib(int n) {
    // Step 1: Create dp array
    vector<int> dp(n + 1, -1);

    // Call recursive memoized function
    int ans = topDownSolve(n, dp);
    return ans;
}

// =====================================================
// MAIN FUNCTION
// =====================================================
int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    cout << "Fibonacci of " << n << " is: " << fib(n) << endl;

    return 0;
}
