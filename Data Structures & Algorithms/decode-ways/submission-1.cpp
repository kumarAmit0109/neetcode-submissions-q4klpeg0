class Solution {
public:
    int dfs(int indx, string s, vector<int>&dp){
        // if we reach end means possible decode so return 1;
        if(indx == s.size()){
            return 1;
        }
        // if value at indx is 0, means no decode possible simply return 0
        // as not any char is mapped to 0
        if(s[indx] == '0'){
            return 0;
        }

        if(dp[indx] != -1){
            return dp[indx];
        }

        // decode 1 char nd call for rest one with indx+1
        int res = dfs(indx+1, s, dp);

        // if indx is within range nd value at indx is either 1 or 2 with nxt value less than
        // 7 so decode 2 char and add it to the result
        if(indx < s.size() - 1){
            if((s[indx] == '1') || (s[indx] == '2' && s[indx+1] < '7')){
                res += dfs(indx+2, s, dp);
            }
        }
        return dp[indx] = res;
    }
    int numDecodings(string s) {
        // top-down approach
        vector<int>dp(s.size()+1, -1);
        // start with index 0
        int res = dfs(0, s, dp);
        return res;
    }
};
