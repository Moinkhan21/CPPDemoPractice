#include <iostream>
using namespace std;

int fib(int n) {
    //Base case
    if(n == 1) {
        //First term
        return 0;
    }
    if(n == 2) {
        //Second term
        return 1;
    }

    //RR -> f(n) = f(n - 1) + f(n - 2)
    int ans = fib(n - 1) + fib(n - 2);
    return ans;
    
}

int main() {
    
    int n;
    cout << "Enter the term you want to see " << endl;
    cin >> n;

    int ans = fib(n);
    cout << "The " << n << "th term of the Fibonacci sequence is: " << ans << endl;

    return 0;
}