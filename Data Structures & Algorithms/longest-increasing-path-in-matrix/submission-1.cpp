class Solution {
public:
    int dfs(int r, int c, vector<vector<int>>& matrix, int prevVal, vector<pair<int,int>>& directions, vector<vector<int>>& dp){
        int rows = matrix.size();
        int cols = matrix[0].size();
        // if we reach out of bound or encounter a value which is smaller than
        // prevVal so we cann't take that path so simply return 0
        if((r < 0 || r >= rows) || (c < 0 || c >= cols) || (matrix[r][c] <= prevVal)){
            return 0;
        }

        if(dp[r][c] != -1){
            return dp[r][c];
        }
        // take current and explore all the direction
        int res = 1;
        for(auto dir : directions){
            int nr = r + dir.first;
            int nc = c + dir.second;
            res = max(res, 1 + dfs(nr, nc, matrix, matrix[r][c], directions, dp));
        }

        return dp[r][c] = res;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int res = INT_MIN;
        vector<pair<int,int>> directions = {{-1,0}, {1,0}, {0,-1}, {0,1}};
        vector<vector<int>>dp(rows, vector<int>(cols, -1));
        for(int r = 0; r < rows; r++){
            for(int c = 0; c < cols; c++){
                int temp = dfs(r, c, matrix, INT_MIN, directions, dp);
                res = max(res, temp);

            }
            // dp[r][c] stores the longest increasing path starting from (r,c) — this
            //  answer is always the same regardless of which cell called it. So it's 
            // safe to reuse across all outer loop iterations.
            // dp.assign(rows, vector<int>(cols, -1));
        }
        return res;
    }
};
