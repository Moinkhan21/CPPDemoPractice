#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

// =====================================================
// FUNCTION: checkBounds
// -----------------------------------------------------
// PURPOSE:
//   Checks whether all given coordinates lie inside
//   the grid boundaries.
//
// PARAMETERS:
//   grid → input matrix
//   v    → vector containing 4 vertices
//
// RETURN:
//   true  → if all vertices are inside grid
//   false → if any vertex goes outside grid
// =====================================================
bool checkBounds(vector<vector<int>>& grid, vector<pair<int, int>>& v) {

    int m = grid.size();
    int n = grid[0].size();

    for (auto pt : v) {

        // Check row and column limits
        if (pt.first < 0 || pt.first >= m ||
            pt.second < 0 || pt.second >= n)
            return false;
    }

    return true;
}

// =====================================================
// FUNCTION: getAllVertices
// -----------------------------------------------------
// PURPOSE:
//   Calculates the 4 vertices of a rhombus centered at
//   position (c.first, c.second) with radius = delta.
//
// RHOMBUS VERTICES:
//
//        A
//        |
//    D --C-- B
//
// PARAMETERS:
//   c     → center of rhombus
//   delta → distance from center to vertex
//
// RETURN:
//   true if rhombus fits inside grid
// =====================================================
bool getAllVertices(vector<vector<int>>& grid,
                    vector<pair<int, int>>& v,
                    pair<int, int> c,
                    int delta) {

    pair<int, int> A(c.first - delta, c.second);
    pair<int, int> B(c.first, c.second + delta);
    pair<int, int> C(c.first + delta, c.second);
    pair<int, int> D(c.first, c.second - delta);

    v[0] = A;
    v[1] = B;
    v[2] = C;
    v[3] = D;

    return checkBounds(grid, v);
}

// =====================================================
// FUNCTION: getAllSum
// -----------------------------------------------------
// PURPOSE:
//   Calculates all rhombus border sums centered at
//   (i, j) and pushes them into the max heap.
//
// APPROACH:
//
//   1️⃣ Start with area 0 rhombus (single cell)
//   2️⃣ Expand rhombus using delta
//   3️⃣ Compute border sum for each rhombus
//
// NOTE:
//   Only the BORDER of rhombus is included.
// =====================================================
void getAllSum(vector<vector<int>>& grid,
               int i, int j,
               priority_queue<int>& pq) {

    // Area 0 rhombus (single cell)
    pq.push(grid[i][j]);

    int delta = 1;

    vector<pair<int, int>> v(4);

    // Expand rhombus until it goes outside grid
    while (getAllVertices(grid, v, {i, j}, delta)) {

        auto A = v[0];
        auto B = v[1];
        auto C = v[2];
        auto D = v[3];

        int csum = 0;

        // ---------------------------------------------
        // Traverse edges of rhombus
        // ---------------------------------------------

        // Edge A → B
        for (int k = 0; k < delta; k++)
            csum += grid[A.first + k][A.second + k];

        // Edge B → C
        for (int k = 0; k < delta; k++)
            csum += grid[B.first + k][B.second - k];

        // Edge C → D
        for (int k = 0; k < delta; k++)
            csum += grid[C.first - k][C.second - k];

        // Edge D → A
        for (int k = 0; k < delta; k++)
            csum += grid[D.first - k][D.second + k];

        pq.push(csum);

        ++delta;
    }
}

// =====================================================
// FUNCTION: canpush
// -----------------------------------------------------
// PURPOSE:
//   Ensures only unique values are inserted
//   into the result vector.
//
// RETURN:
//   true  → value not present
//   false → value already exists
// =====================================================
bool canpush(vector<int>& ans, int top) {

    for (auto val : ans) {
        if (val == top)
            return false;
    }

    return true;
}

// =====================================================
// FUNCTION: getBiggestThree
// -----------------------------------------------------
// PROBLEM:
//   Find the top 3 largest distinct rhombus sums
//   in a given grid.
//
// APPROACH:
//
//   1️⃣ Generate all rhombus border sums
//   2️⃣ Store them in max heap
//   3️⃣ Extract top 3 distinct values
//
// TIME COMPLEXITY:
//   O(m*n*min(m,n))
//
// SPACE COMPLEXITY:
//   O(k) where k = number of rhombus sums
// =====================================================
vector<int> getBiggestThree(vector<vector<int>>& grid) {

    vector<int> ans;

    priority_queue<int> pq;

    int m = grid.size();
    int n = grid[0].size();

    // Generate rhombus sums for every cell
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {

            getAllSum(grid, i, j, pq);
        }
    }

    // Extract top 3 distinct values
    while (!pq.empty() && ans.size() < 3) {

        int top = pq.top();
        pq.pop();

        if (canpush(ans, top))
            ans.push_back(top);
    }

    return ans;
}

// =====================================================
// MAIN FUNCTION
// -----------------------------------------------------
// PURPOSE:
//   Demonstrates finding top 3 rhombus sums
// =====================================================
int main() {

    vector<vector<int>> grid = {
        {3, 4, 5, 1},
        {3, 3, 4, 2},
        {20, 30, 200, 40},
        {1, 5, 5, 4}
    };

    vector<int> ans = getBiggestThree(grid);

    cout << "Biggest three rhombus sums:\n";

    for (int x : ans)
        cout << x << " ";

    cout << endl;

    return 0;
}