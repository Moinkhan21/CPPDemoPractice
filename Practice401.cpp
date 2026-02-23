#include <iostream>
using namespace std;

// =====================================================
// FUNCTION: countSetBitsFast
// -----------------------------------------------------
// PURPOSE:
//   Counts the number of set bits (1s) in the binary
//   representation of a number using an optimized method.
//
// APPROACH (BRIAN KERNIGHAN’S ALGORITHM):
//   Instead of checking every bit,
//   we directly remove the lowest set bit in each step.
//
// KEY IDEA:
//   n & (n - 1) removes the last (rightmost) set bit.
//
// WHY THIS WORKS:
//   • Subtracting 1 flips all bits after the last set bit
//   • AND operation removes that last set bit
//
// EXAMPLE:
//   n = 12 -> 1100
//
//   Step 1:
//     n = 1100
//     n-1 = 1011
//     AND = 1000
//
//   Step 2:
//     n = 1000
//     n-1 = 0111
//     AND = 0000
//
//   Count = 2 (two set bits)
//
// TIME COMPLEXITY:
//   • O(number of set bits)
//   • Faster than O(log n) approach
//
// SPACE COMPLEXITY:
//   • O(1)
// =====================================================
int countSetBitsFast(int n) {

    int count = 0;   // Stores number of set bits

    // -------------------------------------------------
    // LOOP: Runs until all set bits are removed
    // -------------------------------------------------
    while (n != 0) {

        // -------------------------------------------------
        // STEP: Remove the last (rightmost) set bit
        // -------------------------------------------------
        // This operation reduces one set bit in each iteration
        n = (n & (n - 1));

        // Increment count for each removed set bit
        count++;
    }

    // Return total number of set bits
    return count;
}

// =====================================================
// MAIN FUNCTION
// -----------------------------------------------------
// PURPOSE:
//   Entry point of program
//
// WORKING:
//   • Calls optimized set bit function
//   • Prints result
// =====================================================
int main() {

    // Test value
    int n = 15;   // Binary: 1111

    // Function call and output
    cout << "Number of set bits: " << countSetBitsFast(n) << endl;

    return 0;
}