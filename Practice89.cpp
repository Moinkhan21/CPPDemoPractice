#include <iostream>
using namespace std;

// ======================================================================
// FUNCTION: gcd()
// ----------------------------------------------------------------------
// PURPOSE:
//   Computes GCD (Greatest Common Divisor) of two numbers
//   using Euclidean Algorithm (Subtraction Method).
//
// GCD DEFINITION:
//   The largest number that divides both A and B.
//
// EXAMPLE:
//   gcd(8, 12) = 4
//
// APPROACH (Subtraction Method):
//   • Repeatedly subtract smaller number from larger
//   • Until one becomes 0
//   • The other number is the GCD
//
// TIME COMPLEXITY: O(max(A, B))  (slow)
// ======================================================================
int gcd(int A, int B) {

    // --------------------------------------------------
    // Base cases
    // --------------------------------------------------
    if (A == 0) return B;
    if (B == 0) return A;

    // --------------------------------------------------
    // Subtraction method
    // --------------------------------------------------
    while (A > 0 && B > 0) {

        if (A > B) {
            A = A - B;
        }
        else {
            B = B - A;
        }
    }

    // One becomes zero → return the other
    return (A == 0) ? B : A;
}

// ======================================================================
// MAIN FUNCTION
// ======================================================================
int main() {

    int A, B;

    cout << "Enter A: ";
    cin >> A;

    cout << "Enter B: ";
    cin >> B;

    int ans = gcd(A, B);

    cout << "GCD of A and B is: " << ans << endl;

    return 0;
}