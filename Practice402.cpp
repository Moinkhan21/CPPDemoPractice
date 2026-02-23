#include <iostream>
using namespace std;

// =====================================================
// FUNCTION: clearBitsInRange
// -----------------------------------------------------
// PURPOSE:
//   Clears (sets to 0) all bits in the range from
//   index j to i (inclusive) in a given number n.
//
// NOTE:
//   • Bit indexing is from right (LSB) starting at 0
//
// EXAMPLE:
//   n = 15  -> Binary: 1111
//   i = 3, j = 0
//
//   After clearing bits from 0 to 3:
//   Result -> 0000 (0)
//
// APPROACH:
//   1️⃣ Create left mask (a)
//       → 1s before position (i+1), 0s after
//
//   2️⃣ Create right mask (b)
//       → 1s after position (j-1), 0s before
//
//   3️⃣ Combine both masks using OR
//       → Middle bits (j to i) become 0
//
//   4️⃣ AND with n to clear required bits
//
// HOW MASK WORKS:
//
//   a = (-1 << (i + 1))
//       Example: i = 3
//       -1 = 11111111
//       a  = 11110000
//
//   b = (1 << j) - 1
//       Example: j = 0
//       1 << 0 = 0001
//       b = 0000
//
//   mask = a | b
//        = 11110000
//
//   n = 1111
//   result = 1111 & 11110000 = 0000
//
// TIME COMPLEXITY:
//   • O(1)
//
// SPACE COMPLEXITY:
//   • O(1)
// =====================================================
void clearBitsInRange(int n, int i, int j) {

    // -------------------------------------------------
    // STEP 1: Create left mask
    // -------------------------------------------------
    // 1s from MSB to (i+1), 0s from i to 0
    int a = (-1 << (i + 1));

    // -------------------------------------------------
    // STEP 2: Create right mask
    // -------------------------------------------------
    // 1s from (j-1) to 0, 0s above
    int b = (1 << j) - 1;

    // -------------------------------------------------
    // STEP 3: Combine both masks
    // -------------------------------------------------
    // Middle bits (j to i) become 0
    int mask = a | b;

    // -------------------------------------------------
    // STEP 4: Clear bits in range using AND
    // -------------------------------------------------
    n = n & mask;

    // Output result
    cout << "After clearing in range: " << n << endl; 
}

// =====================================================
// MAIN FUNCTION
// -----------------------------------------------------
// PURPOSE:
//   Entry point of program
//
// WORKING:
//   • Calls clearBitsInRange()
//   • Clears bits from j to i
// =====================================================
int main() {

    // Example:
    // n = 15 (1111), clear bits from 0 to 3
    clearBitsInRange(15, 3, 0);

    return 0;
}