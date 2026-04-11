class Solution {
public:
    int solve(vector<int>& coins, int amount, vector<int>& dp) {
        // Base case: 0 amount needs 0 coins
        dp[0] = 0;

        // Build solution from 1 to amount
        for(int i = 1; i <= amount; i++){
            // Try every coin
            for(int coin : coins){
                // If coin can be used and previous state is valid
                if(i - coin >= 0 && dp[i-coin] != INT_MAX){
                    // Update minimum coins for amount i
                    dp[i] = min(dp[i], 1 + dp[i-coin]);
                }
            }
        }

        return dp[amount];
    }

    int coinChange(vector<int>& coins, int amount) {

        // Initialize DP with INT_MAX
        vector<int> dp(amount+1, INT_MAX);
        int minCoins = solve(coins, amount, dp);

        return (minCoins == INT_MAX) ? -1 : minCoins;
    }
};