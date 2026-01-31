#include <string>
#include <iostream>
#include <unordered_map>
using namespace std;

// =====================================================
// FUNCTION: isSubset
// -----------------------------------------------------
// PURPOSE:
//   Checks whether array a2[] is a subset of array a1[].
//
// DEFINITION (SUBSET):
//   • Every element of a2 must be present in a1
//   • Frequency of each element in a2 must not exceed
//     its frequency in a1
//
// INPUT:
//   • a1[] → main array
//   • a2[] → array to be checked as subset
//   • n    → size of a1
//   • m    → size of a2
//
// OUTPUT:
//   • "Yes" → if a2 is a subset of a1
//   • "No"  → otherwise
//
// APPROACH (HASHING):
//   1️⃣ Store frequency of each element of a1 in map
//   2️⃣ Traverse a2 and check:
//       • element exists in map
//       • frequency > 0
//   3️⃣ Reduce frequency after every match
//
// TIME COMPLEXITY:
//   • O(n + m)
//
// SPACE COMPLEXITY:
//   • O(n)
// =====================================================
string isSubset(int a1[], int a2[], int n, int m) {

    unordered_map<int, int> map;
    string ans = "Yes";

    // -------------------------------------------------
    // Step 1: Frequency mapping of a1[]
    // -------------------------------------------------
    // Store count of each element in a1
    for (int i = 0; i < n; i++) {
        map[a1[i]]++;
    }

    // -------------------------------------------------
    // Step 2: Check elements of a2[]
    // -------------------------------------------------
    for (int i = 0; i < m; ++i) {

        // If element does not exist in a1
        if (map.find(a2[i]) == map.end()) {
            ans = "No";
            break;
        }
        else {
            // Element exists, check frequency
            if (map[a2[i]] > 0) {
                map[a2[i]]--;   // use one occurrence
            }
            else {
                // Frequency exhausted
                ans = "No";
                break;
            }
        }
    }

    return ans;
}

// =====================================================
// MAIN FUNCTION (TEST CASE)
// =====================================================
int main() {

    /*
        a1 = {11, 1, 13, 21, 3, 7}
        a2 = {11, 3, 7, 1}

        All elements of a2 exist in a1
        with sufficient frequency

        Output: Yes
    */

    int a1[] = {11, 1, 13, 21, 3, 7};
    int a2[] = {11, 3, 7, 1};

    int n = sizeof(a1) / sizeof(a1[0]);
    int m = sizeof(a2) / sizeof(a2[0]);

    cout << "Is a2 a subset of a1? "
         << isSubset(a1, a2, n, m) << endl;

    return 0;
}
