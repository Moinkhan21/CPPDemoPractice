#include <iostream>
using namespace std;

/*
    Function: fastExponentiation
    Purpose:  Computes a^b (a raised to the power b) in O(log b) time 
              using the "Exponentiation by Squaring" technique.
    Parameters:
        - a: base (integer)
        - b: exponent (integer, non-negative)
    Returns: a^b (integer)
*/
int fastExponentiation(int a, int b) {
    int ans = 1;   // Initialize result as 1 (multiplicative identity)

    // Loop until the exponent becomes 0
    while (b > 0) {
        // Check if the current exponent bit is 1 (i.e., b is odd)
        if (b & 1) {
            // Multiply the current result by base 'a'
            ans = ans * a;
        }

        // Square the base for the next step
        a = a * a;

        // Divide the exponent by 2 (right shift = efficient division by 2)
        b >>= 1;   // Equivalent to b = b / 2
    }

    // Return the final computed result
    return ans;
} 
// Time Complexity: O(log b) → because the exponent is halved at each step
// Space Complexity: O(1) → constant extra space


/*
    Function: slowExponentiation
    Purpose:  Computes a^b (a raised to the power b) in O(b) time
              using simple repeated multiplication.
    Parameters:
        - a: base (integer)
        - b: exponent (integer, non-negative)
    Returns: a^b (integer)
*/
int slowExponentiation(int a, int b) {
    int ans = 1;   // Initialize result as 1

    // Multiply 'a' with itself 'b' times
    for (int i = 0; i < b; ++i) {
        ans *= a;
    }

    return ans;  // Return the computed result
} 
// Time Complexity: O(b) → because it performs b multiplications
// Space Complexity: O(1) → constant extra space


int main() {
    // Testing both methods with example: 5^4 = 625
    cout << slowExponentiation(5, 4) << endl; // Outputs: 625
    cout << fastExponentiation(5, 4) << endl; // Outputs: 625
    return 0;
}
