#include <iostream>
using namespace std;

int numRollsToTarget(int n, int k, int target){
    //Base case
    if(target < 0) return 0;
    if(n == 0 && target == 0) return 1;
    if(n == 0 && target != 0) return 0;
    if(n != 0 && target == 0) return 0;

    int ans = 0;
    for(int i = 1; i <= k; i++){
        ans = ans + numRollsToTarget(n - 1, k, target - i);
    }
    return ans;
}

int main() {

    int n, k, target;
    cout << "Enter number of dice: ";
    cin >> n;
    cout << "Enter number of faces on each die: ";
    cin >> k;
    cout << "Enter target sum: ";
    cin >> target;

    cout << "Number of ways to get the target sum: " << numRollsToTarget(n, k, target) << endl;
    return 0;
    
}