class Solution {
public:
    int solve(vector<int>& coins, int amount, vector<int>&dp) {
        //  If amount becomes 0 → no coins needed
        if (amount == 0){
            return 0;
        }

        if(dp[amount] != -1){
            return dp[amount];
        }
        int res = 1e9;
        for (int coin : coins) {
            if (amount - coin >= 0) {
                res = min(res, 1 + solve(coins, amount - coin, dp));     
            }
        }
        return dp[amount] = res;
    }

    int coinChange(vector<int>& coins, int amount) {

        vector<int>dp(amount+1, -1);
        int minCoins = solve(coins, amount, dp);
        
        return (minCoins >= 1e9) ? -1 : minCoins;
    }
};