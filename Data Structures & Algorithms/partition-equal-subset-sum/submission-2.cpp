class Solution {
public:
    bool canPartition(vector<int>& nums) {
        // idea is pretty simple try to build the subset having sum 
        // of total/2, so other half automatically equal to first half
        int sum = 0;
        for(int num : nums){
            sum += num;
        } 

        // if there is odd sum we are not able to divide it in equal half
        if(sum % 2 != 0){
            return false;
        } 

        int n = nums.size();
        int target = sum / 2;

        // bottom-up dp
        // n+1 rows needed so that base case row (indx=n) exists
        vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));

        // base case: at indx=n with target=0 → we successfully formed the sum
        dp[n][0] = true;

        for(int indx = n - 1; indx >= 0; indx--){
            for(int t = 0; t <= target; t++){
                // exclude current element
                bool exclude = dp[indx + 1][t];
                // include current element (only if target doesn't go negative)
                bool include = false;
                if(t - nums[indx] >= 0){
                    include = dp[indx + 1][t - nums[indx]];
                }
                dp[indx][t] = include || exclude;
            }
        }
        // start with indx=0, try to form sum/2
        return dp[0][target];
    }
};