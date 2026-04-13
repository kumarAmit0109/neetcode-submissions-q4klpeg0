class Solution {
public:
    int solve(vector<int>& nums, int i, int start, vector<int>&dp) {
        // top-down dp
        if (i == start) {
            return nums[start];
        }
        if (i == start + 1) {
            return max(nums[start], nums[start + 1]);
        }

        if(dp[i] != -1){
            return dp[i];
        }
        // include the current element
        int res1 = solve(nums, i - 2, start, dp) + nums[i];
        // exclude the current element
        int res2 = solve(nums, i - 1, start, dp) + 0;
        return dp[i] = max(res1, res2);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n, -1);
        // Edge case: only one house
        if (n == 1) return nums[0];
        // Case 1: Rob houses from index 0 to n-2 (exclude last house)
        int case1 = solve(nums, n - 2, 0, dp);
        // reset the dp array used above for second case
        fill(dp.begin(), dp.end(), -1);
        // Case 2: Rob houses from index 1 to n-1 (exclude first house)
        int case2 = solve(nums, n - 1, 1, dp);
        return max(case1, case2);
    }
};