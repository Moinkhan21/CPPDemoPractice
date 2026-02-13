#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

// =====================================================
// FUNCTION: maxLen
// -----------------------------------------------------
// PURPOSE:
//   Finds the maximum length of a subarray
//   having equal number of 0s and 1s.
//
// KEY IDEA:
//   Convert problem into "Longest subarray with sum = 0"
//
// TRICK:
//   • Replace 0 → -1
//   • Replace 1 → +1
//
// WHY?
//   If number of 0s == number of 1s,
//   then total sum becomes 0.
//
// APPROACH (PREFIX SUM + HASH MAP):
//   1️⃣ Maintain cumulative sum (csum)
//   2️⃣ If csum == 0 → subarray from 0 to i is valid
//   3️⃣ If same csum seen before → subarray between
//      previous index and current index has sum 0
//   4️⃣ Store first occurrence of each csum
//
// TIME COMPLEXITY:
//   • O(N)
//
// SPACE COMPLEXITY:
//   • O(N)
// =====================================================
int maxLen(vector<int>& A, int n) {

    // Map stores: cumulative sum → first index
    unordered_map<int, int> map;

    int csum = 0;   // cumulative sum
    int ans = 0;    // maximum length

    // -------------------------------------------------
    // Traverse the array
    // -------------------------------------------------
    for (int i = 0; i < n; ++i) {

        // -------------------------------------------------
        // STEP 1: Convert values
        // -------------------------------------------------
        // 0 → -1
        // 1 → +1
        int val = (A[i] == 0 ? -1 : 1);

        // Update cumulative sum
        csum += val;

        // -------------------------------------------------
        // STEP 2: If csum is 0
        // -------------------------------------------------
        // Means equal number of 0s and 1s from 0 → i
        if (csum == 0) {
            ans = max(ans, i + 1);
        }

        // -------------------------------------------------
        // STEP 3: First time seeing this sum
        // -------------------------------------------------
        else if (map.find(csum) == map.end()) {
            map[csum] = i;
        }

        // -------------------------------------------------
        // STEP 4: Sum seen before
        // -------------------------------------------------
        // Subarray between previous index and current
        // has sum = 0
        else {
            ans = max(ans, i - map[csum]);
        }
    }

    return ans;
}

// =====================================================
// MAIN FUNCTION
// =====================================================
int main() {

    /*
        Example:
        A = {0, 1, 0, 1, 0, 1, 1}

        Converted:
        {-1, +1, -1, +1, -1, +1, +1}

        Output:
        6
    */

    vector<int> A = {0, 1, 0, 1, 0, 1, 1};
    int n = A.size();

    cout << "Maximum length of subarray with equal 0s and 1s: "
         << maxLen(A, n) << endl;

    return 0;
}
