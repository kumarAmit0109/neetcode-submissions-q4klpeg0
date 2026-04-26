class Solution {
public:
    int backtrack(int indx, int sum, vector<int>& nums, int target, vector<vector<int>>& dp, int totalSum){
        // if we reach end of nums, then simply return whether the sum
        // is equal to target or not in the end
        if(indx == nums.size()){
            return sum == target;
        }
        // shift sum by totalSum to convert negative index → positive
        if(dp[indx][sum + totalSum] != -1){
            return dp[indx][sum + totalSum];
        }
        // add nums[i] to current sum nd make a call for nxt one
        int opt1 = backtrack(indx+1, sum + nums[indx], nums, target, dp, totalSum);
        // subtract nums[i] from the current sum nd make a call for nxt one
        int opt2 = backtrack(indx+1, sum - nums[indx], nums, target, dp, totalSum);
        // store with offset so negative sum maps to valid index
        return dp[indx][sum + totalSum] = opt1 + opt2;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        // calculate total sum to determine the range of possible sums
        // sum ranges from -totalSum to +totalSum
        int totalSum = 0;
        for(int num : nums){
            totalSum += num;
        }
        // rows = indices (0 to n-1)
        // cols = possible sums shifted by totalSum (0 to 2*totalSum)
        vector<vector<int>> dp(nums.size(), vector<int>(2 * totalSum + 1, -1));

        // initially start with 0th index nd sum as 0
        int ans = backtrack(0, 0, nums, target, dp, totalSum);
        return ans;
    }
};