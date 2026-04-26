class Solution {
   public:
    int dfs(vector<int>& nums, int indx, int lastIndx, vector<vector<int>>& dp) {
        if (indx == nums.size()) {
            return 0;
        }
        if (dp[indx][lastIndx + 1] != -1) {
            return dp[indx][lastIndx + 1];
        }
        // not include the curr indx element
        int opt1 = dfs(nums, indx + 1, lastIndx, dp);

        // if previous included element is smaller than curr one then we can include it
        int opt2 = -1;
        if (lastIndx == -1 || nums[lastIndx] < nums[indx]) {
            // if we include after making call for nxt element pass curr indx
            // as the last included indx
            opt2 = 1 + dfs(nums, indx + 1, indx, dp);
        }
        return dp[indx][lastIndx + 1] = max(opt1, opt2);
    }
    int lengthOfLIS(vector<int>& nums) {
        // top-down dp
        // lastIndx and indx both values are changing therefore its an example
        // of 2-D dp
        int n = nums.size();
        // dp[indx][lastIndx+1]
        // since last index can be -1 therefore we choose lastIndx+1
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));

        // inititally start with 0 index nd -1 as the last included indx
        int res = dfs(nums, 0, -1, dp);
        return res;
    }
};
