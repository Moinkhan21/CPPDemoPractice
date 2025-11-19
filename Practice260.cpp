// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <stack>
// using namespace std;

// class Car{
//     public:
//         int pos, speed;
//         Car(int p, int s): pos(p), speed(s) {};
// };

// static bool myComp(Car&a, Car&b) {
//     return a.pos < b.pos;
// }


//     int carFleet(int target, vector <int>& position, vector<int>& speed) {
//         vector<Car> cars;
//         for(int i = 0; i < position.size(); i++) {
//             Car car(position[i], speed[i]);
//             cars.push_back(car);
//         }
//         sort(cars.begin(), cars.end(), myComp);

//         stack<float> st;
//         for(auto car:cars) {
//             float time = (target-car.pos)/((float) car.speed);
//             while(!st.empty() && time >= st.top()){
//                 st.pop();
//             }
//             st.push(time);
//         }
//         return st.size();
//     }

// int main() {
//     return 0;
// }

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

class Car {
public:
    int pos, speed;
    Car(int p, int s) : pos(p), speed(s) {}
};

// Sort cars by position descending (closest to target first)
static bool myComp(Car &a, Car &b) {
    return a.pos > b.pos;
}

// ======================================================
// FUNCTION: carFleet()
// ======================================================
int carFleet(int target, vector<int>& position, vector<int>& speed) {
    vector<Car> cars;

    // Build car objects
    for (int i = 0; i < position.size(); i++) {
        cars.push_back(Car(position[i], speed[i]));
    }

    // Sort by position descending
    sort(cars.begin(), cars.end(), myComp);

    stack<float> st;  // stack stores arrival times

    for (auto &car : cars) {
        // Compute time to reach the target
        float time = (float)(target - car.pos) / car.speed;

        // Fleet merging logic:
        // If current car takes less time than the car ahead,
        // it will catch up → do NOT push (same fleet)
        if (!st.empty() && time <= st.top()) {
            continue;   // merges with fleet ahead
        }

        // Otherwise, this car forms a new fleet
        st.push(time);
    }

    return st.size();
}

// ======================================================
// MAIN (Testing)
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
