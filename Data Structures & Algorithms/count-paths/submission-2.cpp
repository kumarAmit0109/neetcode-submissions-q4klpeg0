class Solution {
public:
    int uniquePaths(int m, int n) {
        // bottom-up dp
        // as two values are changing i.e., i and j so its example of 2D dp
        // m+1 and n+1 to safely access dp[i+1] and dp[j+1] without out of bounds
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        // base case: there is exactly 1 way to reach the destination from itself
        dp[m-1][n-1] = 1;

        // fill the table from bottom-right to top-left
        // because dp[i][j] depends on dp[i][j+1] and dp[i+1][j]
        // so those must be computed first
        for(int i = m-1; i >= 0; i--){
            for(int j = n-1; j >= 0; j--){
                // skip destination cell so we don't overwrite base case
                if(i == m-1 && j == n-1){
                    continue;
                }
                // number of paths going right (j+1)
                int opt1 = dp[i][j+1];
                // number of paths going down (i+1)
                int opt2 = dp[i+1][j];

                // total paths from (i,j) = paths via right + paths via down
                dp[i][j] = opt1 + opt2;
            }
        }

        // answer: total unique paths from (0,0) to (m-1,n-1)
        int res = dp[0][0];
        return res;
    }
};