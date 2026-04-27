class Solution {
public:
    int numDistinct(string s, string t) {
        // if the length of second string is more than the first one
        // this indicates that no, such subsequence possible
        if(t.length() > s.length()){
            return 0;
        }
        // bottom-up dp
        // dp[i][j] = number of distinct subsequences of s[i..] that equals t[j..]
        vector<vector<double>> dp(s.size() + 1, vector<double>(t.size() + 1, 0));

        // base case: if we reach the end of t means we found a valid subsequence
        // so every row at t.length() column = 1
        for(int r = 0; r <= s.size(); r++){
            dp[r][t.length()] = 1;
        }
        // fill from bottom-right to top-left
        // because dp[i][j] depends on dp[i+1][j] and dp[i+1][j+1]
        for(int i = s.size() - 1; i >= 0; i--){
            for(int j = t.size() - 1; j >= 0; j--){
                // skip current char of s, move to next char in s
                int skip = dp[i + 1][j];
                // take current char only if both chars match
                int take = 0;
                if(s[i] == t[j]){
                    take = dp[i + 1][j + 1];
                }
                // total ways = skip + take
                dp[i][j] = take + skip;
            }
        }
        // answer: start from both strings at index 0
        return dp[0][0];
    }
};