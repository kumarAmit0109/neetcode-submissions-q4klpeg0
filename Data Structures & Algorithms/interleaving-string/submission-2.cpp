class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        // bottom-up approach
        int m = s1.length();
        int n = s2.length();

        // early exit: lengths must add up
        if(m + n != s3.length()){
            return false;
        }

        // A key observation is that the position in s3 is always determined by how many characters
        // we have already taken from s1 and s2. So the state can be defined using just
        // index i in s1 and index j in s2
        // k is always i+j so no need to track separately
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));

        // base case: both s1 and s2 exhausted then valid interleaving
        dp[m][n] = true;

        // fill from bottom-right to top-left
        // because dp[i][j] depends on dp[i+1][j] and dp[i][j+1]
        for(int i = m; i >= 0; i--){
            for(int j = n; j >= 0; j--){
                // skip base case
                if(i == m && j == n){
                    continue;
                }
                // k is always i+j
                int k = i + j;
                bool opt1 = false;
                // take from s1 if char matches s3[k]
                if(i < m && s1[i] == s3[k]){
                    opt1 = dp[i+1][j];   // use i+j as k, no manual k--
                }

                bool opt2 = false;
                // take from s2 if char matches s3[k]
                if(j < n && s2[j] == s3[k]){
                    opt2 = dp[i][j+1];  
                }

                dp[i][j] = opt1 || opt2;
            }
        }

        return dp[0][0];
    }
};