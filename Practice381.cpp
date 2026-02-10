#include <iostream>
using namespace std;

// =====================================================
// FUNCTION: spaceOptSolve
// -----------------------------------------------------
// PURPOSE:
//   Computes the nth Fibonacci number using
//   Space-Optimized Dynamic Programming.
//
// KEY IDEA:
//   • Fibonacci depends only on last two values
//   • No need to store entire dp array
//
// VARIABLES:
//   • prev2 → Fibonacci(i-2)
//   • prev1 → Fibonacci(i-1)
//   • curr  → Fibonacci(i)
//
// TIME COMPLEXITY:
//   • O(N)
//
// SPACE COMPLEXITY:
//   • O(1)
// =====================================================
int spaceOptSolve(int n) {

    // -------------------------------------------------
    // BASE CASES
    // -------------------------------------------------
    int prev2 = 0;          // Fib(0)
    if (n == 0)
        return prev2;

    int prev1 = 1;          // Fib(1)
    if (n == 1)
        return prev1;

    int curr = 0;

    // -------------------------------------------------
    // ITERATIVE COMPUTATION
    // -------------------------------------------------
    for (int i = 2; i <= n; i++) {

        // Current Fibonacci value
        curr = prev1 + prev2;

        // Shift window forward
        prev2 = prev1;
        prev1 = curr;
    }

    return curr;
}

// =====================================================
// FUNCTION: fib
// -----------------------------------------------------
// PURPOSE:
//   Wrapper function for Fibonacci calculation
//   using space-optimized DP.
// =====================================================
int fib(int n) {
    return spaceOptSolve(n);
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
