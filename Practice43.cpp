#include <iostream>
#include <vector>
using namespace std;

int solve(int dividend, int divisor) {
    int s = 0;
    int e = dividend;
    int ans = 1;

    int mid = s + (e - s) / 2;

    while(s <= e) {
        //Perfect solution
        if(mid*divisor == dividend) {
            return mid; // Return the quotient
        }
        //Not perfect solution, but close
        if(mid*divisor > dividend) {
            //Left
            e = mid - 1;
        }
        else {
            ans = mid; // Update ans to the closest quotient found so far
            //Right
            s = mid + 1;    
        }
        mid = s + (e - s) / 2; // Recalculate mid
    }
    return ans; // Return the closest quotient found
}

int main() {
    int dividend = 22;
    int divisor = 7;

    int ans = solve(dividend, divisor);
    cout << "Ans is " << ans << endl;

    return 0;
}