#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int maxLen(vector<int>& A, int n) {

    unordered_map<int, int> map;
    int csum = 0;
    int ans = 0; // Max length of subarray with equal 0s and 1s

    for (int i = 0; i < n; ++i) {

        int val = (A[i] == 0 ? -1 : 1);
        csum += val;

        if (csum == 0) {
            ans = max(ans, i + 1);
        }
        else if (map.find(csum) == map.end()) {
            map[csum] = i;
        }
        else {
            ans = max(ans, i - map[csum]);
        }
    }
    return ans;
}

// ===============================
// MAIN FUNCTION
// ===============================
int main() {

    /*
        Example:
        A = {0, 1, 0, 1, 0, 1, 1}
        Output: 6
    */

    vector<int> A = {0, 1, 0, 1, 0, 1, 1};
    int n = A.size();

    cout << "Maximum length of subarray with equal 0s and 1s: "
         << maxLen(A, n) << endl;

    return 0;
}
