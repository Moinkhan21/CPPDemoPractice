#include <iostream>
#include <stack>
using namespace std;

// ========================================
// ✅ Class: StockSpanner
// Uses a monotonic decreasing stack to compute stock spans
// ========================================
class StockSpanner {
public:
    // Stack stores pairs of {price, span}
    stack<pair<int, int>> st;

    // Function to return span for the current day's price
    int next(int price) {
        int span = 1;  // Minimum span is always 1

        // Pop all previous prices that are <= current price
        while (!st.empty() && st.top().first <= price) {
            span += st.top().second;  // Add their spans
            st.pop();
        }

        // Push current price with its calculated span
        st.push({price, span});

        return span;
    }
};

// ========================================
// ✅ Main Function to Test StockSpanner
// ========================================
int main() {
    StockSpanner ss;

    // Example input stream of prices
    int prices[] = {100, 80, 60, 70, 60, 75, 85};
    int n = sizeof(prices) / sizeof(prices[0]);

    cout << "Stock Prices: ";
    for (int p : prices) cout << p << " ";
    cout << "\nSpan Output: ";

    for (int i = 0; i < n; i++) {
        cout << ss.next(prices[i]) << " ";
    }
    cout << endl;

    return 0;
}
