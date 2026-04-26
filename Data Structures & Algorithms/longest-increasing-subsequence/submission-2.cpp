class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // bottom-up dp
        int n = nums.size();
        // dp[indx][lastIndx+1]
        // since last index can be -1 therefore we choose lastIndx+1
        // n+1 columns to handle lastIndx from -1 to n-1
        // base case: dp[n][*] = 0 (no elements left, LIS length = 0)
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        // fill from the end (indx = n-1 to 0)
        for (int indx = n - 1; indx >= 0; indx--) {
            // lastIndx ranges from -1 to n-1, stored as lastIndx+1 (0 to n)
            for (int lastIndx = n - 1; lastIndx >= -1; lastIndx--) {
                // not include the curr indx element
                int opt1 = dp[indx + 1][lastIndx + 1];
                // if previous included element is smaller than curr one then we can include it
                int opt2 = 0;
                if (lastIndx == -1 || nums[lastIndx] < nums[indx]) {
                    // if we include, after making call for nxt element pass curr indx
                    // as the last included indx
                    opt2 = 1 + dp[indx + 1][indx + 1];
                }

                dp[indx][lastIndx + 1] = max(opt1, opt2);
            }
        }

        // start with indx=0 and lastIndx=-1 → dp[0][(-1)+1] = dp[0][0]
        return dp[0][0];
    }
};