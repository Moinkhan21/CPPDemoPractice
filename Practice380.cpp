#include <iostream>
#include <vector>
using namespace std;

// =====================================================
// Bottom-Up Dynamic Programming (Tabulation)
// =====================================================
int BottomUpSolve(int n) {

    // Step 1: Create dp array
    vector<int> dp(n + 1, -1);

    // Step 2: Base cases
    dp[0] = 0;
    if (n == 0)
        return dp[0];

    dp[1] = 1;
    if (n == 1)
        return dp[1];

    // Step 3: Iterative approach
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}

// =====================================================
// Fibonacci function
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

    cout << "Fibonacci of " << n << " is: " << fib(n) << endl;

    return 0;
}
