#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Recursive helper function to calculate max profit
void maxProfitFinder(vector<int>& prices, int i, int& minPrice, int& maxProfit){
    
    // Base case: if we have processed all days, stop recursion
    if(i == prices.size()) return;

    // --- Solve only one case ---
    // Update the minimum price if the current price is lower
    if(prices[i] < minPrice) 
        minPrice = prices[i];

    // Calculate today's profit (sell today after buying at minPrice)
    int todaysProfit = prices[i] - minPrice;

    // Update maxProfit if today's profit is greater
    if(todaysProfit > maxProfit) 
        maxProfit = todaysProfit;

    // --- Recursive call ---
    // Move to the next day
    maxProfitFinder(prices, i + 1, minPrice, maxProfit);
}

// Main function to start recursion
int maxProfit(vector<int>& prices) {
    // Initialize minimum price as maximum possible int value
    int minPrice = INT_MAX;

    // Initialize maxProfit as the smallest possible int value
    // (So that first profit calculation will always be larger)
    int maxProfit = INT_MIN;

    // Start recursive process from day 0
    maxProfitFinder(prices, 0, minPrice, maxProfit);

    return maxProfit;
}

int main() {
    // Example stock prices on different days
    vector<int> prices{7, 1, 5, 3, 6, 4};

    // Find maximum profit
    int ans = maxProfit(prices);

    // Print the result
    cout << ans << endl;

    return 0;
}
