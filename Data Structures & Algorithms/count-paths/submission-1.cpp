class Solution {
public:
    int dfs(int i, int j, int m, int n, vector<vector<int>>& dp){
        // if we reach the destination then return 1 as its a valid path
        if((i == (m-1)) && (j == (n-1))){
            return 1;
        }
        // if we reach out of bound then simply return 0 as a sign of invalid path
        if( (i >= m) || (j >= n)){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        // downward movement
        int opt1 = dfs(i, j+1, m, n, dp);
        // righward movement
        int opt2 = dfs(i+1, j, m, n, dp);
        return dp[i][j] = opt1 + opt2;
    }
    int uniquePaths(int m, int n) {
        // top-down dp
        // as two values are changing i.e., i and j so its example of 2D dp
        vector<vector<int>>dp(m, vector<int>(n, -1));
        // start with (0,0) postions to reach the (m-1, n-1)th postion
        int res = dfs(0, 0, m, n, dp);
        return res;
    }
};
