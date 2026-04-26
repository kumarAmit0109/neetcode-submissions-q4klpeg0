class Solution {
public:
    int change(int amount, vector<int>& coins) {
        // bottom-up dp
        vector<vector<int>>dp(coins.size()+1, vector<int>(amount+1, 0));
        
        // Base case: amount = 0 so return 1 
        for (int i = 0; i <= coins.size(); i++) {
            dp[i][0] = 1;
        }

        // Fill table bottom-up
        for (int indx = coins.size() - 1; indx >= 0; indx--) {
            for (int amt = 1; amt <= amount; amt++) {
                // Skip current coin
                dp[indx][amt] = dp[indx + 1][amt];

                // Take current coin (unlimited supply)
                if (amt >= coins[indx]) {
                    dp[indx][amt] += dp[indx][amt - coins[indx]];
                }
            }
        }

        // Answer: ways to form `amount` starting at index 0
        return dp[0][amount];

    }
};
