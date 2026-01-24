#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

bool checkBounds(vector<vector<int>>& grid, vector<pair<int, int>>& v) {
    int m = grid.size();
    int n = grid[0].size();
    for (auto pt : v) {
        if (pt.first < 0 || pt.first >= m || pt.second < 0 || pt.second >= n)
            return false;
    }
    return true;
}

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

void getAllSum(vector<vector<int>>& grid,
               int i, int j,
               priority_queue<int>& pq) {

    // Area 0 rhombus
    pq.push(grid[i][j]);

    int delta = 1;
    vector<pair<int, int>> v(4);

    while (getAllVertices(grid, v, {i, j}, delta)) {

        auto A = v[0];
        auto B = v[1];
        auto C = v[2];
        auto D = v[3];

        int csum = 0;

        // A → B
        for (int k = 0; k < delta; k++)
            csum += grid[A.first + k][A.second + k];

        // B → C
        for (int k = 0; k < delta; k++)
            csum += grid[B.first + k][B.second - k];

        // C → D
        for (int k = 0; k < delta; k++)
            csum += grid[C.first - k][C.second - k];

        // D → A
        for (int k = 0; k < delta; k++)
            csum += grid[D.first - k][D.second + k];

        pq.push(csum);
        ++delta;
    }
}

bool canpush(vector<int>& ans, int top) {
    for (auto val : ans) {
        if (val == top)
            return false;
    }
    return true;
}

vector<int> getBiggestThree(vector<vector<int>>& grid) {

    vector<int> ans;
    priority_queue<int> pq;

    int m = grid.size();
    int n = grid[0].size();

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            getAllSum(grid, i, j, pq);
        }
    }

    while (!pq.empty() && ans.size() < 3) {
        int top = pq.top();
        pq.pop();
        if (canpush(ans, top))
            ans.push_back(top);
    }
    return ans;
}

// ===============================
// MAIN FUNCTION
// ===============================
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
