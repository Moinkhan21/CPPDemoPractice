#include<iostream>   // For input/output
#include<climits>    // For INT_MIN (to represent invalid/unreachable cases)
using namespace std;

/*
   Function: solve
   ----------------
   This function returns the maximum number of segments a rod of length `n`
   can be cut into, using only lengths `x`, `y`, or `z`.

   Parameters:
   - n: Current rod length
   - x, y, z: Allowed segment lengths

   Returns:
   - Maximum number of segments possible for rod length `n`
*/
int solve(int n, int x, int y, int z) {
    
    // Base case 1: If rod length becomes 0
    // It means we have successfully cut the rod exactly into pieces
    if(n == 0) {
        return 0;
    }

    // Base case 2: If rod length becomes negative
    // It means we tried to cut too much, which is invalid
    if(n < 0) {
        return INT_MIN;   // Use INT_MIN to represent an impossible case
    }

    // Recursive choice 1: Cut segment of length `x`
    int ans1 = solve(n - x, x, y, z) + 1;

    // Recursive choice 2: Cut segment of length `y`
    int ans2 = solve(n - y, x, y, z) + 1;

    // Recursive choice 3: Cut segment of length `z`
    int ans3 = solve(n - z, x, y, z) + 1;

    // Take the maximum of the three choices
    int ans = max(ans1, max(ans2, ans3));
    return ans;
}

int main(){

    int n = 7, x = 5, y = 2, z = 2; // Example: rod length 7, possible cuts 5, 2, 2

    // Call recursive function to get the maximum number of segments
    int ans = solve(n, x, y, z);

    // If answer is negative (means impossible to cut into exact pieces),
    // set answer to 0
    if(ans < 0)
         ans = 0;

    // Print the final result
    cout << "Answer is: " << ans << endl;

    return 0;
}
