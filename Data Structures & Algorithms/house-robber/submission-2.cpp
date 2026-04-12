class Solution {
public:
    int solve(vector<int>&nums, int i, vector<int>&dp){
        // top-down approach
        if(i < 0){
            return 0;
        }
        if(i == 0){
            return nums[0];
        }

        if(dp[i] != -1){
            return dp[i];
        }

        // include the current element
        int res1 = solve(nums, i-2, dp) + nums[i];
        // exclude the current element
        int res2 = solve(nums, i-1, dp) + 0;
        return  dp[i] = max(res1, res2);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n, -1);
        int ans = solve(nums, n-1, dp);
        return ans;
    }
};
