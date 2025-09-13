#include <iostream>
#include <vector>
#include <climits>
using namespace std;

void maxProfitFinder(vector<int>& prices, int i, int& minPrice, int& maxProfit){
    
    //Base case
    if(i == prices.size()) return;

    //Solve only one case
    if(prices[i] < minPrice) minPrice = prices[i];
    int todaysProfit = prices[i] - minPrice;
    if(todaysProfit > maxProfit) maxProfit = todaysProfit;

    //Recursive call
    maxProfitFinder(prices, i + 1, minPrice, maxProfit);
}

int maxProfit(vector<int>& prices) {
    int minPrice = INT_MAX;
    int maxProfit = INT_MIN;

    maxProfitFinder(prices, 0, minPrice, maxProfit);
    return maxProfit;
}

int main() {
    vector<int> prices{7, 1, 5, 3, 6, 4};
    int ans = maxProfit(prices);
    cout << ans << endl;

    return 0;
}