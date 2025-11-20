#include <iostream>
#include <stack>
#include <vector>
#include <climits>
using namespace std;

// ====================================================================================================
// FUNCTION: prevSmallerElement
// ----------------------------------------------------------------------------------------------------
// PURPOSE:
//   For each index i, find the index of the nearest smaller element to the LEFT.
//   If no smaller element exists on the left → return -1.
//
// WHY WE NEED THIS?
//   In the "largest rectangle in histogram" problem,
//   each bar expands left until it finds a smaller bar.
//
// APPROACH (Monotonic Stack):
//   • Stack stores indices of bars in increasing height order.
//   • For each height[i], pop from stack until we find a smaller bar.
//   • The top of stack becomes the previous smaller index.
//   • Push the current index.
//
// Time:  O(n)
// Space: O(n)
// ====================================================================================================
vector<int> prevSmallerElement(vector<int>& input) {
    stack<int> s;
    s.push(-1);           // Sentinel for "no previous smaller"
    int n = input.size();

    vector<int> ans(n);

    for (int i = 0; i < n; i++) {
        int curr = input[i];

        // Pop until a smaller element is found
        while (s.top() != -1 && input[s.top()] >= curr) {
            s.pop();
        }

        ans[i] = s.top(); // nearest smaller to LEFT
        s.push(i);        // push current index
    }
    return ans;
}

// ====================================================================================================
// FUNCTION: nextSmallerElement
// ----------------------------------------------------------------------------------------------------
// PURPOSE:
//   For each index i, find the nearest smaller element to the RIGHT.
//   If none exists → return -1.
//
// WHY NEEDED?
//   In histogram rectangle calculation, each bar expands RIGHT until a smaller bar blocks it.
//
// APPROACH:
//   • Traverse from right to left.
//   • Maintain increasing stack (based on heights).
//   • Similar logic to prevSmaller but reversed direction.
//
// Time:  O(n)
// Space: O(n)
// ====================================================================================================
vector<int> nextSmallerElement(vector<int>& input) {
    stack<int> s;
    s.push(-1);           // Sentinel
    int n = input.size();

    vector<int> ans(n);

    for (int i = n - 1; i >= 0; i--) {
        int curr = input[i];

        // Pop until a smaller element is found
        while (s.top() != -1 && input[s.top()] >= curr) {
            s.pop();
        }

        ans[i] = s.top(); // nearest smaller to RIGHT
        s.push(i);
    }
    return ans;
}

// ====================================================================================================
// FUNCTION: getRectangularAreaHistogram
// ----------------------------------------------------------------------------------------------------
// PURPOSE:
//   Compute the largest rectangle area in a histogram using:
//      • prevSmallerElement
//      • nextSmallerElement
//
// FORMULA:
//   width = next_smaller_index - prev_smaller_index - 1
//   area  = height[i] * width
//
// WHY THIS WORKS?
//   For each bar, we expand as far left/right as possible until a smaller bar stops expansion.
//
// Time:  O(n)
// Space: O(n)
// ====================================================================================================
int getRectangularAreaHistogram(vector<int>& height) {

    vector<int> prev = prevSmallerElement(height);
    vector<int> next = nextSmallerElement(height);

    int maxArea = INT_MIN;
    int n = height.size();

    for (int i = 0; i < n; i++) {
        int h = height[i];

        // If no smaller on right → treat next index as N
        if (next[i] == -1)
            next[i] = n;

        int width = next[i] - prev[i] - 1;
        int area = h * width;

        maxArea = max(maxArea, area);
    }

    return maxArea;
}

// ====================================================================================================
// FUNCTION: maximaRectangle
// ----------------------------------------------------------------------------------------------------
// PURPOSE:
//   Compute the largest rectangle full of '1's in a binary CHAR matrix.
//
// KEY IDEA:
//   Treat each row like the base of a histogram.
//   Convert each row into a histogram of heights:
//      • If matrix[i][j] == '1' → height += 1
//      • Else → height = 0
//   Now apply histogram max-area algorithm to each row.
//
// WHY THIS WORKS?
//   A full rectangle of ones can be represented as stacked histogram bars.
//
// Time:  O(n * m)
// Space: O(m)
// ====================================================================================================
int maximaRectangle(vector<vector<char>>& matrix) {

    // Guard condition: Empty matrix
    if (matrix.empty() || matrix[0].empty())
        return 0;

    int n = matrix.size();
    int m = matrix[0].size();

    // Convert char matrix → int matrix (0/1)
    vector<vector<int>> v(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            v[i][j] = matrix[i][j] - '0';

    // Compute area for first row (histogram)
    int area = getRectangularAreaHistogram(v[0]);

    // For every row below, accumulate heights to build histogram,
    // then compute max rectangle for that updated histogram.
    for (int i = 1; i < n; i++) {

        for (int j = 0; j < m; j++) {
            if (v[i][j] == 1)
                v[i][j] += v[i - 1][j];  // add height from above row
            else
                v[i][j] = 0;            // reset height
        }

        area = max(area, getRectangularAreaHistogram(v[i]));
    }

    return area;
}

// ====================================================================================================
// MAIN FUNCTION — Testing Maximal Rectangle
// ====================================================================================================
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
