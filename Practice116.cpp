#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int solve(vector<int>& arr, int i, int sum, int &maxi){
    //Base case
    if(i >= arr.size()) {
        //Maxi update
        maxi = max(sum, maxi);
        return maxi;
    }

    //Include
    solve(arr, i + 2, sum + arr[i], maxi);
    //exclude
    solve(arr, i + 1, sum, maxi);
}

int main() {
    vector<int> arr{2, 1, 4, 9};
    int sum = 0;
    int maxi = INT_MIN;

    int i = 0;
    solve(arr, i, sum, maxi);
    
    cout << "Maximum sum of non-adjacent elements is: " << maxi << endl;
    return 0;
}