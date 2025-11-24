#include <iostream>
#include <vector>
using namespace std;

// ==========================================================
// FUNCTION: canCompleteCircuit
// ==========================================================
int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {

    int deficit = 0;   // total shortage
    int balance = 0;   // current fuel
    int start = 0;     // starting index candidate

    int n = gas.size();
    if (n == 0) return -1;

    for (int i = 0; i < n; i++) {

        balance += gas[i] - cost[i];

        // If balance goes negative, this segment fails
        if (balance < 0) {
            deficit += balance;  // record shortage
            start = i + 1;       // next position becomes new start
            balance = 0;         // reset tank
        }
    }

    // Check if total fuel is enough
    if (balance + deficit >= 0)
        return start;

    return -1;
}

// ==========================================================
// MAIN — Test Gas Station algorithm
// ==========================================================
int main() {

    vector<int> gas  = {1, 2, 3, 4, 5};
    vector<int> cost = {3, 4, 5, 1, 2};

    int startIndex = canCompleteCircuit(gas, cost);

    cout << "Starting station index: " << startIndex << endl;

    return 0;
}
