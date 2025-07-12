#include <iostream>
#include <vector>
using namespace std;

int solve(int dividend, int divisor) {
    int s = 0;
    int e = abs(dividend);
    int ans = 1;

    int mid = s + (e - s) / 2;

    while(s <= e) {
        //Perfect solution
        if(abs(mid*divisor) == abs(dividend)) {
            return mid; // Return the quotient
        }
        //Not perfect solution, but close
        if(abs(mid*divisor) > abs(dividend)) {
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
    if((divisor < 0 && dividend < 0) || (divisor > 0 && dividend > 0)) {
        return ans; // Return the quotient
    }else {
        return -ans; // Return the negative quotient
    }
}

int main() {
    int dividend = 22;
    int divisor = -7;

    int ans = solve(dividend, divisor);
    cout << "Ans is " << ans << endl;

    return 0;
}