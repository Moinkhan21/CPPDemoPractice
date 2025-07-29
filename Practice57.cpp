#include <iostream>
#include <vector>
#include <algorithm>  // For using max_element
using namespace std;

/*
----------------------------------------------------------------------------------------
Function: isPossibleSolution
Purpose : To check if it's possible to collect at least 'm' units of wood by cutting 
          the trees at a given saw blade height 'mid'.
Params  :
    - trees: Vector containing heights of the trees
    - m    : Required amount of wood
    - mid  : Height at which saw blade is set
Returns :
    - true if we can collect at least 'm' units of wood at height 'mid'
    - false otherwise
----------------------------------------------------------------------------------------
*/
bool isPossibleSolution(vector<long long int> trees, long long int m, long long int mid){
    long long int woodCollected = 0;

    // Loop through all trees and calculate the total wood collected
    for(int i = 0; i < trees.size(); i++){
        if(trees[i] > mid){
            // Only collect wood from the part above the saw blade height
            woodCollected += (trees[i] - mid);
        }
    }

    // Check if the total collected wood is at least 'm'
    return woodCollected >= m;
}

/*
----------------------------------------------------------------------------------------
Function: maxSawBladeHeight
Purpose : To find the maximum saw blade height such that we still collect 
          at least 'm' units of wood using binary search.
Params  :
    - trees: Vector of tree heights
    - m    : Required amount of wood
Returns :
    - The maximum height at which the saw blade can be set while still collecting >= m wood
----------------------------------------------------------------------------------------
*/
long long int maxSawBladeHeight(vector<long long int> trees, long long int m){
    long long int start = 0, end, ans = -1;

    // The maximum blade height can be the height of the tallest tree
    end = *max_element(trees.begin(), trees.end());

    // Binary Search Loop
    while(start <= end){
        long long int mid = start + (end - start) / 2;

        // If we can collect enough wood at this height, try higher height
        if(isPossibleSolution(trees, m, mid)){
            ans = mid;         // Store current valid height
            start = mid + 1;   // Try a higher blade height
        }
        else{
            end = mid - 1;     // Try a lower blade height
        }
    }

    return ans;  // Maximum valid height
}

/*
----------------------------------------------------------------------------------------
Main Function:
- Reads input: number of trees and required wood
- Collects heights of trees into a vector
- Calls maxSawBladeHeight to get the result
- Prints the final answer
----------------------------------------------------------------------------------------
*/
int main() {
    long long int n, m;
    cin >> n >> m;  // Input number of trees and required wood

    vector<long long int> trees;

    // Input tree heights
    while(n--) {
        long long int height;
        cin >> height;
        trees.push_back(height);
    }

    // Output the maximum saw blade height that satisfies the wood requirement
    cout << maxSawBladeHeight(trees, m) << endl;

    return 0;
}
