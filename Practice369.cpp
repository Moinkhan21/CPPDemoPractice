#include <string>
#include <iostream>
#include <unordered_map>
using namespace std;

string isSubset(int a1[], int a2[], int n, int m) {

    unordered_map<int, int> map;
    string ans = "Yes";

    // Map hashing using a1
    for (int i = 0; i < n; i++) {
        map[a1[i]]++;
    }

    // Check whether all elements of a2 are present in a1
    for (int i = 0; i < m; ++i) {
        if (map.find(a2[i]) == map.end()) {
            ans = "No";
            break;
        }
        else {
            if (map[a2[i]] > 0) {
                map[a2[i]]--;
            }
            else {
                ans = "No";
                break;
            }
        }
    }
    return ans;
}

// ===============================
// MAIN FUNCTION
// ===============================
int main() {

    /*
        a1 = {11, 1, 13, 21, 3, 7}
        a2 = {11, 3, 7, 1}

        Output: Yes
    */

    int a1[] = {11, 1, 13, 21, 3, 7};
    int a2[] = {11, 3, 7, 1};

    int n = sizeof(a1) / sizeof(a1[0]);
    int m = sizeof(a2) / sizeof(a2[0]);

    cout << "Is a2 a subset of a1? "
         << isSubset(a1, a2, n, m) << endl;

    return 0;
}
