#include <iostream>
using namespace std;

int findSqrt(int n) {
    int target = n;
    int s = 0;
    int e = n;
    int mid = s + (e - s) / 2;
    int ans = -1;

    while(s <= e) {
        
        if(mid * mid == target) {
            return mid;
        }
        if(mid * mid > target) {
            //Left search
            e = mid - 1;
            
        } else {
            //Ans store
            ans = mid;
            //Right search
            s = mid + 1;
        }
        mid = s + (e - s) / 2; // Recalculate mid after updating s or e
    }
    return ans; // Return the floor value of the square root
}

int main() {
    
    int n;
    cout << "Enter the number: ";
    cin >> n;

    int ans = findSqrt(n);
    cout << "Ans is: " << ans << endl;

    int precision;
    cout << "Enter the number of floating digits in precision: " << endl;
    cin >> precision;

    double step = 0.1;
    double finalAns = ans; // Start with the integer part of the square root
    for(int i = 0; i < precision; i++) {
        for(double j = finalAns; j * j < n; j += step) {
            finalAns = j;
        }
        step /= 10; // Reduce the step size for more precision
    }

    cout << "Final ans is: " << finalAns << endl;

    return 0; // Successful execution
}