#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
using namespace std;

#define ll long long

void print(vector<ll>& v) {
    for (auto i : v)
        cout << i << " ";
    cout << endl;
}

long long minimumDifference(vector<int>& nums) {

    int n = nums.size() / 3;
    vector<ll> prefix(nums.size(), -1), suffix(nums.size(), -1);

    // ===============================
    // Prefix: minimum sum of n elements from left
    // ===============================
    ll sum = 0;
    priority_queue<ll> maxHeap;

    for (int i = 0; i < nums.size(); ++i) {
        sum += nums[i];
        maxHeap.push(nums[i]);

        if (maxHeap.size() > n) {
            sum -= maxHeap.top();
            maxHeap.pop();
        }
        if (maxHeap.size() == n) {
            prefix[i] = sum;
        }
    }

    // ===============================
    // Suffix: maximum sum of n elements from right
    // ===============================
    sum = 0;
    priority_queue<ll, vector<ll>, greater<ll>> minHeap;

    for (int i = nums.size() - 1; i >= 0; --i) {
        sum += nums[i];
        minHeap.push(nums[i]);

        if (minHeap.size() > n) {
            sum -= minHeap.top();
            minHeap.pop();
        }
        if (minHeap.size() == n) {
            suffix[i] = sum;   // ✅ FIXED
        }
    }

    print(prefix);
    print(suffix);

    // ===============================
    // Calculate answer
    // ===============================
    ll ans = LLONG_MAX;
    for (int i = n - 1; i < 2 * n; ++i) {
        ans = min(ans, prefix[i] - suffix[i + 1]);
    }
    return ans;
}

// ===============================
// MAIN FUNCTION
// ===============================
int main() {

    /*
        Example:
        nums = [3,1,2,4,5,6]
        n = 2

        Expected Output:
        Minimum Difference
    */

    vector<int> nums = {3, 1, 2, 4, 5, 6};

    cout << "Minimum Difference = "
         << minimumDifference(nums) << endl;

    return 0;
}
