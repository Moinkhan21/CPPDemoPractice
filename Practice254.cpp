#include <iostream>
#include <stack>
using namespace std;

// ==========================================================
// ✅ Class: StockSpanner
// ----------------------------------------------------------
// Purpose:
//   Computes the "stock span" for each day's stock price.
//
// Definition of Stock Span:
//   The stock span of today’s price is the number of consecutive 
//   days (including today) for which the price was less than or 
//   equal to today’s price.
//
// Example:
//   Input Prices:  [100, 80, 60, 70, 60, 75, 85]
//   Output Spans:  [1, 1, 1, 2, 1, 4, 6]
//
// Approach:
//   - Maintain a **monotonic decreasing stack** storing pairs of 
//     (price, span).
//   - For each new price, pop all smaller or equal prices and 
//     add their spans to the current span.
//   - Push the current (price, span) pair back into the stack.
//
// Time Complexity:  O(n) (Each price is pushed/popped at most once)
// Space Complexity: O(n)
// ==========================================================
class StockSpanner {
public:
    // Stack stores pairs of {price, span}
    stack<pair<int, int>> st;

    // ✅ Function: next(price)
    // Calculates the stock span for the current day's price.
    int next(int price) {
        int span = 1; // Every day has at least a span of 1 (itself)

        // Pop all previous days where the price was <= today's price
        while (!st.empty() && st.top().first <= price) {
            // Add their spans since today's price covers them too
            span += st.top().second;
            st.pop();
        }

        // Push the current day's price and its computed span
        st.push({price, span});

        // Return computed span
        return span;
    }
};

// ==========================================================
// ✅ Function: Main — Demonstration of StockSpanner
// ----------------------------------------------------------
// Example Walkthrough:
//   Day 1: 100 → No previous higher → Span = 1
//   Day 2:  80 → 80 < 100 → Span = 1
//   Day 3:  60 → 60 < 80  → Span = 1
//   Day 4:  70 → Covers 60 → Span = 2
//   Day 5:  60 → Span = 1
//   Day 6:  75 → Covers 60, 70, 60 → Span = 4
//   Day 7:  85 → Covers 75, 70, 60, 80 → Span = 6
// ----------------------------------------------------------
// Output: [1, 1, 1, 2, 1, 4, 6]
// ==========================================================
int main() {
    StockSpanner ss; // Object of StockSpanner class

    // Input array of stock prices for consecutive days
    int prices[] = {100, 80, 60, 70, 60, 75, 85};
    int n = sizeof(prices) / sizeof(prices[0]);

    cout << "Stock Prices: ";
    for (int p : prices) cout << p << " ";
    cout << "\nSpan Output:  ";

    // Compute span for each price and print result
    for (int i = 0; i < n; i++) {
        cout << ss.next(prices[i]) << " ";
    }
    cout << endl;

    return 0;
}
