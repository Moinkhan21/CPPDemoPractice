#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Comparator for sorting by departure time
bool cmp(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

int solve(int n, int arr[], int dept[]) {

    if (n == 0) return 0;

    vector<pair<int, int>> data;

    // Store arrival and departure
    for (int i = 0; i < n; i++) {
        data.push_back({arr[i], dept[i]});
    }

    // Sort by departure time
    sort(data.begin(), data.end(), cmp);

    int cnt = 1;

    // First selected train
    cout << data[0].first << ", " << data[0].second << endl;

    int lastDept = data[0].second;

    for (int i = 1; i < n; i++) {
        if (data[i].first >= lastDept) {

            cnt++;
            lastDept = data[i].second;

            // Print selected interval
            cout << data[i].first << ", " << data[i].second << endl;
        }
    }

    return cnt;
}

// ===============================
// MAIN FUNCTION
// ===============================
int main() {

    int n = 4;

    int arr[] = {5, 8, 2, 4};
    int dept[] = {7, 11, 6, 5};

    int ans = solve(n, arr, dept);

    cout << "Answer is: " << ans << endl;

    return 0;
}
