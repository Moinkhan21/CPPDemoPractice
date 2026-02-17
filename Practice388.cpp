#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    deque<int> dq;

    //We will store indexes in deque
    vector<int> ans;

    //Process frist k size window
    for(int i = 0; i < k; i++) {
        while(!dq.empty() && nums[dq.back()] < nums[i])
            dq.pop_back();

        //Insert element
        dq.push_back(i);
    }

    //Ans store karlo for 1st window
    ans.push_back(nums[dq.front()]);

    //Remainin windows
    for(int i = k; i < nums.size(); i++) {

        //Removal
        if(!dq.empty() && i - k >= dq.front())
            dq.pop_front();

        //Additional
        while(!dq.empty() && nums[dq.back()] < nums[i])
            dq.pop_back();
        //Insert element
        dq.push_back(i);

        //Ans store
        ans.push_back(nums[dq.front()]);
    }
    return ans;
}