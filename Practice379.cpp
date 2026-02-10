#include <iostream>
#include <vector>
using namespace std;

// =====================================================
// FUNCTION: topDownSolve
// -----------------------------------------------------
// PURPOSE:
//   Computes the nth Fibonacci number using
//   Recursion + Memoization (Top-Down DP).
//
// PARAMETERS:
//   • n  → Fibonacci index to compute
//   • dp → memoization array
//
// RETURNS:
//   • Fibonacci value of n
//
// WHY MEMOIZATION?
//   • Avoids recomputation of overlapping subproblems
//   • Reduces exponential time to linear time
//
// TIME COMPLEXITY:
//   • O(N)
//
// SPACE COMPLEXITY:
//   • O(N) (dp array + recursion stack)
// =====================================================
int topDownSolve(int n, vector<int>& dp) {

    // -------------------------------------------------
    // BASE CASES
    // -------------------------------------------------
    // Fibonacci(0) = 0
    // Fibonacci(1) = 1
    if (n == 0 || n == 1) {
        return n;
    }

    // -------------------------------------------------
    // STEP 3: Memoization check
    // -------------------------------------------------
    // If value already computed, return it
    if (dp[n] != -1) {
        return dp[n];
    }

    // -------------------------------------------------
    // STEP 2: Recursive computation + store result
    // -------------------------------------------------
    dp[n] = topDownSolve(n - 1, dp)
          + topDownSolve(n - 2, dp);

    return dp[n];
}

// =====================================================
// FUNCTION: fib
// -----------------------------------------------------
// PURPOSE:
//   Wrapper function to compute Fibonacci number
//   using Top-Down DP approach.
//
// STEPS:
//   1️⃣ Create dp array initialized with -1
//   2️⃣ Call recursive memoized function
//   3️⃣ Return the computed answer
// =====================================================
int fib(int n) {

    // Step 1: Create DP array of size (n + 1)
    vector<int> dp(n + 1, -1);

    // Step 2: Call top-down DP function
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

    cout << "Fibonacci of " << n
         << " is: " << fib(n) << endl;

    return 0;
}
