#include <iostream>
#include <vector>
using namespace std;

// =====================================================
// FUNCTION: BottomUpSolve
// -----------------------------------------------------
// PURPOSE:
//   Computes the nth Fibonacci number using
//   Bottom-Up Dynamic Programming (Tabulation).
//
// APPROACH:
//   • Solve smaller subproblems first
//   • Build the answer iteratively from 0 → n
//
// WHY BOTTOM-UP?
//   • No recursion overhead
//   • Avoids stack usage
//   • Easier to visualize DP table
//
// TIME COMPLEXITY:
//   • O(N)
//
// SPACE COMPLEXITY:
//   • O(N)
// =====================================================
int BottomUpSolve(int n) {

    // -------------------------------------------------
    // STEP 1: Create DP array of size (n + 1)
    // -------------------------------------------------
    vector<int> dp(n + 1, -1);

    // -------------------------------------------------
    // STEP 2: Base cases
    // -------------------------------------------------
    dp[0] = 0;
    if (n == 0)
        return dp[0];

    dp[1] = 1;
    if (n == 1)
        return dp[1];

    // -------------------------------------------------
    // STEP 3: Fill DP table iteratively
    // -------------------------------------------------
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    // Final answer
    return dp[n];
}

// =====================================================
// FUNCTION: fib
// -----------------------------------------------------
// PURPOSE:
//   Wrapper function for Fibonacci calculation
//   using Bottom-Up DP.
// =====================================================
int fib(int n) {

    int ans = BottomUpSolve(n);
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
