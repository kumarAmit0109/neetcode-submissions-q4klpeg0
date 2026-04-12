class Solution {
public:
    int solve(vector<int>&nums, int n, vector<int>&dp){
        // bottom-up approach
        dp[0] = nums[0];

        dp[1] = max(nums[0], nums[1]);

        // now process for remaining
        for(int i = 2; i < nums.size(); i++){
            // include the current element
            int res1 = dp[i-2] + nums[i];
            // exclude the current element
            int res2 = dp[i-1] + 0;
            dp[i] = max(res1, res2);
        }
        return dp[n];
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n, -1);
        int ans = solve(nums, n-1, dp);
        return ans;
    }
};
