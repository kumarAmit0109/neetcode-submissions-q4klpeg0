class Solution {
public:
    int dfs(int indx, bool isBuying, vector<int>& prices){
        // if we go out of bounds no more transactions possible, s
        if(indx >= prices.size()){
            return 0;
        }

        // at any stage we can do two things either buy or sell stocks or
        // leave as cooldown period
        // cooldown: skip current day, move to next day, state remains same
        int cooldown = dfs(indx+1, isBuying, prices);

        if(isBuying){
            // BUY option: pay prices[indx], move to next day in selling state
            int buy = dfs(indx+1, false, prices) - prices[indx];
            // return best of: buying today vs skipping today (cooldown)
            return max(buy, cooldown);
        }else{
            // SELL option: gain prices[indx], skip next day (cooldown after sell)
            // jump to indx+2 because after selling we must wait 1 day (cooldown rule)
            int sell = dfs(indx+2, true, prices) + prices[indx];
            // return best of: selling today vs skipping today (cooldown)
            return max(sell, cooldown);
        }
    }

    int maxProfit(vector<int>& prices) {
        // start with 0th index nd buying stock option as true
        // true = we are currently in buying state (haven't bought yet)
        int ans = dfs(0, true, prices);
        return ans;
    }
};