class Solution {
public:
    int dfs(int indx, int amount, vector<int>& coins, vector<vector<int>>&dp){
        // if we have nothing left so simply return 1 as valid count
        if(amount == 0){
            return 1;
        }
        // if at any moment amount become -ve or we reach out of bound
        // so its not possible to reach the final amount so, simply return
        // 0
        if(amount < 0 || indx >= coins.size()){
            return 0; 
        }

        if(dp[indx][amount] != -1){
            return dp[indx][amount];
        }
        // Choice 1: Take current coin (unlimited supply)
        int take = dfs(indx, amount - coins[indx], coins, dp);
        // Choice 2: Skip current coin
        int skip = dfs(indx + 1, amount, coins, dp);
        // Total ways from this state
        return dp[indx][amount] = take + skip;

    }
    int change(int amount, vector<int>& coins) {
        // top-down dp
        vector<vector<int>>dp(coins.size(), vector<int>(amount+1, -1));
        // strt with index 0 and amount as remaining sum to make
        int res = dfs(0, amount, coins, dp);
        return res;
    }
};
