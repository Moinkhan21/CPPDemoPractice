#include <iostream>
using namespace std;

// =====================================================
// PROGRAM: Check Even or Odd using Bit Manipulation
// -----------------------------------------------------
// PURPOSE:
//   Determines whether a given number is EVEN or ODD
//   using bitwise operation.
//
// WHAT IS EVEN / ODD?
//   • EVEN → Last bit is 0
//   • ODD  → Last bit is 1
//
// EXAMPLES:
//   4  -> 100  → EVEN
//   5  -> 101  → ODD
//
// APPROACH:
//   1️⃣ Check the last bit using (n & 1)
//   2️⃣ If result is 1 → number is ODD
//   3️⃣ If result is 0 → number is EVEN
//
// WHY THIS WORKS:
//   • Binary numbers:
//       EVEN → last bit = 0
//       ODD  → last bit = 1
//
//   • (n & 1) extracts the last bit
//
// TIME COMPLEXITY:
//   • O(1)
//
// SPACE COMPLEXITY:
//   • O(1)
// =====================================================
int main() {

    // -------------------------------------------------
    // INPUT: Take integer value from user
    // -------------------------------------------------
    cout << "Enter integer the value: " << endl;
    int n;
    cin >> n;

    // -------------------------------------------------
    // CHECK: Even or Odd using bitwise AND
    // -------------------------------------------------
    if (n & 1) {
        // If last bit is 1 → ODD
        cout << n << " is odd" << endl;
    }
    else {
        // If last bit is 0 → EVEN
        cout << n << " is even" << endl;
    }

    return 0;
}