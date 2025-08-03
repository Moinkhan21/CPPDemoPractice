#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(char first, char second) {
    return first > second;
}

bool compare(int a, int b) {
    return a > b;
}

int main() {
    // Your code here

    string s = "babbar";
    sort(s.begin(), s.end(), cmp);

    cout << s << endl;
    // Output: abbbra

    vector<int> v = {1, 2, 3, 4, 5};
    sort(v.begin(), v.end(), compare);
    for(int num : v) {
        cout << num << " ";
    }

    // Output: 5 4 3 2 1
    return 0;
}