#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int main() {
    int n = 8;
    int m = 5;

    int arr[] = { 3, 4, 1, 9, 56, 7, 9, 12};

    //sort
    sort(arr, arr + n);

    //check differences in m-size window
    int i = 0;
    int j = m - 1;
    int diff = INT_MAX;
    while(j < n) {
        int newDiff = arr[j] - arr[i];
        diff = min(diff, newDiff);
        j++;
        i++;
    }
    cout << "Answer is: " << diff << endl;

    return 0;
}