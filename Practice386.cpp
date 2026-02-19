#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// =====================================================
// FUNCTION: cmp (Comparator)
// -----------------------------------------------------
// PURPOSE:
//   Sort items based on value/weight ratio (descending)
//
// WHY?
//   • Higher value per weight should be picked first
//   • This ensures maximum profit
//
// FORMULA:
//   ratio = value / weight
// =====================================================
bool cmp(pair<int, int> a, pair<int, int> b) {
    double ratio1 = ((1.0) * a.first) / a.second;
    double ratio2 = ((1.0) * b.first) / b.second;
    return ratio1 > ratio2;   // descending order
}

// =====================================================
// MAIN FUNCTION
// -----------------------------------------------------
// PROBLEM:
//   Given weights and values of items and a knapsack
//   with capacity W, maximize total value.
//
//   👉 You can take FRACTIONS of items
//
// APPROACH: GREEDY
//
// IDEA:
//   1️⃣ Calculate value/weight ratio
//   2️⃣ Sort items in decreasing ratio
//   3️⃣ Take full item if possible
//   4️⃣ Otherwise take fraction
//
// TIME COMPLEXITY:
//   • O(N log N) → sorting
//
// SPACE COMPLEXITY:
//   • O(N)
// =====================================================
int main() {

    int val[] = {60, 100, 120};   // values
    int wt[] = {10, 20, 30};      // weights
    int n = 3;
    int capacity = 50;            // knapsack capacity

    // -------------------------------------------------
    // STEP 1: Store value and weight together
    // -------------------------------------------------
    vector<pair<int, int>> data;

    for (int i = 0; i < n; i++) {
        data.push_back({val[i], wt[i]});
    }

    // -------------------------------------------------
    // STEP 2: Sort based on value/weight ratio
    // -------------------------------------------------
    sort(data.begin(), data.end(), cmp);

    // Print sorted items (for understanding)
    cout << "Sorted by value/weight ratio:\n";
    for (auto i : data) {
        cout << i.first << ", " << i.second << endl;
    }

    // -------------------------------------------------
    // STEP 3: Pick items greedily
    // -------------------------------------------------
    double totalValue = 0;   // total profit

    for (int i = 0; i < n; i++) {

        pair<int, int> item = data[i];

        int itemValue = item.first;
        int itemWeight = item.second;

        // -------------------------------------------------
        // CASE 1: Entire item can be taken
        // -------------------------------------------------
        if (itemWeight <= capacity) {

            totalValue += itemValue;

            // Reduce capacity
            capacity = capacity - itemWeight;
        }
        else {
            // -------------------------------------------------
            // CASE 2: Take fraction of item
            // -------------------------------------------------
            double ratio = ((1.0) * itemValue) / itemWeight;

            // Take only required portion
            double valueToAdd = ratio * capacity;

            totalValue += valueToAdd;

            // Knapsack is full
            capacity = 0;

            break;  // no more capacity left
        }
    }

    // -------------------------------------------------
    // FINAL ANSWER
    // -------------------------------------------------
    cout << "Maximum value in knapsack = " << totalValue << endl;

    return 0;
}
