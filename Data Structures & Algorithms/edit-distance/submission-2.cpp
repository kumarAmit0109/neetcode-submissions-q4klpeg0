class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();

        // dp[i][j] = min operations to convert word1[i:] to word2[j:]
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        // Base cases (same as top-down)
        // If word1 is exhausted, insert remaining chars of word2
        for (int j = 0; j <= n; j++) {
            dp[m][j] = n - j;
        }

        // If word2 is exhausted, delete remaining chars of word1
        for (int i = 0; i <= m; i++) {
            dp[i][n] = m - i;
        }

        // Fill table bottom-up
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {

                // If characters match, no operation needed
                if (word1[i] == word2[j]) {
                    dp[i][j] = dp[i + 1][j + 1];
                } else {
                    // Three operations
                    int del = dp[i + 1][j];     // delete
                    int ins = dp[i][j + 1];     // insert
                    int rep = dp[i + 1][j + 1]; // replace

                    dp[i][j] = 1 + min({del, ins, rep});
                }
            }
        }

        return dp[0][0];
    }
};