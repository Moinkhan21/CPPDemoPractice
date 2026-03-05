#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

// =====================================================
// FUNCTION: maxLen
// -----------------------------------------------------
// PROBLEM:
//   Find the maximum length of a subarray
//   with sum equal to 0.
//
// EXAMPLE:
//   A = {15, -2, 2, -8, 1, 7, 10, 23}
//
//   Subarray with sum 0:
//   {-2, 2, -8, 1, 7}
//
//   Length = 5
//
// APPROACH (PREFIX SUM + HASH MAP):
//   1️⃣ Maintain cumulative sum (csum)
//   2️⃣ If csum becomes 0 → subarray from 0 to i
//   3️⃣ If csum repeats → subarray between the
//      previous index and current index has sum 0
//
// WHY THIS WORKS?
//   If prefixSum[i] == prefixSum[j],
//   then the elements between (i+1 ... j)
//   must sum to 0.
//
// TIME COMPLEXITY:
//   • O(n)
//
// SPACE COMPLEXITY:
//   • O(n)
// =====================================================
int maxLen(vector<int>& A, int n) {

    // Hash map stores:
    // {prefixSum → first index where it occurred}
    unordered_map<int, int> map;

    int csum = 0;   // cumulative prefix sum
    int ans = 0;    // stores maximum length

    // -------------------------------------------------
    // Traverse the array
    // -------------------------------------------------
    for (int i = 0; i < n; ++i) {

        // Update cumulative sum
        csum += A[i];

        // -------------------------------------------------
        // CASE 1: If cumulative sum becomes 0
        // Entire subarray (0..i) has sum 0
        // -------------------------------------------------
        if (csum == 0) {
            ans = max(ans, i + 1);
        }

        // -------------------------------------------------
        // CASE 2: If this prefix sum is seen first time
        // Store its index
        // -------------------------------------------------
        else if (map.find(csum) == map.end()) {
            map[csum] = i;
        }

        // -------------------------------------------------
        // CASE 3: Prefix sum already seen
        // Subarray between previous index and current
        // has sum 0
        // -------------------------------------------------
        else {
            ans = max(ans, i - map[csum]);
        }
    }

    return ans;
}

// =====================================================
// MAIN FUNCTION
// -----------------------------------------------------
// PURPOSE:
//   Entry point of program
// =====================================================
int main() {

    /*
        Example:
        A = {15, -2, 2, -8, 1, 7, 10, 23}

        Longest subarray with sum 0:
        {-2, 2, -8, 1, 7}

        Length = 5
    */

    vector<int> A = {15, -2, 2, -8, 1, 7, 10, 23};
    int n = A.size();

    cout << "Maximum length of subarray with sum 0: "
         << maxLen(A, n) << endl;

    return 0;
}