#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
using namespace std;

#define ll long long

// =====================================================
// FUNCTION: print
// -----------------------------------------------------
// PURPOSE:
//   Utility function to print elements of a vector.
//
// USED FOR:
//   Debugging prefix and suffix arrays
// =====================================================
void print(vector<ll>& v) {
    for (auto i : v)
        cout << i << " ";
    cout << endl;
}

// =====================================================
// FUNCTION: minimumDifference
// -----------------------------------------------------
// PROBLEM:
//   Given an array of size 3n, remove n elements so that
//   the difference between the sum of the remaining
//   first n elements and last n elements is minimized.
//
// APPROACH:
//   Use two heaps:
//
//   1️⃣ Prefix Phase
//       - Maintain the smallest possible sum of n elements
//         from the LEFT side.
//       - Use a MAX HEAP to remove the largest element.
//
//   2️⃣ Suffix Phase
//       - Maintain the largest possible sum of n elements
//         from the RIGHT side.
//       - Use a MIN HEAP to remove the smallest element.
//
//   3️⃣ Compute minimum difference:
//
//       prefix[i] - suffix[i+1]
//
// WHY HEAPS?
//   Heaps allow efficient removal of the largest/smallest
//   elements while maintaining exactly n elements.
//
// TIME COMPLEXITY:
//   O(n log n)
//
// SPACE COMPLEXITY:
//   O(n)
// =====================================================
long long minimumDifference(vector<int>& nums) {

    int n = nums.size() / 3;

    // prefix[i]  → minimum sum of n elements from left up to i
    // suffix[i]  → maximum sum of n elements from right from i
    vector<ll> prefix(nums.size(), -1), suffix(nums.size(), -1);

    // =====================================================
    // PREFIX COMPUTATION
    // -----------------------------------------------------
    // Maintain smallest sum of n elements from left
    // =====================================================
    ll sum = 0;

    // Max Heap → used to remove largest element
    priority_queue<ll> maxHeap;

    for (int i = 0; i < nums.size(); ++i) {

        sum += nums[i];
        maxHeap.push(nums[i]);

        // If more than n elements → remove largest
        if (maxHeap.size() > n) {
            sum -= maxHeap.top();
            maxHeap.pop();
        }

        // Store prefix sum when heap has exactly n elements
        if (maxHeap.size() == n) {
            prefix[i] = sum;
        }
    }

    // =====================================================
    // SUFFIX COMPUTATION
    // -----------------------------------------------------
    // Maintain largest sum of n elements from right
    // =====================================================
    sum = 0;

    // Min Heap → used to remove smallest element
    priority_queue<ll, vector<ll>, greater<ll>> minHeap;

    for (int i = nums.size() - 1; i >= 0; --i) {

        sum += nums[i];
        minHeap.push(nums[i]);

        // If more than n elements → remove smallest
        if (minHeap.size() > n) {
            sum -= minHeap.top();
            minHeap.pop();
        }

        // Store suffix sum
        if (minHeap.size() == n) {
            suffix[i] = sum;
        }
    }

    // Debug printing
    print(prefix);
    print(suffix);

    // =====================================================
    // CALCULATE MINIMUM DIFFERENCE
    // -----------------------------------------------------
    // Split array into two parts and compute difference
    // =====================================================
    ll ans = LLONG_MAX;

    for (int i = n - 1; i < 2 * n; ++i) {
        ans = min(ans, prefix[i] - suffix[i + 1]);
    }

    return ans;
}

// =====================================================
// MAIN FUNCTION
// -----------------------------------------------------
// PURPOSE:
//   Demonstrates Minimum Difference problem
// =====================================================
int main() {

    /*
        Example:
        nums = [3,1,2,4,5,6]

        n = nums.size()/3 = 2

        We split array into:
        Left part → minimize sum
        Right part → maximize sum

        Goal → minimize difference
    */

    vector<int> nums = {3, 1, 2, 4, 5, 6};

    cout << "Minimum Difference = "
         << minimumDifference(nums) << endl;

    return 0;
}