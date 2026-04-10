class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        // bottom-up approach
        int n = cost.size();
        // dp[i] = minimum cost to reach step i
        vector<int> dp(n);
        // Base cases:
        // Cost to reach step 0 and step 1
        dp[0] = cost[0];
        dp[1] = cost[1];

        // Fill DP array
        for(int i = 2; i < n; i++){
            // To reach step i:
            // you can come from (i-1) or (i-2)
            // choose minimum cost path
            dp[i] = min(dp[i-1], dp[i-2]) + cost[i];
        }

        // Final answer:
        // You can reach the top from either last step (n-1)
        // or second last step (n-2)
        return min(dp[n-1], dp[n-2]);
    }
};