#include <iostream>
using namespace std;

/*
    Function: factorial
    -------------------
    Computes the factorial of a number n using recursion.

    Factorial definition:
        n! = n * (n-1) * (n-2) * ... * 2 * 1
        Example: 5! = 5 * 4 * 3 * 2 * 1 = 120

    Parameters:
        n : integer value for which factorial is to be calculated

    Returns:
        Factorial value of n
*/
int factorial(int n) {
    // Debug statement to track recursive calls
    cout << "Factorial is called for n: " << n << endl;

    // ✅ Base case:
    // Factorial of 1 is 1 (stopping condition of recursion)
    if(n == 1) 
        return 1;
    
    // ✅ Recursive case:
    // Step 1: Assume factorial(n-1) is already solved (smaller problem)
    int chotiProblemAns = factorial(n - 1);

    // Step 2: Multiply current number with result of smaller problem
    int badiProblemAns = n * chotiProblemAns;

    // Step 3: Return the final answer for this call
    return badiProblemAns;
}

int main() {
    int n;

    // Take input from user
    cout << "Enter the value of n: " << endl;
    cin >> n;
    cout << "You entered: " << n << endl;

    // Call factorial function
    int ans = factorial(n);

    // Print the final result
    cout << "Factorial of " << n << " is: " << ans << endl;

    return 0;
}
