#include <iostream>
#include <unordered_map>
using namespace std;

// =====================================================
// FUNCTION: findPairs
// -----------------------------------------------------
// PURPOSE:
//   Checks whether there exist TWO DIFFERENT pairs
//   in the array such that:
//
//     a[i] + a[j] == a[k] + a[l]
//
//   where all indices are distinct.
//
// RETURN VALUE:
//   • 1 → if such a pair exists
//   • 0 → otherwise
//
// APPROACH (HASHING):
//   1️⃣ Generate sum of every unique pair (i < j)
//   2️⃣ Store each sum in a hash map
//   3️⃣ If the same sum appears again → answer found
//
// WHY HASH MAP?
//   • Allows O(1) average lookup
//   • Efficient way to detect repeated sums
//
// TIME COMPLEXITY:
//   • O(N²)
//
// SPACE COMPLEXITY:
//   • O(N²) in worst case (all sums unique)
// =====================================================
int findPairs(long long a[], long long n) {

    // Map to store pair sums
    // Key   → sum of a pair
    // Value → dummy (true), since only existence matters
    unordered_map<long long, bool> map;

    // -------------------------------------------------
    // Generate all unique pairs
    // -------------------------------------------------
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {

            // Calculate sum of current pair
            long long sum = a[i] + a[j];

            // -------------------------------------------------
            // If sum already exists → equal sum pair found
            // -------------------------------------------------
            if (map.find(sum) != map.end()) {
                return 1;   // Pair with equal sum exists
            }
            else {
                // Store this sum
                map[sum] = true;
            }
        }
    }

    // No two pairs with equal sum found
    return 0;
}

// =====================================================
// MAIN FUNCTION (TEST CASE)
// =====================================================
int main() {

    /*
        Example:
        a = [3, 4, 7, 1, 2, 9, 8]

        Pair sums:
        (3,4) -> 7
        (7,1) -> 8
        (3,8) -> 11
        (4,7) -> 11  ← SAME SUM FOUND

        Hence → Answer = YES
    */

    long long a[] = {3, 4, 7, 1, 2, 9, 8};
    long long n = sizeof(a) / sizeof(a[0]);

    int result = findPairs(a, n);

    if (result)
        cout << "Pair with equal sum exists" << endl;
    else
        cout << "No such pair exists" << endl;

    return 0;
}
