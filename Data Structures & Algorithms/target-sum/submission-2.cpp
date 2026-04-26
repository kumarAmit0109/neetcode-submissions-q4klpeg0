class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        // calculate total sum to determine the range of possible sums
        // sum ranges from -totalSum to +totalSum
        int totalSum = 0;
        for(int num : nums){
            totalSum += num;
        }

        // edge case: target is out of reachable range
        if(target > totalSum || target < -totalSum){
            return 0;
        }
        int n = nums.size();

        // rows = indices (0 to n)  → n+1 for base case row at indx=n
        // cols = possible sums shifted by totalSum (0 to 2*totalSum)
        vector<vector<int>> dp(n + 1, vector<int>(2 * totalSum + 1, 0));

        // base case: at indx=n, only target sum gives 1 way
        // shift target by totalSum to get valid index
        dp[n][target + totalSum] = 1;

        // fill from bottom to top
        // because dp[indx] depends on dp[indx+1]
        for(int indx = n - 1; indx >= 0; indx--){
            for(int sum = -totalSum; sum <= totalSum; sum++){
                // add nums[indx] to current sum
                int opt1 = 0;
                if(sum + nums[indx] + totalSum <= 2 * totalSum){
                    opt1 = dp[indx + 1][sum + nums[indx] + totalSum];
                }
                // subtract nums[indx] from current sum
                int opt2 = 0;
                if(sum - nums[indx] + totalSum >= 0){
                    opt2 = dp[indx + 1][sum - nums[indx] + totalSum];
                }

                // total ways from this state
                dp[indx][sum + totalSum] = opt1 + opt2;
            }
        }

        // answer: start from indx=0, sum=0
        return dp[0][0 + totalSum];
    }
};