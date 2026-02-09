#include <iostream>
using namespace std;

// =====================================================
// Space Optimized Fibonacci
// =====================================================
int spaceOptSolve(int n) {

    // Base cases
    int prev2 = 0;
    if (n == 0)
        return prev2;

    int prev1 = 1;
    if (n == 1)
        return prev1;

    int curr = 0;

    // Iterative approach
    for (int i = 2; i <= n; i++) {
        curr = prev1 + prev2;

        // Shift values
        prev2 = prev1;
        prev1 = curr;
    }

    return curr;
}

// =====================================================
// Fibonacci function
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

    cout << "Fibonacci of " << n << " is: " << fib(n) << endl;

    return 0;
}
