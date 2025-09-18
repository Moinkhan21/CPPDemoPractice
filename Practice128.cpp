#include <iostream>
#include <vector>
using namespace std;

// Recursive helper function to compute minimum ticket cost
int minCostTicketsHelper(vector<int>& days, vector<int>& costs, int i) {
    // --- Base case ---
    // If we have already covered all travel days, no more cost is needed
    if(i >= days.size()) {
        return 0;
    }

    // --- Solve one case at a time ---

    // ✅ Option 1: Buy a 1-day pass
    // Cost of 1-day pass + recursive call for the next travel day
    int cost1 = costs[0] + minCostTicketsHelper(days, costs, i + 1);

    // ✅ Option 2: Buy a 7-day pass
    // The pass covers days[i] to days[i]+6
    int passEndDay = days[i] + 7 - 1; // Last day covered by 7-day pass
    int j = i; 
    // Skip all travel days that are within the 7-day range
    while(j < days.size() && days[j] <= passEndDay) {
        j++;
    }
    // Cost of 7-day pass + recursive call starting from the first uncovered day
    int cost7 = costs[1] + minCostTicketsHelper(days, costs, j);

    // ✅ Option 3: Buy a 30-day pass
    // The pass covers days[i] to days[i]+29
    passEndDay = days[i] + 30 - 1; // Last day covered by 30-day pass
    j = i;
    // Skip all travel days that are within the 30-day range
    while(j < days.size() && days[j] <= passEndDay) {
        j++;
    }
    // Cost of 30-day pass + recursive call starting from the first uncovered day
    int cost30 = costs[2] + minCostTicketsHelper(days, costs, j);

    // ✅ Return the minimum cost among the 3 choices
    return min(cost1, min(cost7, cost30));
}

// Wrapper function to start recursion from the 0th index
int mincostTickets(vector<int>& days, vector<int>& costs) {
    return minCostTicketsHelper(days, costs, 0);
}

int main() {
    // Example input:
    // Travel days
    vector<int> days{1, 4, 6, 7, 8, 20}; 
    // Ticket costs -> [1-day, 7-day, 30-day]
    vector<int> costs{2, 7, 15}; 

    // Call the function
    int result = mincostTickets(days, costs);

    // Print result
    cout << "Minimum cost for travel: " << result << endl;

    return 0;
}
