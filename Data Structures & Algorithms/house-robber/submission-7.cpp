class Solution {
public:
    int solve(vector<int>&nums){
        // Edge case: only one house
        if(nums.size() == 1){
            return nums[0];
        }
        // space optimization approach
        int prev1 = nums[0]; // make dp[0] as prev1

        int prev2 = max(nums[0], nums[1]); // make dp[1] as prev2

        // now process for remaining
        for(int i = 2; i < nums.size(); i++){
            // include the current element
            int res1 = prev1 + nums[i];
            // exclude the current element
            int res2 = prev2 + 0;
            int res = max(res1, res2);
            // update prev1, nd prev2
            prev1 = prev2;
            prev2 = res;
        }
        return prev2;
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        int ans = solve(nums);
        return ans;
    }
};
