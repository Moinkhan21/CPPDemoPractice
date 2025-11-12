#include <iostream>
#include <stack>
#include <vector>
#include <climits>
using namespace std;

// =============================================================
// ✅ Function: prevSmallerElement()
// -------------------------------------------------------------
// Finds the index of the previous smaller element for every bar
// in the histogram. If no smaller element exists, returns -1.
// Traverses from **left to right**.
// =============================================================
vector<int> prevSmallerElement(vector<int>& input) {
    stack<int> s;       // Stack stores indices, not values
    s.push(-1);         // Base value when no smaller element exists
    vector<int> ans(input.size());

    for (int i = 0; i < input.size(); i++) {
        int curr = input[i];

        // Pop elements until a smaller element is found or stack becomes empty
        while (s.top() != -1 && input[s.top()] >= curr) {
            s.pop();
        }

        // Store index of previous smaller element
        ans[i] = s.top();

        // Push current element's index to stack
        s.push(i);
    }
    return ans;
}

// =============================================================
// ✅ Function: nextSmallerElement()
// -------------------------------------------------------------
// Finds the index of the next smaller element for every bar
// in the histogram. If no smaller element exists, returns -1.
// Traverses from **right to left**.
// =============================================================
vector<int> nextSmallerElement(vector<int>& input) {
    stack<int> s;
    s.push(-1);
    vector<int> ans(input.size());

    for (int i = input.size() - 1; i >= 0; i--) {
        int curr = input[i];

        // Pop until a smaller element is found or stack becomes empty
        while (s.top() != -1 && input[s.top()] >= curr) {
            s.pop();
        }

        // Store index of next smaller element
        ans[i] = s.top();

        // Push current element's index
        s.push(i);
    }
    return ans;
}

// =============================================================
// ✅ Function: getRectangularAreaHistogram()
// -------------------------------------------------------------
// Purpose:
//   Calculates the **largest rectangular area** possible in a
//   histogram represented by bar heights.
//
// Approach:
//   - For each bar, determine how far it can extend left and right
//     without encountering a smaller bar.
//   - Use previous and next smaller indices to determine width.
//   - Area = height * width for each bar, track maximum.
// =============================================================
int getRectangularAreaHistogram(vector<int>& height) {
    // Step 1: Find previous smaller element indices
    vector<int> prev = prevSmallerElement(height);

    // Step 2: Find next smaller element indices
    vector<int> next = nextSmallerElement(height);

    int maxArea = INT_MIN;
    int size = height.size();

    // Step 3: Calculate area for each bar
    for (int i = 0; i < size; i++) {
        int length = height[i]; // Height of current bar

        // If no smaller element on right, treat boundary as end
        if (next[i] == -1) {
            next[i] = size;
        }

        // Width = distance between next smaller and previous smaller indices - 1
        int width = next[i] - prev[i] - 1;

        // Area for current bar
        int area = length * width;

        // Keep track of the maximum area
        maxArea = max(maxArea, area);
    }

    return maxArea;
}

// =============================================================
// ✅ MAIN FUNCTION — Testing Largest Rectangle in Histogram
// -------------------------------------------------------------
// Example:
// Input: [2, 1, 5, 6, 2, 3]
// Output: 10  (rectangle covering bars with height 5 and 6)
// =============================================================
int main() {
    vector<int> v = {2, 1, 5, 6, 2, 3};

    cout << "Maximum Rectangular Area in Histogram: "
         << getRectangularAreaHistogram(v) << endl;

    return 0;
}
