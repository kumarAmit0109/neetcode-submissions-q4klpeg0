class Solution {
   public:
    bool isMatch(string s, string p) {
        // start with 0th index for both strings s and p
        // bottom-up dp
        int m = s.length();
        int n = p.length();
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));

        // base case: both string and pattern exhausted save true
        dp[m][n] = true;

        // handle patterns like "a*b*c*" that can match empty string
        for (int j = n - 2; j >= 0; j -= 2) {
            if (p[j + 1] == '*') {
                dp[m][j] = dp[m][j + 2];  // zero occurrence matches empty string
            } else {
                break;
            }
        }

        for (int i = m; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                // check if current characters match
                // i must be valid + chars must match or pattern has '.'
                bool currMatch = (i < m) && (s[i] == p[j] || p[j] == '.');

                // if next pattern char is '*' → two choices:
                if (j + 1 < n && p[j + 1] == '*') {
                    // opt1: use '*' as zero occurrences → skip "x*" in pattern
                    bool zeroOccurrence = dp[i][j + 2];
                    // opt2: use '*' as one+ occurrences → consume s[i] if currMatch
                    bool oneOccurrence = currMatch && dp[i + 1][j];
                    dp[i][j] = zeroOccurrence || oneOccurrence;
                } else {
                    // used if-else block so '*' result doesn't get overwritten
                    // no '*' → current must match, then move both forward
                    dp[i][j] = currMatch && dp[i + 1][j + 1];
                }
            }
        }

        return dp[0][0];
    }
};