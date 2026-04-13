class Solution {
public:
    int solve(vector<int>& nums, int n, int start, vector<int>&dp) {
        // space-optimization approach
        int prev1 = nums[start]; // dp[start] becomes prev1

        int prev2 = max(nums[start], nums[start+1]); // dp[start+1] becomes prev2

        for(int i = start+2; i <= n; i++){
            // include the current element
            int res1 = prev1 + nums[i];
            // exclude the current element
            int res2 = prev2 + 0;
            int res = max(res1, res2);
            // update prev1 and prev2
            prev1 = prev2;
            prev2 = res;

        }
        
        return prev2;
        
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