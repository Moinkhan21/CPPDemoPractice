#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// =====================================================
// FUNCTION: minRefuelStops
// -----------------------------------------------------
// PROBLEM:
//   Given a target distance, initial fuel, and a list
//   of fuel stations, determine the minimum number of
//   refueling stops required to reach the destination.
//
//   stations[i] = {position, fuel}
//
// EXAMPLE:
//   target = 100
//   startFuel = 10
//   stations = {{10,60},{20,30},{30,30},{60,40}}
//
//   Output → 2
//
// APPROACH (GREEDY + MAX HEAP):
//
//   Idea:
//   Always refuel from the station that provides the
//   maximum fuel among all reachable stations.
//
//   Steps:
//
//   1️⃣ Keep adding stations that are reachable
//       into a max heap.
//
//   2️⃣ Travel as far as possible with current fuel.
//
//   3️⃣ If fuel runs out before reaching target,
//       refuel from the station with the maximum fuel.
//
//   4️⃣ Repeat until destination reached.
//
// WHY MAX HEAP?
//   • It gives the station with the largest fuel
//     instantly.
//
// TIME COMPLEXITY:
//   O(n log n)
//
// SPACE COMPLEXITY:
//   O(n)
// =====================================================
int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {

    int stops = 0;     // number of refueling stops
    int dist = 0;      // current distance traveled
    int i = 0;         // station index
    int fuel = startFuel;

    // Max heap storing {fuel, position}
    priority_queue<pair<int, int>> pq;

    while (true) {

        // -------------------------------------------------
        // STEP 1: Push all reachable stations into heap
        // -------------------------------------------------
        while (i < stations.size()) {

            // Check if station is reachable
            if (stations[i][0] <= dist + fuel)
                pq.push({stations[i][1], stations[i][0]});
            else
                break;

            ++i;
        }

        // -------------------------------------------------
        // STEP 2: Travel with current fuel
        // -------------------------------------------------
        dist += fuel;
        fuel = 0;

        // -------------------------------------------------
        // STEP 3: Check if destination reached
        // -------------------------------------------------
        if (dist >= target)
            break;

        // -------------------------------------------------
        // STEP 4: If no station available → impossible
        // -------------------------------------------------
        if (pq.empty()) {
            stops = -1;
            break;
        }

        // -------------------------------------------------
        // STEP 5: Refuel from station with max fuel
        // -------------------------------------------------
        auto top = pq.top();
        pq.pop();

        // Update fuel and distance
        fuel = (dist - top.second) + top.first;
        dist = top.second;

        ++stops;
    }

    return stops;
}

// =====================================================
// MAIN FUNCTION
// -----------------------------------------------------
// PURPOSE:
//   Demonstrates minimum refueling stops problem
// =====================================================
int main() {

    /*
        Example:
        target = 100
        startFuel = 10

        stations =
        {10,60}
        {20,30}
        {30,30}
        {60,40}

        Output → 2
    */

    int target = 100;
    int startFuel = 10;

    vector<vector<int>> stations = {
        {10, 60},
        {20, 30},
        {30, 30},
        {60, 40}
    };

    int result = minRefuelStops(target, startFuel, stations);

    cout << "Minimum refuel stops: " << result << endl;

    return 0;
}