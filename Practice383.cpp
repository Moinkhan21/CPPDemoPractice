#include <iostream>
#include <algorithm>
using namespace std;

// =====================================================
// PROGRAM: Minimum Amount to Pay (Buy 1 Get 1 Free)
// -----------------------------------------------------
// PROBLEM:
//   Given prices of items,
//   For every item you buy, you can get one item FREE
//   (the free item must be of equal or lesser price).
//
//   Find the minimum total amount to pay.
//
// EXAMPLE:
//   prices = {2, 8, 6, 9, 4, 7}
//
// APPROACH (GREEDY):
//   1️⃣ Sort the prices in ascending order
//   2️⃣ Buy the cheapest available item
//   3️⃣ Get the most expensive available item FREE
//   4️⃣ Repeat until all items are processed
//
// WHY THIS WORKS?
//   • To minimize cost, we should pay for cheaper items
//   • Use expensive items as FREE items
//
// TIME COMPLEXITY:
//   • O(n log n) → due to sorting
//
// SPACE COMPLEXITY:
//   • O(1)
// =====================================================
int main() {

    // -------------------------------------------------
    // INPUT: Prices of items
    // -------------------------------------------------
    int prices[] = {2, 8, 6, 9, 4, 7};
    int n = 6;

    // -------------------------------------------------
    // STEP 1: Sort prices in ascending order
    // -------------------------------------------------
    sort(prices, prices + n);

    int amount = 0;   // Stores minimum total amount
    int buy = 0;      // Pointer for items we pay for
    int free = n - 1; // Pointer for items we get free

    // -------------------------------------------------
    // STEP 2: Process items
    // -------------------------------------------------
    while (buy <= free) {

        // Pay for cheapest item
        amount += prices[buy];
        buy++;

        // Skip the most expensive item (FREE)
        free--;

        // Since Buy 1 Get 1 Free,
        // reduce one more from free side
        free--;
    }

    // -------------------------------------------------
    // OUTPUT: Minimum amount to pay
    // -------------------------------------------------
    cout << "Answer is " << amount << endl;

    return 0;
}