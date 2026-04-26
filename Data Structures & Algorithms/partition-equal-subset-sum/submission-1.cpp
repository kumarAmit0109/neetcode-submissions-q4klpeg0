class Solution {
public:
    bool dfs(vector<int>& nums, int indx, int target, vector<vector<int>>& dp){
        // if we reach the end simply return whether we are able
        // to meet the target or not
        if(indx == nums.size()){
            return target == 0;
        }
        // if at any point we have to form -ve target simply return 0
        if(target < 0){
            return 0;
        }
        if(dp[indx][target] != -1){
            return dp[indx][target];
        }
        bool include = dfs(nums, indx+1, target - nums[indx], dp);
        bool exclude = dfs(nums, indx+1, target, dp);
        return dp[indx][target] = include || exclude;
    }
    bool canPartition(vector<int>& nums) {
        // idea is pretty simple try to build the subset having sum 
        // of total/2, so other half automatically equal to first half
        int sum = 0;
        for(int num : nums){
            sum += num;
        }
        // if there is odd sum we are not able to divide it in equl half 
        if(sum % 2 != 0){
            return false;
        }
        // here indx nd target two things are changing so, its an example of 
        // 2-D dp
        vector<vector<int>>dp(nums.size(), vector<int>(sum/2 + 1, -1));
        // strt with indx 0, nd try to find the subset having total/2 as sum
        return dfs(nums, 0, sum/2, dp);
    }
};
