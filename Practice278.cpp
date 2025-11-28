#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

// ====================================================================
// Helper to check if we can assign 'mid' tasks
// ====================================================================
bool canAssign(int mid, vector<int>& workers, vector<int>& tasks, int pills, int strength) {

    multiset<int> usable(workers.end() - mid, workers.end());  // strongest 'mid' workers

    for (int i = mid - 1; i >= 0; i--) {  // loop over hardest tasks first

        int task = tasks[i];

        // Step 1: Try strongest worker without pill
        auto itStrong = --usable.end();
        if (*itStrong >= task) {
            usable.erase(itStrong);
            continue;
        }

        // Step 2: Try using pill on weakest worker
        if (pills <= 0) return false;

        auto itWeak = usable.lower_bound(task - strength);
        if (itWeak == usable.end()) return false;  // even pill cannot help

        usable.erase(itWeak);
        pills--;
    }

    return true;
}

// ====================================================================
// Main function to compute max tasks
// ====================================================================
int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {

    sort(tasks.begin(), tasks.end());
    sort(workers.begin(), workers.end());

    int left = 0, right = min((int)tasks.size(), (int)workers.size());
    int ans = 0;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (canAssign(mid, workers, tasks, pills, strength)) {
            ans = mid;        // can assign mid tasks
            left = mid + 1;   // try for more
        } else {
            right = mid - 1;  // try fewer tasks
        }
    }

    return ans;
}

// ====================================================================
// MAIN — TESTING
// ====================================================================
int main() {
    vector<int> tasks = {3,2,1};
    vector<int> workers = {3,3,1};
    int pills = 1;
    int strength = 1;

    cout << "Maximum tasks assignable = "
         << maxTaskAssign(tasks, workers, pills, strength) << endl;

    return 0;
}
