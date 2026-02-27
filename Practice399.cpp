#include <iostream>
using namespace std;

// =====================================================
// FUNCTION: checkPowerOf2
// -----------------------------------------------------
// PURPOSE:
//   Checks whether a given number 'n' is a power of 2.
//
// WHAT IS A POWER OF 2?
//   A number that can be written as:
//
//       n = 2^k  (k >= 0)
//
//   Examples:
//       1  -> 2^0
//       2  -> 2^1
//       4  -> 2^2
//       8  -> 2^3
//       16 -> 2^4
//
// KEY OBSERVATION:
//   A power of 2 has exactly ONE set bit in binary.
//
//   Examples:
//       1  -> 0001
//       2  -> 0010
//       4  -> 0100
//       8  -> 1000
//
// IMPORTANT TRICK:
//   For any power of 2:
//
//       n & (n - 1) == 0
//
// WHY THIS WORKS:
//   • n has only one set bit
//   • (n - 1) flips that bit and all lower bits
//   • AND operation removes the only set bit → result becomes 0
//
// EXAMPLE:
//   n = 16 -> 10000
//   n-1 = 15 -> 01111
//   AND = 00000 → Power of 2
//
// EDGE CASE:
//   n = 0 → Not a power of 2
//   (0 & -1 = 0, but 0 is not valid)
//
// TIME COMPLEXITY:
//   • O(1)
//
// SPACE COMPLEXITY:
//   • O(1)
// =====================================================
bool checkPowerOf2(int n) {

    // -------------------------------------------------
    // EDGE CASE: 0 is not a power of 2
    // -------------------------------------------------
    if (n == 0)
        return false;

    // -------------------------------------------------
    // MAIN LOGIC:
    // Check if only one bit is set
    // -------------------------------------------------
    if ((n & (n - 1)) == 0)
        return true;
    else
        return false;
}

// =====================================================
// MAIN FUNCTION
// -----------------------------------------------------
// PURPOSE:
//   Entry point of program
//
// WORKING:
//   • Calls checkPowerOf2()
//   • Prints result (1 = true, 0 = false)
// =====================================================
int main() {

    // Test value
    int n = 16;

    // Function call and output
    cout << "Power of 2 ans: " << checkPowerOf2(n) << endl;

    return 0;
}