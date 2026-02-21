#include <iostream>
using namespace std;

// =====================================================
// FUNCTION: clearIthBit
// -----------------------------------------------------
// PURPOSE:
//   Clear (turn OFF) the i-th bit of a number.
//
// INPUT:
//   • n → given number
//   • i → bit position (0-based)
//
// OUTPUT:
//   • Number after clearing i-th bit
//
// APPROACH: BIT MASKING
//
// IDEA:
//   1️⃣ Create a mask with i-th bit OFF
//        mask = ~(1 << i)
//
//   2️⃣ Perform AND operation
//        ans = n & mask
//
// WHY AND?
//   • 1 & 0 = 0 → clears bit
//   • 1 & 1 = 1 → keeps bit unchanged
//   • 0 & 0 = 0 → stays 0
//
// EXAMPLE:
//   n = 5 → 101
//   i = 2
//
//   mask = ~(1 << 2)
//        = ~(100)
//        = 011
//
//   result = 101 & 011 = 001 → 1
//
// TIME COMPLEXITY:
//   • O(1)
//
// SPACE COMPLEXITY:
//   • O(1)
// =====================================================
void clearIthBit(int n, int i) {

    // Step 1: Create mask with i-th bit OFF
    int mask = ~(1 << i);

    // Step 2: AND operation to clear bit
    int ans = n & mask;

    cout << "After clearing: " << ans << endl;
}

// =====================================================
// MAIN FUNCTION
// =====================================================
int main() {

    cout << "Enter integer value: " << endl;

    int n;
    cin >> n;

    cout << "Enter value of i for clearing bit (masking): " << endl;

    int i;
    cin >> i;

    clearIthBit(n, i);

    return 0;
}