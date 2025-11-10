#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
    vector<int> v;
    v.push_back(2);
    v.push_back(1);
    v.push_back(4);
    v.push_back(3);

    stack<int> s;
    s.push(-1);

    vector<int> ans(v.size());
    for(int i = v.size() - 1; i >= 0; i--) {
        int curr = v[i];

        //Apka answer stack me se dhundh ke laao
        while(s.top() >= curr) {
            s.pop();
        }

        //Chotta element mil chuka he -> 
        ans[i] = s.top();

        //Push kar do current element ko
        s.push(curr);
    }

    cout << "Printing..." << endl;
    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }

}