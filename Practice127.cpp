#include <iostream>
using namespace std;

// Recursive function to calculate the number of ways to roll 'n' dice with 'k' faces
// such that the total sum equals 'target'
int numRollsToTarget(int n, int k, int target){
    // --- Base cases ---
    
    if(target < 0) 
        return 0; // If target becomes negative, it's not possible → return 0 ways
    
    if(n == 0 && target == 0) 
        return 1; // If no dice left and target also reached → 1 valid way
    
    if(n == 0 && target != 0) 
        return 0; // If no dice left but target is not reached → 0 ways
    
    if(n != 0 && target == 0) 
        return 0; // If target is 0 but still dice are left → impossible case

    // --- Recursive case ---
    int ans = 0; // To count the number of ways
    
    // Try placing each face value (1 to k) on the current die
    for(int i = 1; i <= k; i++){
        // Reduce dice count by 1 and reduce target by 'i'
        ans = ans + numRollsToTarget(n - 1, k, target - i);
    }
    
    return ans; // Return total number of valid ways
}

int main() {
    int n, k, target;

    // Input values from user
    cout << "Enter number of dice: ";
    cin >> n;

    cout << "Enter number of faces on each die: ";
    cin >> k;

    cout << "Enter target sum: ";
    cin >> target;

    // Function call and output
    cout << "Number of ways to get the target sum: " 
         << numRollsToTarget(n, k, target) << endl;

    return 0;
}
