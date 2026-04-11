class Solution {
public:
    int solve(vector<int>& coins, int amount) {
        //  If amount becomes 0 → no coins needed
        if (amount == 0){
            return 0;
        }

        int res = 1e9;
        for (int coin : coins) {
            if (amount - coin >= 0) {
                res = min(res, 1 + solve(coins, amount - coin));     
            }
        }
        return res;
    }

    int coinChange(vector<int>& coins, int amount) {
        int minCoins = solve(coins, amount);
        
        return (minCoins >= 1e9) ? -1 : minCoins;
    }
};