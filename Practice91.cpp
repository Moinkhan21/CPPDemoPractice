#include <iostream>
using namespace std;

/*
    Function: PowMod
    Purpose:  Computes (x^n) % M efficiently using Binary Exponentiation.
    Parameters:
        - x : the base number
        - n : the exponent (power)
        - M : the modulus value
    Returns:
        - (x^n) % M
*/
long long int PowMod(long long int x, long long int n, long long int M) {
    long long int ans = 1; // Initialize result as 1 (multiplicative identity)

    // Loop until exponent becomes 0
    while (n > 0) {

        // Step 1: If n is odd, multiply the current result with x
        // (n & 1) checks the least significant bit of n.
        if (n & 1) {
            ans = (ans * x) % M; // Keep result modulo M to avoid overflow
        }

        // Step 2: Square the base for the next bit in exponent
        x = (x * x) % M;

        // Step 3: Right shift n by 1 (equivalent to dividing n by 2)
        n >>= 1;
    }

    // Return the final result modulo M
    return ans % M;
}

int main() {
    /*
        Example:
        Compute (5^4) % 10

        Step by step:
        5^4 = 625
        625 % 10 = 5
    */
    cout << PowMod(5, 4, 10) << endl; // Output: 5

    return 0;
}
