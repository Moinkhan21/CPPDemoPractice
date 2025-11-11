#include <iostream>
#include <stack>
#include <vector>
#include <climits>
using namespace std;

vector<int> prevSmallerElement(vector<int>& input) {
    stack<int> s;
    s.push(-1);

    vector<int> ans(input.size());

    //left to right -> prev smaller
    for(int i = 0; i < input.size(); i++) {
        int curr = input[i];

        //Apka answer stack me
        while(s.top() != -1 && input[s.top()] >= curr) {
            s.pop();
        }

        //Chotta element mil chuka he -> ans store
        ans[i] = s.top();

        //Push krdo curr element ka index
        s.push(i);
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
        while(s.top() != -1 && input[s.top()] >= curr) {
            s.pop();
        }

        //Chotta element mil chuka he -> 
        ans[i] = s.top();

        //Push kar do current element ko
        s.push(i);
    }
    return ans;
}

int gerRectangularAreaHistogram(vector<int> &height) {

    //Step1: prevSmaller output
    vector<int> prev = prevSmallerElement(height);

    //Step2: nextSmaller output
    vector<int> next = nextSmallerElement(height);

    int maxArea = INT_MIN;
    int size = height.size();

    for(int i = 0; i < height.size(); i++) {
        int length = height[i];

        if(next[i] == -1) {
            next[i] = size;
        }

        int width = next[i] - prev[i] - 1;

        int area = length * width;
        maxArea = max(maxArea, area);
    }

    return maxArea;
}

int main() {

    vector<int> v;
    v.push_back(2);
    v.push_back(1);
    v.push_back(5);
    v.push_back(6);
    v.push_back(2);
    v.push_back(3);

    cout << "Ans is: " << gerRectangularAreaHistogram(v) << endl;
    
    return 0;
}
