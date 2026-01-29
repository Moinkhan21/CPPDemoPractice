#include <iostream>
#include <unordered_map>
using namespace std;

int findPairs(long long a[], long long n) {

    unordered_map<long long, bool> map;

    // Check pairs
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {

            long long sum = a[i] + a[j];

            if (map.find(sum) != map.end()) {
                return 1;   // pair found
            }
            else {
                map[sum] = true;
            }
        }
    }
    return 0;   // no such pair
}

// ===============================
// MAIN FUNCTION
// ===============================
int main() {

    /*
        Example:
        a = [3, 4, 7, 1, 2, 9, 8]
        Pairs:
        (3,4) -> 7
        (7,1) -> 8
        (3,8) -> 11
        (4,7) -> 11  ← same sum exists
    */

    long long a[] = {3, 4, 7, 1, 2, 9, 8};
    long long n = sizeof(a) / sizeof(a[0]);

    int result = findPairs(a, n);

    if (result)
        cout << "Pair with equal sum exists" << endl;
    else
        cout << "No such pair exists" << endl;

    return 0;
}
