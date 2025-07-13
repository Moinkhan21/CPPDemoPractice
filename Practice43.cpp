#include <iostream>
#include <vector>
using namespace std;

// =====================================================
// Function: solve
// Purpose : To perform integer division without using
//           division (/) operator. Handles both positive
//           and negative values correctly.
// Logic   : Uses binary search to find the quotient.
// =====================================================
int solve(int dividend, int divisor) {
    int s = 0;                      // Start of search space
    int e = abs(dividend);         // End of search space: absolute of dividend
    int ans = 1;                   // Variable to store the answer (quotient)

    int mid = s + (e - s) / 2;     // Midpoint to avoid overflow

    // Binary search to find the maximum mid such that mid * divisor <= dividend
    while (s <= e) {
        // Case 1: Perfect match found
        if (abs(mid * divisor) == abs(dividend)) {
            ans = mid;             // Update answer
            return ((divisor < 0 && dividend < 0) || (divisor > 0 && dividend > 0)) ? ans : -ans;
        }

        // Case 2: Product is too large → move to left half
        if (abs(mid * divisor) > abs(dividend)) {
            e = mid - 1;
        }
        // Case 3: Product is less → try larger value, store current mid as potential answer
        else {
            ans = mid;
            s = mid + 1;
        }

        mid = s + (e - s) / 2;     // Update mid after adjusting search space
    }

    // Determine sign of result:
    // If dividend and divisor have same sign → result is positive
    // Otherwise, result is negative
    if ((divisor < 0 && dividend < 0) || (divisor > 0 && dividend > 0)) {
        return ans;
    } else {
        return -ans;
    }
}

// =====================================================
// Main function: Entry point of the program
// =====================================================
int main() {
    int dividend = 22;
    int divisor = -7;

    // Call the solve function to compute integer division
    int ans = solve(dividend, divisor);

    // Output the result
    cout << "Ans is " << ans << endl; // Should print -3

    return 0; // Successful execution
}
