#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void coutArrangementHelper(vector<int> &v, int &n, int &ans, int currNum){
    //Base Case
    if(currNum == n + 1){
        for(int i = 1; i <= n; i++) {
            cout << v[i] << " ";
        }
        cout << endl;
        ans++;
        return;
    }

    for(int i = 1; i <= n; ++i) {
        if(v[i] == 0 && (currNum % i == 0 || i % currNum == 0)) {
            v[i] = currNum;
            coutArrangementHelper(v, n, ans, currNum + 1);
            v[i] = 0; // Backtrack
        }
    }
}

int countArrangement(int n) {
    vector<int> v(n + 1, 0); // 1-indexed array to hold the arrangement
    int ans = 0;
    coutArrangementHelper(v, n, ans, 1);
    return ans;
}

int main(){
    int n = 3; // You can change this value to test with different n
    int result = countArrangement(n);
    cout << "Total arrangements for n = " << n << ": " << result << endl;
    return 0;
}