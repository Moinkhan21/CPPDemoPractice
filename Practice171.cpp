#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> v = {3, 4, 1, 2};
    sort(v.begin(), v.end());
    for(auto i : v){
        cout << i << endl;
    }
    return 0;
}