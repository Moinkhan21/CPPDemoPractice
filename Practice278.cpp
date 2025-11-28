#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

// ====================================================================
// FUNCTION: canAssign
// --------------------------------------------------------------------
// PURPOSE:
//   Check whether it is possible to assign exactly 'mid' hardest tasks
//   to 'mid' strongest workers, using at most 'pills' pills where each
//   pill increases worker strength by 'strength'.
//
// PARAMETERS:
//   mid      → number of tasks we are trying to assign
//   workers  → sorted list of worker strengths
//   tasks    → sorted list of task requirements
//   pills    → number of available strength pills
//   strength → additional strength each pill provides
//
// APPROACH:
//   • Consider only the strongest 'mid' workers.
//   • Assign tasks starting from hardest → easiest.
//   • For each task:
//        1) Try strongest worker → if strong enough, assign.
//        2) Else try weakest worker WITH pill → if possible, assign.
//        3) If neither works → return false.
//
// RETURN:
//   true  → if all 'mid' tasks can be assigned
//   false → otherwise
// ====================================================================
bool canAssign(int mid, vector<int>& workers, vector<int>& tasks, int pills, int strength) {

    // Use multiset to store strongest 'mid' workers (auto-sorted)
    multiset<int> usable(workers.end() - mid, workers.end());

    // Loop over the 'mid' hardest tasks (tasks already sorted ascending)
    // tasks[mid-1] = hardest among the first 'mid'
    for (int i = mid - 1; i >= 0; i--) {

        int task = tasks[i];

        // ================================================================
        // OPTION 1: Assign strongest available worker WITHOUT pill
        // ================================================================
        auto itStrong = --usable.end();      // strongest worker available
        if (*itStrong >= task) {
            usable.erase(itStrong);          // worker can do task
            continue;
        }

        // Strongest worker cannot do task → need pill support
        // If no pills left, assignment fails
        if (pills <= 0) return false;

        // ================================================================
        // OPTION 2: Assign weakest worker WITH pill boost
        // ================================================================
        // We need worker strength + strength >= task
        // → worker >= task - strength
        auto itWeak = usable.lower_bound(task - strength);

        if (itWeak == usable.end()) {
            // No worker strong enough even WITH a pill
            return false;
        }

        // Assign this weakest usable worker with pill
        usable.erase(itWeak);
        pills--;  // pill used
    }

    // All 'mid' tasks assigned successfully
    return true;
}

// ====================================================================
// FUNCTION: maxTaskAssign
// --------------------------------------------------------------------
// PURPOSE:
//   Compute the maximum number of tasks assignable using binary search.
//
// APPROACH:
//   • Sort tasks and workers.
//   • Binary-search over number of tasks (mid).
//   • For every mid, check feasibility using canAssign().
//   • Return the highest feasible mid.
//
// TIME COMPLEXITY:
//   O(n log n + (n log n) log n) due to binary search + multiset ops.
//
// RETURN:
//   Maximum number of tasks that can be assigned.
// ====================================================================
int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {

    // Sort tasks (easiest → hardest) and workers (weakest → strongest)
    sort(tasks.begin(), tasks.end());
    sort(workers.begin(), workers.end());

    int left = 0;
    int right = min((int)tasks.size(), (int)workers.size()); // max possible tasks
    int ans = 0;

    // Binary search the maximum number of feasible tasks
    while (left <= right) {
        int mid = left + (right - left) / 2;

        // If 'mid' tasks are possible, try to do more
        if (canAssign(mid, workers, tasks, pills, strength)) {
            ans = mid;
            left = mid + 1;
        } 
        else {
            // Otherwise try fewer tasks
            right = mid - 1;
        }
    }

    return ans;
}

// ====================================================================
// MAIN — TESTING LOGIC
// ====================================================================
int main() {

    // Example:
    // tasks  = {3, 2, 1}  → hardest = 3
    // workers= {3, 3, 1}
    // pills  = 1
    // strength = 1 (pill adds +1)
    vector<int> tasks = {3,2,1};
    vector<int> workers = {3,3,1};
    int pills = 1;
    int strength = 1;

    cout << "Maximum tasks assignable = "
         << maxTaskAssign(tasks, workers, pills, strength) 
         << endl;

    return 0;
}
