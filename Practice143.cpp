#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int maxSumArrayHelper(vector<int>& v, int start, int end) {
    if(start == end) return v[start];
    int maxLeftBorderSum = INT_MIN, maxRightBorderSum = INT_MIN;
    int mid = start + ((end - start) / 2);

    int maxLeftSum = maxSumArrayHelper(v, start, mid);
    int maxRightSum = maxSumArrayHelper(v, mid + 1, end);

    //Max Cross Border Sum
    int leftBorderSum = 0, rightBorderSum = 0;
    for(int i = mid; i >= start; i--) {
        leftBorderSum += v[i];
        if(leftBorderSum > maxLeftBorderSum) maxLeftBorderSum = leftBorderSum;
    }

    for(int i = mid + 1; i <= end; i++) {
        rightBorderSum += v[i];
        if(rightBorderSum > maxRightBorderSum) maxRightBorderSum = rightBorderSum;
    }
    int maxCrossBorderSum = maxLeftBorderSum + maxRightBorderSum;
    return max(maxLeftSum, max(maxRightSum, maxCrossBorderSum));
}

int maxSumArray(vector<int>& v) {
    return maxSumArrayHelper(v, 0, v.size() - 1);
}

int main() {
    vector<int> v = {-2,1,-3,4,-1,2,1,-5,4};
    cout << maxSumArray(v) << endl; // Output: 6
    return 0;
}