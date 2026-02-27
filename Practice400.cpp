#include <iostream>
using namespace std;

// =====================================================
// FUNCTION: countSetBits
// -----------------------------------------------------
// PURPOSE:
//   Counts the number of set bits (1s) in the binary
//   representation of a given number 'n'.
//
// WHAT ARE SET BITS?
//   Bits which are equal to 1 in binary form.
//
//   Example:
//       n = 5  -> Binary: 101 → Set bits = 2
//       n = 15 -> Binary: 1111 → Set bits = 4
//
// APPROACH (BIT BY BIT CHECK):
//   1️⃣ Extract the last bit using (n & 1)
//   2️⃣ If last bit is 1 → increment count
//   3️⃣ Right shift n to process next bit
//   4️⃣ Repeat until n becomes 0
//
// HOW IT WORKS:
//   • (n & 1) gives the last bit (LSB)
//   • Right shift (n >> 1) removes last bit
//
// TIME COMPLEXITY:
//   • O(log n) → Number of bits in n
//
// SPACE COMPLEXITY:
//   • O(1)
// =====================================================
int countSetBits(int n) {

    int count = 0;   // Stores number of set bits

    // -------------------------------------------------
    // LOOP: Process each bit until n becomes 0
    // -------------------------------------------------
    while (n != 0) {

        // -------------------------------------------------
        // STEP 1: Extract last bit
        // -------------------------------------------------
        int lastBit = n & 1;

        // -------------------------------------------------
        // STEP 2: If last bit is 1 → increment count
        // -------------------------------------------------
        if (lastBit)
            count++;

        // -------------------------------------------------
        // STEP 3: Right shift n by 1
        // Moves to next bit
        // -------------------------------------------------
        n = n >> 1;
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
//   • Calls countSetBits()
//   • Prints result
// =====================================================
int main() {

    // Test value
    int n = 15;   // Binary: 1111

    // Function call and output
    cout << "Number of set bits: " << countSetBits(n) << endl;

    return 0;
}