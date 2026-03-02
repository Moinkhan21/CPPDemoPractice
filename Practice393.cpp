#include <iostream>
using namespace std;

// =====================================================
// FUNCTION: getIthBit
// -----------------------------------------------------
// PURPOSE:
//   Returns the value (0 or 1) of the ith bit
//   in a given number n.
//
// WHAT DOES "GET ITH BIT" MEAN?
//   • Check whether the ith bit is 0 or 1
//   • Bit indexing starts from right (LSB = 0)
//
// EXAMPLE:
//   n = 5  -> Binary: 0101
//
//   i = 0 → 1
//   i = 1 → 0
//   i = 2 → 1
//
// APPROACH:
//   1️⃣ Create a mask with only ith bit set:
//       mask = (1 << i)
//
//   2️⃣ Perform AND operation:
//       ans = n & mask
//
//   3️⃣ If result is 0 → bit is 0
//      Else → bit is 1
//
// HOW IT WORKS:
//
//   Example:
//     n = 5 → 0101
//     i = 2
//
//     mask = 0100
//     AND  = 0101 & 0100 = 0100 (non-zero)
//
//     → Bit is 1
//
// TIME COMPLEXITY:
//   • O(1)
//
// SPACE COMPLEXITY:
//   • O(1)
// =====================================================
int getIthBit(int n, int i) {

    // -------------------------------------------------
    // STEP 1: Create mask
    // -------------------------------------------------
    int mask = 1 << i;

    // -------------------------------------------------
    // STEP 2: Perform AND operation
    // -------------------------------------------------
    int ans = n & mask;

    // -------------------------------------------------
    // STEP 3: Check result
    // -------------------------------------------------
    if (ans == 0)
        return 0;   // ith bit is 0
    else
        return 1;   // ith bit is 1
}

// =====================================================
// MAIN FUNCTION
// -----------------------------------------------------
// PURPOSE:
//   Entry point of program
//
// WORKING:
//   • Takes input from user
//   • Calls getIthBit()
//   • Prints result
// =====================================================
int main() {

    // -------------------------------------------------
    // INPUT: Number
    // -------------------------------------------------
    cout << "Enter integer value: " << endl;
    int n;
    cin >> n;

    // -------------------------------------------------
    // INPUT: Bit position
    // -------------------------------------------------
    cout << "Enter value of i for bit masking: " << endl;
    int i;
    cin >> i;
 
    // Function call
    int ans = getIthBit(n, i);

    // Output result
    cout << "After performing operation of bit masking the answer is: " << endl;
    cout << ans << endl;

    return 0;
}