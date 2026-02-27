#include <iostream>
using namespace std;

// =====================================================
// FUNCTION: clearLastBits
// -----------------------------------------------------
// PURPOSE:
//   Clears (sets to 0) the last 'i' bits of a number n.
//
// EXAMPLE:
//   n = 7  -> Binary: 111
//   i = 2
//
//   After clearing last 2 bits:
//   Result -> 100 (which is 4)
//
// APPROACH:
//   1️⃣ Create a mask with 0s in last i positions
//      and 1s in remaining positions
//
//   2️⃣ Perform bitwise AND with n
//      → This will clear last i bits
//
// HOW MASK WORKS:
//   -1 in binary = all bits are 1 (two's complement)
//
//   Example:
//     -1       = 11111111
//     -1 << i  = 11111100   (last i bits become 0)
//
//   When we do:
//     n & mask
//
//   → last i bits become 0
//
// TIME COMPLEXITY:
//   • O(1)
//
// SPACE COMPLEXITY:
//   • O(1)
// =====================================================
void clearLastBits(int n, int i) {

    // -------------------------------------------------
    // STEP 1: Create mask
    // -------------------------------------------------
    // -1 has all bits set to 1
    // Left shift by i → last i bits become 0
    int mask = (-1 << i);

    // -------------------------------------------------
    // STEP 2: Clear last i bits using AND operation
    // -------------------------------------------------
    // AND with mask will turn last i bits to 0
    n = n & mask;

    // -------------------------------------------------
    // STEP 3: Print result
    // -------------------------------------------------
    cout << "After clearing last i bits: " << n << endl;
}

// =====================================================
// MAIN FUNCTION
// -----------------------------------------------------
// PURPOSE:
//   Entry point of program
//
// WORKING:
//   • Initializes a number
//   • Calls function to clear last i bits
// =====================================================
int main() {

    // Input number
    int n = 7;  // Binary: 111

    // Number of bits to clear
    int i = 2;

    // Function call
    clearLastBits(n, i);

    return 0;
}