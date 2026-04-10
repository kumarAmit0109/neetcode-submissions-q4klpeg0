class Solution {
public:

    int climbStairs(int n) {
        // Base cases
        if(n <= 1) return 1;

        int prev2 = 1; // dp[0]
        int prev1 = 1; // dp[1]

        // Build answer iteratively
        for(int i = 2; i <= n; i++){
            int curr = prev1 + prev2; // dp[i]
            // Shift values forward
            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }
};