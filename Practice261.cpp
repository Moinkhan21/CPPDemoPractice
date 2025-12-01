#include <iostream>
#include <stack>
#include <vector>
#include <iomanip>
using namespace std;

// ============================================================================
// ✅ FUNCTION: getCollisionTimes()
// ----------------------------------------------------------------------------
// PURPOSE:
//   Given multiple cars on a single-lane road, each defined by {position, speed},
//   this function computes the time at which each car will **collide** with the
//   car directly ahead of it.
//
// DEFINITION:
//   - If car A (behind) is slower than or equal to car B (ahead), A will never
//     collide with B → collision time = -1.
//   - If car A is faster, compute time until they meet.
//   - However, if B collides with another car before A reaches it, A cannot
//     collide with B first, so the collision with B is ignored.
//
// APPROACH (Monotonic Stack):
//   🔹 Traverse from **right to left** (start from the last car).
//   🔹 Maintain a stack storing indices of potential "front" cars.
//   🔹 For each car i:
//        1️⃣ Pop cars that are slower or have earlier collisions.
//        2️⃣ Compute valid collision time only if it happens before the next car’s collision.
//        3️⃣ Store valid result in the answer vector.
// ============================================================================
vector<double> getCollisionTimes(vector<vector<int>>& cars) {

    int n = cars.size();
    vector<double> answer(n, -1.0);  // Default: no collision
    stack<int> st;                   // Stack stores indices of potential front cars

    // Traverse from the last car towards the first (right → left)
    for (int i = n - 1; i >= 0; i--) {

        // Clean the stack to find the correct car to collide with
        while (!st.empty()) {

            // If the current car is slower or same speed as the car in front,
            // it can never catch up → remove the car from sstack
            if (cars[i][1] <= cars[st.top()][1]) {
                st.pop();
                continue;
            }

            // Calculate the potential collision time between car i and car j
            int front = st.top();
            double colTime = (double)(cars[front][0] - cars[i][0]) /
                             (double)(cars[i][1] - cars[front][1]);

            // If front car will collide after this collision time or never collides
            if (answer[front] == -1 || colTime <= answer[front]) {
                // Valid collision time found
                answer[i] = colTime;
                break;
            }

            // Otherwise, front car collides before we reach it → pop it
            st.pop();
        }

        // Push current car index onto stack
        st.push(i);
    }

    return answer;
}

// ============================================================================
// ✅ MAIN FUNCTION — Testing getCollisionTimes()
// ----------------------------------------------------------------------------
// Input Format: cars = { {position, speed}, ... }
// Example:
//   Input:
//     cars = [ [1,2], [2,1], [4,3], [7,2] ]
//
//   Output:
//     Collision Times: [1.00000, -1.00000, 3.00000, -1.00000]
//
//   Explanation:
//     - Car 0 (pos=1, sp=2) collides with Car 1 (pos=2, sp=1) after 1 sec.
//     - Car 1 never catches anyone (slower).
//     - Car 2 collides with Car 3 after 3 sec.
//     - Car 3 has no car ahead → no collision.
// ============================================================================
int main() {

    vector<vector<int>> cars = {
        {1, 2},
        {2, 1},
        {4, 3},
        {7, 2}
    };

    vector<double> ans = getCollisionTimes(cars);

    cout << fixed << setprecision(5);
    cout << "Collision Times (seconds):\n";

    for (double x : ans) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
