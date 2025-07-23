class Solution {
    public:

    bool isPossibleSolution(vector<int>&stalls, int k, int mid) {
        
        //Can we place k cows, with at least mid distance between cows.
        int c = 1; // Count of cows placed

        int pos = stalls[0]; // First stall position
        for(int i = 1; i < stalls.size(); i++) {
            if(stalls[i] - pos >= mid){
                c++;
                pos = stalls[i]; // one more cow has been placed
            }
            if(c == k) {
                return true; // Enough cows placed with at least mid distance
            }
        }
        return false; // Not enough cows placed
    }

    int solve(int n, int k, vector<int> &stalls) {
        sort(stalls.begin(), stalls.end()); // Sort the stalls
        int start = 0;
        int end = stalla[stalls.size() - 1] - stalls[0]; // Maximum distance

        int ans = -1;

        while(start <= end) {
            int mid = start + (end - start) / 2;

            if (isPossibleSolution(stalls, n, k, mid)) {
                ans = mid; // Found a possible solution, try for a better one
                end = mid - 1; // Look for a smaller maximum distance
            } else {
                start = mid + 1; // Increase the minimum distance limit
            }
        }
        return ans;
    }
};