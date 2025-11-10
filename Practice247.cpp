#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> prevSmallerElement(vector<int>& input) {
    stack<int> s;
    s.push(-1);

    vector<int> ans(input.size());

    //left to right -> prev smaller
    for(int i = 0; i < input.size(); i++) {
        int curr = input[i];

        //Apka answer stack me
        while(s.top() >= curr) {
            s.pop();
        }

        //Chotta element mil chuka he -> ans store
        ans[i] = s.top();

        //Push krdo curr element ko
        s.push(curr);
    }
    return ans;

}

vector<int> nextSmallerElement(vector<int> &input) {
    stack<int> s;
    s.push(-1);

    vector<int> ans(input.size());
    for(int i = input.size() - 1; i >= 0; i--) {
        int curr = input[i];

        //Apka answer stack me se dhundh ke laao
        while(s.top() >= curr) {
            s.pop();
        }

        //Chotta element mil chuka he -> 
        ans[i] = s.top();

        //Push kar do current element ko
        s.push(curr);
    }
    return ans;
}

int main() {
    vector<int> input;
    input.push_back(2);
    input.push_back(1);
    input.push_back(4);
    input.push_back(3);

    vector<int> ans1 = nextSmallerElement(input);
    cout << "Printing ans1..." << endl;
    for(int i = 0; i < input.size(); i++) {
        cout << ans1[i] << " ";
    }
    cout << endl;

    vector<int> ans2 = prevSmallerElement(input);
    cout << "Printing ans2..." << endl;
    for(int i = 0; i < input.size(); i++) {
        cout << ans2[i] << " ";
    }
    cout << endl;
}