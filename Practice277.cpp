#include <iostream>
#include <deque>
#include <vector>
using namespace std;

int sumOfMinMaxAllWindowOfSizek(vector<int>& nums, int k) {
    deque<int> dq1, dq2;
    int ans = 0;

    //First window of k size
    for(int i = 0; i < k; i++) {

        //Chote element remove krdo
        while(!dq1.empty() && nums[i] >= nums[dq1.back()]) {
            dq1.pop_back();
        }

        //Bade element remove krdo
        while(!dq2.empty() && nums[i] <= nums[dq2.back()]) {
            dq2.pop_back();
        }

        //Inserting index, so that we can checkout of window element
        dq1.push_back(i);
        dq2.push_back(i);
    }

    ans += nums[dq1.front()] + nums[dq2.front()];

    //Remaining windows ko process
    for(int i = k; i < nums.size(); i++) {
        //Out of window element ko remove krdia
        if(!dq1.empty() && i - dq1.front() >= k) {
            dq1.pop_front();
        }

        if(!dq2.empty() && i - dq2.front() >= k) {
            dq2.pop_front();
        }

        //Ab ferse current element k liye chhote element ko remove krna he
        while(!dq1.empty() && nums[i] >= nums[dq1.back()]) {
            dq1.pop_back();
        }
        while(!dq2.empty() && nums[i] <= nums[dq2.back()]) {
            dq2.pop_back();
        }

        //Inserting index, so that we can checkout of window element
        dq1.push_back(i);
        dq2.push_back(i);

        //Current window ko answer store krna he
        ans += nums[dq1.front()] + nums[dq2.front()];
    }

    return ans;
}

int main() {

    vector<int> v{2, 5, -1, 7, -3, -1, -2};
    int k = 4;
    cout << sumOfMinMaxAllWindowOfSizek(v, k);

    return 0;
}