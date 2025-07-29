#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
---------------------------------------------------------
Function: isPossibleSolution
Purpose : To check if it's possible to cook at least `nP`
          pratas (Indian pancakes) within `mid` minutes
          using the given cooks and their ranks.
Params  :
    - cooksRanks : vector containing ranks of each cook
    - nP         : number of pratas to cook
    - mid        : max time allowed to check feasibility
Returns :
    true  -> if it's possible to cook nP pratas in `mid` time
    false -> otherwise
---------------------------------------------------------
*/
bool isPossibleSolution(vector<int> cooksRanks, int nP, int mid) {
    int currP = 0; // Total pratas cooked so far

    for(int i = 0; i < cooksRanks.size(); i++) {
        int R = cooksRanks[i]; // Rank of the current cook
        int j = 1;              // j-th prata (1-based)
        int timeTaken = 0;      // Time used by the current cook

        // Try cooking as many pratas as possible within `mid` time
        while(true) {
            // Time required to cook the j-th prata by this cook is (j * R)
            if(timeTaken + j * R <= mid) {
                currP++;                 // One more prata cooked
                timeTaken += j * R;     // Accumulate time
                j++;                    // Move to the next prata
            } else {
                break; // Can't cook more pratas within `mid` time
            }
        }

        // If total cooked pratas meet or exceed the required amount
        if(currP >= nP) {
            return true; // This time (mid) is sufficient
        }
    }

    return false; // Not enough pratas cooked within `mid` time
}

/*
---------------------------------------------------------
Function: minTimeToComplete
Purpose : Uses binary search to find the minimum time needed
          to cook `nP` pratas using the given cooks.
Params  :
    - cooksRanks : vector of ranks of each cook
    - nP         : number of pratas to cook
Returns :
    Minimum possible time in which `nP` pratas can be cooked
---------------------------------------------------------
*/
int minTimeToComplete(vector<int> cooksRanks, int nP) {
    int start = 0;

    // Upper bound (max time) if the slowest cook cooks all pratas alone
    int highestRank = *max_element(cooksRanks.begin(), cooksRanks.end());
    int end = highestRank * (nP * (nP + 1)) / 2;

    int ans = -1; // Store the final answer (minimum time)

    // Binary search between start and end
    while(start <= end) {
        int mid = start + (end - start) / 2;

        // Check if mid time is sufficient
        if(isPossibleSolution(cooksRanks, nP, mid)) {
            ans = mid;       // Store current answer
            end = mid - 1;   // Try to find a smaller time
        } else {
            start = mid + 1; // Try with more time
        }
    }

    return ans; // Minimum time required
}

/*
---------------------------------------------------------
Main Function
Reads multiple test cases and computes the minimum time
to cook the required number of pratas using available cooks.
---------------------------------------------------------
*/
int main() {
    int T;
    cin >> T; // Number of test cases

    while(T--) {
        int nP, nC;
        cin >> nP >> nC; // Number of pratas and cooks

        vector<int> cooksRanks;

        // Input each cook's rank
        while(nC--) {
            int rank;
            cin >> rank;
            cooksRanks.push_back(rank);
        }

        // Output the result for this test case
        cout << minTimeToComplete(cooksRanks, nP) << endl;
    }

    return 0;
}
