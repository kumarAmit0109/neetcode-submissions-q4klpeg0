class Solution {
public:
    int dfs(string s) {
        int n = s.size();

        // nxt1 = dp[i+1], nxt2 = dp[i+2]
        // Base case: dp[n] = 1 (empty string has 1 valid decoding)
        int nxt1 = 1;
        int nxt2 = 0;

        // Traverse from right to left
        for (int i = n - 1; i >= 0; i--) {
            // curr starts from 0 because we accumulate valid decoding ways at index i;
            // if no valid decoding is possible (e.g., s[i] == '0'), it should remain 0.
            int curr = 0;
            // If current digit is '0', no valid decoding possible
            if (s[i] != '0') {
                // Option 1: decode one digit
                curr = nxt1;
                // Option 2: decode two digits if valid (10–26)
                if (i < n - 1 && (s[i] == '1' || (s[i] == '2' && s[i + 1] < '7'))) {
                    curr += nxt2;
                }
            }

            // Shift values for next iteration
            nxt2 = nxt1;
            nxt1 = curr;
        }

        // nxt1 now holds dp[0]
        return nxt1;
    }

    int numDecodings(string s) {
        // Space-optimized bottom-up solution
        return dfs(s);
    }
};