#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// =====================================================
// CLASS: mycomp
// -----------------------------------------------------
// PURPOSE:
//   Custom comparator for priority_queue to build
//   a MIN HEAP based on distance from origin.
//
// WHY CUSTOM COMPARATOR?
//   • priority_queue in C++ is MAX heap by default
//   • We need the point with SMALLEST distance first
//
// DISTANCE FORMULA (No sqrt needed):
//   distance² = x² + y²
//   (sqrt is avoided for efficiency)
//
// RULE:
//   • Point with smaller distance gets higher priority
// =====================================================
class mycomp {
public:
    bool operator()(pair<int, int>& a, pair<int, int>& b) {

        // Squared distance of point A from origin
        int distA = a.first * a.first +
                    a.second * a.second;

        // Squared distance of point B from origin
        int distB = b.first * b.first +
                    b.second * b.second;

        // Return true if A should come AFTER B
        // (creates MIN heap based on distance)
        return distA > distB;
    }
};

// =====================================================
// FUNCTION: kClosest
// -----------------------------------------------------
// PURPOSE:
//   Find the K points closest to the origin (0, 0).
//
// INPUT:
//   • points → list of 2D points [x, y]
//   • k      → number of closest points required
//
// OUTPUT:
//   • Vector containing K closest points
//
// APPROACH (MIN HEAP):
//   1️⃣ Push all points into a min heap
//   2️⃣ Heap is ordered by distance from origin
//   3️⃣ Pop top K elements (closest points)
//
// WHY MIN HEAP?
//   • Always gives nearest point in O(log N)
//   • Simple and intuitive solution
//
// TIME COMPLEXITY:
//   • Heap insertion: O(N log N)
//   • Extract k points: O(k log N)
//
// SPACE COMPLEXITY:
//   • O(N) for heap storage
// =====================================================
vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

    // Stores final answer
    vector<vector<int>> ans;

    // Min heap storing (x, y) pairs
    priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        mycomp
    > pq;

    // -------------------------------------------------
    // Step 1: Push all points into the heap
    // -------------------------------------------------
    for (auto p : points) {
        pq.push({p[0], p[1]});
    }

    // -------------------------------------------------
    // Step 2: Extract K closest points
    // -------------------------------------------------
    while (!pq.empty() && k--) {

        // Get closest point (COPY, not reference)
        auto top = pq.top();
        pq.pop();

        // Add to answer
        ans.push_back({top.first, top.second});
    }

    return ans;
}

// =====================================================
// MAIN FUNCTION (TEST CASE)
// =====================================================
int main() {

    /*
        Input:
        Points = [[1,3], [-2,2], [5,8], [0,1]]
        k = 2

        Distances from origin:
        (1,3)  → 10
        (-2,2) → 8
        (5,8)  → 89
        (0,1)  → 1

        Closest points:
        [-2,2], [0,1]
    */

    vector<vector<int>> points = {
        {1, 3},
        {-2, 2},
        {5, 8},
        {0, 1}
    };

    int k = 2;

    vector<vector<int>> result = kClosest(points, k);

    cout << "K Closest Points to Origin:\n";
    for (auto &p : result) {
        cout << "[" << p[0] << ", " << p[1] << "]\n";
    }

    return 0;
}
