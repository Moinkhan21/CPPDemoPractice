#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isPossibleSolution(vector<int> cooksRanks, int nP, int mid) {
    int currP = 0; //initial cooked Prata count
    for(int i = 0; i < cooksRanks.size(); i++){
        int R = cooksRanks[i];
        int j = 1;
        int timeTaken = 0;

        while(true) {
            if(timeTaken + j * R <= mid) {
                currP++;
                timeTaken += j * R;
                j++;
            }
            else {
                break;
            }
        }
        if(currP >= nP) {
            return true; // Found a cook who can complete the required number of dishes within mid time
        }
    }
    return false; // Not enough cooks can complete the dishes within mid time
}

int minTimeToComplete(vector<int> cooksRanks, int nP) {
    int start = 0;
    int highestRank = *max_element(cooksRanks.begin(), cooksRanks.end());
    int end = highestRank * (nP * (nP + 1)) / 2; // Maximum time if the highest rank cook cooks all dishes
    int ans = -1;

    while(start <= end){
        int mid = start + (end - start)/2;

        if(isPossibleSolution(cooksRanks, nP, mid)) {
            ans = mid;
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }
    return ans;
}

int main() {
    int T;
    cin >> T;

    while(T--) {
        int nP, nC;
        cin >> nP >> nC;
        vector<int> cooksRanks;

        while(nC--) {
            int rank;
            cin >> rank;
            cooksRanks.push_back(rank);
        }

        cout << minTimeToComplete(cooksRanks, nP) << endl;
    }
}