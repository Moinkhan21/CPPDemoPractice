#include <iostream>
#include <vector>
using namespace std;

// ============================================================================
// FUNCTION: canCompleteCircuit
// PURPOSE:
//   Given two arrays:
//      gas[i]  → gas available at station i
//      cost[i] → gas required to travel from station i to i+1
//
//   Determine the FIRST index from which a circular trip is possible.
//
// KEY INSIGHT:
//   - If total gas < total cost → NO solution.
//   - If starting from some index, balance becomes negative, then ANY index
//     between the chosen start and this failure point CANNOT be a valid start.
//   - Reset start to next index and continue.
//
// TIME COMPLEXITY: O(n)
// SPACE COMPLEXITY: O(1)
// ============================================================================
int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {

    int deficit = 0;   // Tracks total fuel shortage accumulated during failures
    int balance = 0;   // Tracks current fuel in tank while testing a route
    int start = 0;     // Current candidate for the starting station

    int n = gas.size();
    if (n == 0) return -1; // Edge-case: empty arrays

    // ------------------------------------------------------------------------
    // Traverse each station and simulate fuel collection and consumption
    // ------------------------------------------------------------------------
    for (int i = 0; i < n; i++) {

        // Add fuel gained at station i and subtract cost to travel to i+1
        balance += gas[i] - cost[i];

        // --------------------------------------------------------------------
        // FAILURE CONDITION:
        // If balance becomes negative, we cannot start from 'start' to this 'i'
        // because we ran out of fuel before completing segment.
        //
        // IMPORTANT IDEA:
        //     Every station between 'start' and 'i' is also invalid.
        //
        // So we:
        //   1. Add the negative balance to deficit (shortage)
        //   2. Reset balance to 0 (as if restarting fresh)
        //   3. Move start to i+1
        // --------------------------------------------------------------------
        if (balance < 0) {
            deficit += balance;   // accumulate negative shortage
            start = i + 1;        // next station becomes the new start candidate
            balance = 0;          // reset current fuel
        }
    }

    // ------------------------------------------------------------------------
    // FINAL CHECK:
    // If total fuel (balance + deficit) is non-negative,
    // we can complete the full circuit starting from 'start'.
    // ------------------------------------------------------------------------
    if (balance + deficit >= 0)
        return start;

    return -1;  // Not enough fuel overall
}

// ============================================================================
// MAIN — Test Gas Station algorithm
// ============================================================================
int main() {

    vector<int> gas  = {1, 2, 3, 4, 5};
    vector<int> cost = {3, 4, 5, 1, 2};

    int startIndex = canCompleteCircuit(gas, cost);

    cout << "Starting station index: " << startIndex << endl;

    return 0;
}
