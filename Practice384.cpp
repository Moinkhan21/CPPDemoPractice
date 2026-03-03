#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

// =====================================================
// PROGRAM: Maximum Area of Unblocked Rectangle
// -----------------------------------------------------
// PROBLEM:
//   Given a grid of size (x × y) and n blocked cells,
//   find the maximum area of a rectangle that does NOT
//   contain any blocked cell.
//
// IDEA:
//   1️⃣ Store all blocked row coordinates
//   2️⃣ Store all blocked column coordinates
//   3️⃣ Add boundaries (0 and x+1 / y+1)
//   4️⃣ Sort them
//   5️⃣ Find maximum gap between consecutive rows
//   6️⃣ Find maximum gap between consecutive columns
//   7️⃣ Multiply both to get maximum area
//
// WHY THIS WORKS?
//   • The largest empty rectangle will lie between
//     two consecutive blocked rows and columns.
//
// TIME COMPLEXITY:
//   • O(n log n) → due to sorting
//
// SPACE COMPLEXITY:
//   • O(n)
// =====================================================
int main() {

    // -------------------------------------------------
    // INPUT:
    // x → total rows
    // y → total columns
    // n → number of blocked cells
    // -------------------------------------------------
    int x, y, n;
    cin >> x >> y >> n;

    int t = n;

    // Vectors to store blocked row and column positions
    vector<int> rowC;
    vector<int> colC;

    // -------------------------------------------------
    // STEP 1: Add boundary 0 (before grid starts)
    // -------------------------------------------------
    rowC.push_back(0);
    colC.push_back(0);

    // -------------------------------------------------
    // STEP 2: Store blocked cell positions
    // -------------------------------------------------
    while (t--) {
        int a, b;
        cin >> a >> b;
        rowC.push_back(a);
        colC.push_back(b);
    }

    // -------------------------------------------------
    // STEP 3: Add ending boundary (x+1, y+1)
    // -------------------------------------------------
    // This helps calculate gap till end of grid
    rowC.push_back(x + 1);
    colC.push_back(y + 1);

    // -------------------------------------------------
    // STEP 4: Sort coordinates
    // -------------------------------------------------
    sort(rowC.begin(), rowC.end());
    sort(colC.begin(), colC.end());

    // Debug printing (optional)
    for (auto i : rowC) {
        cout << i << " ";
    }
    cout << endl;

    for (auto i : colC) {
        cout << i << " ";
    }
    cout << endl;

    // -------------------------------------------------
    // STEP 5: Find maximum gap between rows
    // -------------------------------------------------
    int maxLen = INT_MIN;

    for (int i = 1; i < rowC.size(); i++) {
        int a = rowC[i - 1];
        int b = rowC[i];

        // -1 because blocked cells cannot be included
        maxLen = max(maxLen, b - a - 1);
    }

    // -------------------------------------------------
    // STEP 6: Find maximum gap between columns
    // -------------------------------------------------
    int maxWidth = INT_MIN;

    for (int i = 1; i < colC.size(); i++) {
        int a = colC[i - 1];
        int b = colC[i];

        maxWidth = max(maxWidth, b - a - 1);
    }

    // -------------------------------------------------
    // STEP 7: Maximum Area
    // -------------------------------------------------
    cout << "answer is " << maxLen * maxWidth << endl;

    return 0;
}