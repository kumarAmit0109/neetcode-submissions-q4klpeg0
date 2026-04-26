class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        // +1 size to safely handle base case at i=text1.size() or j=text2.size()
        // initialized to 0 so base case rows/cols are already set
        vector<vector<int>> dp(text1.size() + 1, vector<int>(text2.size() + 1, 0));

        // fill from bottom-right to top-left
        // because dp[i][j] depends on dp[i+1][j+1], dp[i+1][j], dp[i][j+1]
        // so those must be computed first
        for(int i = text1.size() - 1; i >= 0; i--){
            for(int j = text2.size() - 1; j >= 0; j--){

                if(text1[i] == text2[j]){
                    // chars match so take it and move both pointers forward
                    dp[i][j] = 1 + dp[i+1][j+1];
                } else {
                    // if no match then try skipping from either string, take best
                    int opt1 = dp[i+1][j];   // skip char from text1
                    int opt2 = dp[i][j+1];   // skip char from text2
                    dp[i][j] = max(opt1, opt2);
                }
            }
        }

        // answer: LCS starting from both strings at index 0
        return dp[0][0];
    }
};