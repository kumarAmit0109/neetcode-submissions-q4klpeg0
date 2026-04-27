class Solution {
public:
    bool dfs(int i, int j, string& s, string& p, vector<vector<int>>&dp ){
        // if pattern exhausted → match only if string also exhausted
        if(j >= p.length()){
            return i >= s.length();
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }
        // check if current characters match
        // i must be valid + chars must match or pattern has '.'
        bool currMatch = (i < s.length()) && (s[i] == p[j] || p[j] == '.');

        // if next pattern char is '*' → two choices:
        if(j + 1 < p.length() && p[j+1] == '*'){
            // opt1: use '*' as zero occurrences → skip "x*" in pattern
            bool zeroOccurrence = dfs(i, j+2, s, p, dp);
            // opt2: use '*' as one+ occurrences → consume s[i] if currMatch
            bool oneOccurrence = currMatch && dfs(i+1, j, s, p, dp);
            return dp[i][j] = zeroOccurrence || oneOccurrence;
        }

        // no '*' → current must match, then move both forward
        return dp[i][j] = currMatch && dfs(i+1, j+1, s, p, dp);
    }

    bool isMatch(string s, string p) {
        // start with 0th index for both strings s and p
        // top-down dp
        vector<vector<int>>dp(s.length()+1 , vector<int>(p.length()+1 , -1));
        return dfs(0, 0, s, p, dp);
    }
};