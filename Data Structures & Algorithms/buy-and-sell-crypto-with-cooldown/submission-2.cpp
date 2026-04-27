class Solution {
   public:
    int dfs(int indx, bool isBuying, vector<int>& prices, vector<vector<int>>& dp) {
        for (int indx = prices.size() - 1; indx >= 0; indx--) {
            for (int isBuying = 1; isBuying >= 0; isBuying--) {
                // at any stage we can do two things either buy or sell stocks or
                // leave as cooldown period
                // cooldown: skip current day, move to next day, state remains same
                int cooldown = dp[indx + 1][isBuying];

                if (isBuying) {
                    // BUY option: pay prices[indx], move to next day in selling state
                    int buy = dp[indx + 1][0] - prices[indx];
                    // return best of: buying today vs skipping today (cooldown)
                    dp[indx][isBuying] = max(buy, cooldown);
                } else {
                    // SELL option: gain prices[indx], skip next day (cooldown after sell)
                    // jump to indx+2 because after selling we must wait 1 day (cooldown rule)
                    int sell = dp[indx + 2][1] + prices[indx];
                    // return best of: selling today vs skipping today (cooldown)
                    dp[indx][isBuying] = max(sell, cooldown);
                }
            }
        }
        return dp[0][1];
    }

    int maxProfit(vector<int>& prices) {
        // start with 0th index nd buying stock option as true
        // true = we are currently in buying state (haven't bought yet)
        // bottom-up dp
        // rows denotes prices indexes from  0 to n-1, while
        // cols denotes the isbuying state (0 means selling, 1 means buying)
        // use +2 as rows to stop gettting out of bound error
        vector<vector<int>> dp(prices.size() + 2, vector<int>(2, 0));
        int ans = dfs(0, true, prices, dp);
        return ans;
    }
};