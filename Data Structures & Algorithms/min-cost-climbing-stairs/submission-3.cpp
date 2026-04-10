class Solution {
public:
    int solve(int n, vector<int>&cost, vector<int>&dp){
        // if we reach 0th floor then simply return cost of 0th floor
        if(n == 0){
            return cost[0];
        }
        // if we reach 1st floor then simply return cost of 1st floor
        if(n == 1){
            return cost[1];
        }
        if(dp[n] != -1){
            return dp[n];
        }
        // calculate min cost to reach n-1 th floor
        int res1 = solve(n-1, cost, dp);
        // calculate min cost to reach n-2 th floor
        int res2 = solve(n-2, cost, dp);
        
        // overall cost to reach nth floor is min of costs to reach n-1th
        // n-2th floor + cost of nth floor
        return dp[n] = min(res1, res2) + cost[n];

    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int>dp(n+1, -1);
        int ans =  min(solve(n-1, cost, dp), solve(n-2, cost, dp));
        // int ans = solve(n, cost, dp);
        return ans;
    }
};
