class Solution {
public:
    int dfs(int indx, string s, vector<string>& wordDict, vector<int>& dp){
        // if we reach the end of string s, means s can be segmented into a space
        // seperated sequence of dictionary words so return true;
        if(indx == s.length()){
            return true;
        }

        if(dp[indx] != -1){
            return dp[indx];
        }
        // try to find that is there any words in the dictionary either exists
        // as a substr in string s, if yes then make a recursive call with the
        // new index as a (initial indx + existed word.length) if from that call we 
        // recive true simply return then
        for(const string& word : wordDict){
            if( indx + word.length() <= s.length() && s.substr(indx, word.length()) == word){
                if(dfs(indx + word.length(), s, wordDict, dp)){
                    return dp[indx] = true;
                }
            }
        }
        return dp[indx] = false;

    }
    bool wordBreak(string s, vector<string>& wordDict) {
        // start with the 0th index for the wordDict vector
        vector<int>dp(s.length(), -1);
        return dfs(0, s, wordDict, dp);
    }
};
