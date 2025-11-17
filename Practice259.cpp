#include <iostream>
#include <stack>
#include <vector>
#include <climits>
using namespace std;

// =============================================================
// PREVIOUS SMALLER ELEMENT (Left Boundary)
// =============================================================
vector<int> prevSmallerElement(vector<int>& input) {
    stack<int> s;
    s.push(-1);
    int n = input.size();
    vector<int> ans(n);

    for (int i = 0; i < n; i++) {
        int curr = input[i];

        while (s.top() != -1 && input[s.top()] >= curr) {
            s.pop();
        }
        ans[i] = s.top();
        s.push(i);
    }
    return ans;
}

// =============================================================
// NEXT SMALLER ELEMENT (Right Boundary)
// =============================================================
vector<int> nextSmallerElement(vector<int>& input) {
    stack<int> s;
    s.push(-1);
    int n = input.size();
    vector<int> ans(n);

    for (int i = n - 1; i >= 0; i--) {
        int curr = input[i];

        while (s.top() != -1 && input[s.top()] >= curr) {
            s.pop();
        }
        ans[i] = s.top();
        s.push(i);
    }
    return ans;
}

// =============================================================
// MAXIMUM AREA IN HISTOGRAM
// =============================================================
int getRectangularAreaHistogram(vector<int>& height) {
    vector<int> prev = prevSmallerElement(height);
    vector<int> next = nextSmallerElement(height);

    int maxArea = INT_MIN;
    int n = height.size();

    for (int i = 0; i < n; i++) {
        int h = height[i];

        if (next[i] == -1)
            next[i] = n;

        int width = next[i] - prev[i] - 1;
        int area = h * width;

        maxArea = max(maxArea, area);
    }

    return maxArea;
}

// =============================================================
// MAXIMAL RECTANGLE IN BINARY MATRIX
// =============================================================
int maximaRectangle(vector<vector<char>>& matrix) {

    if (matrix.empty() || matrix[0].empty())
        return 0;

    int n = matrix.size();
    int m = matrix[0].size();

    // Convert char matrix to int matrix
    vector<vector<int>> v(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            v[i][j] = matrix[i][j] - '0';

    // Compute area for the first row histogram
    int area = getRectangularAreaHistogram(v[0]);

    // For each next row, accumulate heights
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (v[i][j] == 1)
                v[i][j] += v[i - 1][j];
            else
                v[i][j] = 0;
        }
        area = max(area, getRectangularAreaHistogram(v[i]));
    }

    return area;
}

// =============================================================
// MAIN FUNCTION — Test Cases
// =============================================================
int main() {

    vector<vector<char>> matrix = {
        {'1','0','1','0','0'},
        {'1','0','1','1','1'},
        {'1','1','1','1','1'},
        {'1','0','0','1','0'}
    };

    cout << "Maximum Rectangle Area: "
         << maximaRectangle(matrix) << endl;

    return 0;
}
