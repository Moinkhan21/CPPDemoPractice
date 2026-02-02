#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int maxLen(vector<int>& A, int n) {

    unordered_map<int, int> map;
    int csum = 0;
    int ans = 0; // Max length of subarray with sum 0

    for (int i = 0; i < n; ++i) {

        csum += A[i];

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
        A = {15, -2, 2, -8, 1, 7, 10, 23}
        Output: 5
        Subarray: {-2, 2, -8, 1, 7}
    */

    vector<int> A = {15, -2, 2, -8, 1, 7, 10, 23};
    int n = A.size();

    cout << "Maximum length of subarray with sum 0: "
         << maxLen(A, n) << endl;

    return 0;
}
