class Solution {
public:
    int dfs(int left, int right, vector<int>& nums, vector<vector<int>>& dp){
        // no balloons left to burst in this range
        if(right - left < 2){
            return 0;
        }

        // return already computed result
        if(dp[left][right] != -1){
            return dp[left][right];
        }

        int maxCoins = 0;
        // try every balloon k as the last to burst in range (left, right)
        // when k is burst last, its neighbors are still left and right
        for(int k = left+1; k < right; k++){
            // coins from bursting k last in this range
            int coins = nums[left] * nums[k] * nums[right];
            // coins from left subrange + right subrange
            coins += dfs(left, k, nums, dp) + dfs(k, right, nums, dp);
            maxCoins = max(maxCoins, coins);
        }

        return dp[left][right] = maxCoins;
    }

    int maxCoins(vector<int>& nums) {
        // add 1 to beginning and the end to avoids out-of-bounds when 
        // bursting first or last balloon as now they always have a 1 as neighbor
        nums.insert(nums.begin(), 1);
        nums.push_back(1);

        int n = nums.size();
        // dp[left][right] = max coins from bursting all balloons between left and right
        vector<vector<int>> dp(n, vector<int>(n, -1));

        // try all possible burst orders and return the maximum coins
        return dfs(0, n-1, nums, dp);
    }
};