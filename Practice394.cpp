#include <iostream>
using namespace std;

// =====================================================
// FUNCTION: setIthBit
// -----------------------------------------------------
// PURPOSE:
//   Sets (makes 1) the ith bit of a given number n.
//
// WHAT DOES "SET BIT" MEAN?
//   • Convert the ith bit to 1
//   • If already 1 → remains 1
//
// EXAMPLE:
//   n = 5  -> Binary: 0101
//   i = 1
//
//   After setting ith bit:
//   Result -> 0111 (which is 7)
//
// APPROACH:
//   1️⃣ Create a mask with only ith bit set
//       mask = (1 << i)
//
//   2️⃣ Perform bitwise OR with n
//       → OR operation sets the ith bit to 1
//
// HOW IT WORKS:
//   mask = 1 << i
//
//   Example:
//     i = 2
//     mask = 0100
//
//   Now:
//     n   = 0011
//     mask= 0100
//     OR  = 0111
//
//   → ith bit becomes 1
//
// TIME COMPLEXITY:
//   • O(1)
//
// SPACE COMPLEXITY:
//   • O(1)
// =====================================================
void setIthBit(int n, int i) {

    // -------------------------------------------------
    // STEP 1: Create mask
    // -------------------------------------------------
    // Shift 1 to ith position
    int mask = 1 << i;

    // -------------------------------------------------
    // STEP 2: Set ith bit using OR operation
    // -------------------------------------------------
    int ans = n | mask;

    // -------------------------------------------------
    // STEP 3: Print result
    // -------------------------------------------------
    cout << "After setting: " << ans << endl;
}

// =====================================================
// MAIN FUNCTION
// -----------------------------------------------------
// PURPOSE:
//   Entry point of program
//
// WORKING:
//   • Takes input from user
//   • Calls setIthBit()
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
    cout << "Enter value of i for setting bit (masking): " << endl;
    int i;
    cin >> i;
 
    // Function call
    setIthBit(n, i);

    return 0;
}