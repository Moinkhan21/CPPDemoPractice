#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// =====================================================
// FUNCTION: cmp (Comparator)
// -----------------------------------------------------
// PURPOSE:
//   Sort intervals based on departure time.
//
// WHY SORT BY DEPARTURE?
//   • To select maximum number of non-overlapping intervals
//   • Greedy strategy: finish early → allow more intervals
// =====================================================
bool cmp(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

// =====================================================
// FUNCTION: solve
// -----------------------------------------------------
// PROBLEM:
//   Given arrival and departure times of trains,
//   select maximum number of non-overlapping trains.
//
//   (Classic Activity Selection Problem)
//
// APPROACH (GREEDY):
//   1️⃣ Combine arrival & departure into pairs
//   2️⃣ Sort by departure time
//   3️⃣ Select first interval
//   4️⃣ For remaining intervals:
//        If arrival >= last selected departure
//        → Select it
//
// WHY GREEDY WORKS?
//   • Choosing earliest finishing activity leaves
//     maximum room for future selections.
//
// TIME COMPLEXITY:
//   • O(n log n) → due to sorting
//
// SPACE COMPLEXITY:
//   • O(n)
// =====================================================
int solve(int n, int arr[], int dept[]) {

    // Edge case
    if (n == 0) return 0;

    vector<pair<int, int>> data;

    // -------------------------------------------------
    // STEP 1: Store arrival and departure as pairs
    // -------------------------------------------------
    for (int i = 0; i < n; i++) {
        data.push_back({arr[i], dept[i]});
    }

    // -------------------------------------------------
    // STEP 2: Sort by departure time
    // -------------------------------------------------
    sort(data.begin(), data.end(), cmp);

    int cnt = 1;  // First interval is always selected

    // -------------------------------------------------
    // STEP 3: Select first interval
    // -------------------------------------------------
    cout << data[0].first << ", " << data[0].second << endl;
    int lastDept = data[0].second;

    // -------------------------------------------------
    // STEP 4: Traverse remaining intervals
    // -------------------------------------------------
    for (int i = 1; i < n; i++) {

        // If current arrival >= last departure
        // → No overlap → Select it
        if (data[i].first >= lastDept) {

            cnt++;
            lastDept = data[i].second;

            // Print selected interval
            cout << data[i].first << ", " << data[i].second << endl;
        }
    }

    return cnt;
}

// =====================================================
// MAIN FUNCTION
// -----------------------------------------------------
// PURPOSE:
//   Entry point of program
// =====================================================
int main() {

    int n = 4;

    int arr[] = {5, 8, 2, 4};
    int dept[] = {7, 11, 6, 5};

    int ans = solve(n, arr, dept);

    cout << "Answer is: " << ans << endl;

    return 0;
}