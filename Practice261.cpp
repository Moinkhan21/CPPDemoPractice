#include <iostream>
#include <stack>
#include <vector>
#include <iomanip>
using namespace std;

// ================================================================
// FUNCTION: getCollisionTimes
// ================================================================
vector<double> getCollisionTimes(vector<vector<int>>& cars) {

    int n = cars.size();
    vector<double> answer(n, -1.0);
    stack<int> st;  // Stack stores indices of cars ahead

    // Process from right → left
    for (int i = n - 1; i >= 0; i--) {

        while (!st.empty()) {

            // If car i is slower or same speed as car j in front => no collision
            if (cars[i][1] <= cars[st.top()][1]) {
                st.pop();
                continue;
            }

            // Compute collision time with j
            int front = st.top();
            double colTime = (double)(cars[front][0] - cars[i][0]) /
                             (double)(cars[i][1] - cars[front][1]);

            // If front car collides *after* this collision, this is valid
            if (answer[front] == -1 || colTime <= answer[front]) {
                answer[i] = colTime;
                break;
            }

            // Otherwise front car collides sooner → invalid
            st.pop();
        }

        st.push(i);
    }

    return answer;
}

// ================================================================
// MAIN — Test the code
// ================================================================
int main() {

    vector<vector<int>> cars = {
        {1, 2},
        {2, 1},
        {4, 3},
        {7, 2}
    };

    vector<double> ans = getCollisionTimes(cars);

    cout << fixed << setprecision(5);
    cout << "Collision Times:\n";

    for (double x : ans) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
