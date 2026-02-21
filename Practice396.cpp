#include <iostream>
using namespace std;

// =====================================================
// FUNCTION: clearIthBit
// -----------------------------------------------------
// PURPOSE:
//   Clears (turns OFF) the i-th bit of number n.
//
// PARAMETER:
//   • n passed by reference → original number updated
//   • i → bit position (0-based)
//
// APPROACH:
//   mask = ~(1 << i)
//   n = n & mask
// =====================================================
void clearIthBit(int& n, int i) {

    // Create mask with i-th bit = 0
    int mask = ~(1 << i);

    // Clear i-th bit
    n = n & mask;
}

// =====================================================
// FUNCTION: updateIthBit
// -----------------------------------------------------
// PURPOSE:
//   Update i-th bit to target (0 or 1)
//
// INPUT:
//   • n → given number (by reference)
//   • i → bit position
//   • target → 0 or 1
//
// APPROACH:
//   1️⃣ Clear i-th bit
//   2️⃣ Set it according to target
//
// CASES:
//   target = 0 → bit remains cleared
//   target = 1 → bit becomes set
//
// FORMULA:
//   n = (n & ~(1 << i)) | (target << i)
//
// TIME COMPLEXITY:
//   • O(1)
// =====================================================
void updateIthBit(int& n, int i, int target) {

    // Step 1: Clear i-th bit
    clearIthBit(n, i);

    // Step 2: Set i-th bit if target = 1
    int mask = target << i;

    // Update number
    n = n | mask;

    cout << "After updating: " << n << endl;
}

// =====================================================
// MAIN FUNCTION
// =====================================================
int main() {

    cout << "Enter integer value: " << endl;

    int n;
    cin >> n;

    cout << "Enter value of i for bit position: " << endl;

    int i;
    cin >> i;

    cout << "Targeting the value (0 or 1): " << endl;

    int target;
    cin >> target;

    updateIthBit(n, i, target);

    return 0;
}