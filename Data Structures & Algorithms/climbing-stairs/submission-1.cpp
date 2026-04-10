class Solution {
public:
    int solve(int n, vector<int>& dp){
        if(n == 0){
            return 1;
        }
        if(n < 0){
            return 0;
        }
        if(dp[n] != -1){
            return dp[n];
        }

        // no. of ways to reach the top will be sum of the no. of ways to 
        // reach the n-1th step + no. of ways to reach the n-2th step
        return dp[n] = solve(n-1, dp) + solve(n-2, dp);

    }
    int climbStairs(int n) {
        // top-down dp
        vector<int>dp(n+1, -1);
        int ans = solve(n, dp);
        return ans;
    }
};
