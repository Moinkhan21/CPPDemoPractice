#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {

    int stops = 0;
    int dist = 0;
    int i = 0;
    int fuel = startFuel;

    priority_queue<pair<int, int>> pq; // {fuel, position}

    while (true) {

        // Push all reachable stations
        while (i < stations.size()) {
            if (stations[i][0] <= dist + fuel)
                pq.push({stations[i][1], stations[i][0]});
            else
                break;
            ++i;
        }

        // Travel with current fuel
        dist += fuel;
        fuel = 0;

        // Destination reached
        if (dist >= target)
            break;

        // No station to refuel from
        if (pq.empty()) {
            stops = -1;
            break;
        }

        // Refuel from best station
        auto top = pq.top();   // ✅ FIXED
        pq.pop();

        fuel = (dist - top.second) + top.first;
        dist = top.second;

        ++stops;
    }

    return stops;
}

// ===============================
// MAIN FUNCTION
// ===============================
int main() {

    /*
        Example:
        target = 100
        startFuel = 10
        stations = {{10,60},{20,30},{30,30},{60,40}}

        Output: 2
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
