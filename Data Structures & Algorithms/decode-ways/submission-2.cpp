class Solution {
   public:
    int dfs(string s, vector<int>& dp) {
        // dp[i] = number of ways to decode substring starting at index i
        // If we are at the end of the string, there is exactly 1 way to decode
        // (we have successfully decoded the entire string)
        dp[s.size()] = 1;

        // Fill the dp array from right to left
        for (int i = s.size() - 1; i >= 0; i--) {
            // If the current character is '0',
            // it cannot be decoded into any letter
            // so there are 0 ways starting from index

            if (s[i] == '0') {
                dp[i] = 0;
            } else {
                // decode 1 char nd call for rest one with indx+1
                int res = dp[i + 1];
                // if indx is within range nd value at indx is either 1 or 2 with nxt value less
                // than 7 so decode 2 char and add it to the result
                if (i < s.size() - 1) {
                    if ((s[i] == '1') || (s[i] == '2' && s[i + 1] < '7')) {
                        res += dp[i + 2];
                    }
                }
                dp[i] = res;
            }
        }

        // dp[0] contains the total number of ways
        // to decode the entire string

        return dp[0];
    }
    int numDecodings(string s) {
        // bottom-up approach
        vector<int> dp(s.size() + 1, -1);
        // start with index 0
        int res = dfs(s, dp);
        return res;
    }
};
