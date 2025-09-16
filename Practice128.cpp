#include <iostream>
#include <vector>
using namespace std;

int minCostTicketsHelper(vector<int>& days, vector<int>& costs, int i) {
    //Base case
    if(i >= days.size()) {
        return 0;
    }

    //Solve one case only
    //1 - day pass taken
    int cost1 = costs[0] + minCostTicketsHelper(days, costs, i + 1);

    //7 - day pass taken
    int passEndDay = days[i] + 7 - 1;
    int j = i;
    while(j < days.size() && days[j] <= passEndDay) {
        j++;
    }
    int cost7 = costs[1] + minCostTicketsHelper(days, costs, j);

    //30 - day pass taken
    passEndDay = days[i] + 30 - 1;
    j = i;
    while(j < days.size() && days[j] <= passEndDay) {
        j++;
    }
    int cost30 = costs[2] + minCostTicketsHelper(days, costs, j);

    return min(cost1, min(cost7, cost30));
}

int mincostTickets(vector<int>& days, vector<int>& costs) {
    return minCostTicketsHelper(days, costs, 0);
}

int main() {
    vector<int> days{1, 4, 6, 7, 8, 20}; // Example travel days
    vector<int> costs{2, 7, 15}; // Costs for 1-day, 7-day, and 30-day passes

    int result = mincostTickets(days, costs);
    cout << "Minimum cost for travel: " << result << endl;

    return 0;
}