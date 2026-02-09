int BottomUpSolve(int n) {
    
    //Step 1 : create dp array
    vector<int> dp(n + 1, -1);

    //Step 2 : Observe base case in above solution
    dp[0] = 0;
    if(n == 0)
        return dp[0];

    dp[1] = 1;
    if(n == 1)
        return dp[1];

    //Step 3 : Iterative approach
    for(int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];

}