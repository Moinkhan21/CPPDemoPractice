#include <iostream>
using namespace std;

int factorial(int n) {
    // if (n == 0) {
    //     return 1;
    // } else {
    //     return n * factorial(n - 1);
    // }

    cout << "Factorial is called for n: " << n << endl;

    //Base case
    if(n == 1) 
        return 1;
    

    int chotiProblemAns = factorial(n - 1);
    int badiProblemAns = n * chotiProblemAns;

    return badiProblemAns;

}

int main() {
    int n;
    cout << "Enter the value of n: " << endl;
    cin >> n;
    cout << "You entered: " << n << endl;

    int ans = factorial(n);
    cout << "Factorial of " << n << " is: " << ans << endl;

    return 0;
}