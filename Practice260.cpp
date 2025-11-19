#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

// ======================================================
// Class: Car
// Represents a car with position and speed
// ======================================================
class Car {
public:
    int pos, speed;
    Car(int p, int s) : pos(p), speed(s) {}
};

// ======================================================
// Custom comparator
// Sort cars based on position in descending order
// Cars closest to the target are processed first
// ======================================================
static bool myComp(Car &a, Car &b) {
    return a.pos > b.pos;
}

// ======================================================
// FUNCTION: carFleet
// ------------------------------------------------------
// PURPOSE:
//   Calculate how many "fleets" of cars will arrive at
//   the target. A fleet is formed when a faster car from
//   behind catches a slower car ahead and they move
//   together at the slower car’s speed.
//
// APPROACH:
//   1. Combine positions and speeds into a Car object.
//   2. Sort cars from closest to farthest from target.
//   3. Compute time for each car to reach target.
//   4. Use a STACK to determine when fleets merge:
//        - If current car takes *less or equal* time
//          than the fleet ahead → merges into same fleet.
//        - Else creates a new fleet.
//
// Time Complexity:  O(n log n)  (sorting dominates)
// Space Complexity: O(n)        (stack + car vector)
// ======================================================
int carFleet(int target, vector<int>& position, vector<int>& speed) {
    vector<Car> cars;

    // Step 1: Build car objects from inputs
    for (int i = 0; i < position.size(); i++) {
        cars.push_back(Car(position[i], speed[i]));
    }

    // Step 2: Sort cars by position descending
    sort(cars.begin(), cars.end(), myComp);

    // Stack stores arrival times of fleets
    stack<float> st;

    // Step 3: Process each car in sorted order
    for (auto &car : cars) {
        float time = (float)(target - car.pos) / car.speed;

        // Fleet merging condition:
        // If current car arrives earlier than or equal to fleet ahead,
        // it will catch up → does NOT form new fleet.
        if (!st.empty() && time <= st.top()) {
            continue;
        }

        // Otherwise, this car forms a NEW fleet
        st.push(time);
    }

    // Number of fleets = size of stack
    return st.size();
}

// ======================================================
// MAIN — Testing the carFleet function
// ======================================================
int main() {
    int target = 12;
    vector<int> position = {10, 8, 0, 5, 3};
    vector<int> speed    = {2, 4, 1, 1, 3};

    cout << "Number of car fleets: "
         << carFleet(target, position, speed)
         << endl;

    return 0;
}
