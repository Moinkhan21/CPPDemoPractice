#include <iostream>   // For standard input/output
using namespace std;

// Function to calculate the number of ways to climb 'n' stairs
int climbStairs(int n) {
    // Base cases: when there are 0 or 1 stairs
    // If n == 0: only 1 way (stand still, do nothing)
    // If n == 1: only 1 way (take a single step)
    if (n == 0 || n == 1) {
        return 1;
    }

    // Recursive case:
    // From step 'n', you can reach it either:
    //  - by taking 1 step from (n-1)
    //  - by taking 2 steps from (n-2)
    //
    // So total ways to reach step 'n' =
    // ways to reach (n-1) + ways to reach (n-2)
    int ans = climbStairs(n - 1) + climbStairs(n - 2);

    // Return the computed answer for this 'n'
    return ans;
}

int main() {
    int n;

    // Ask the user for the number of stairs
    cout << "Enter the value of n: ";
    cin >> n;

    // Call the recursive function
    int ans = climbStairs(n);

    // Print the result
    cout << "Answer is : " << ans << endl;

    return 0; // End of program
}
