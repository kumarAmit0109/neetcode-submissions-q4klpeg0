class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        // dp[i] = true means s[i..] can be segmented into dictionary words
        // initialized to false, only set true when valid segmentation found
        vector<bool> dp(s.length() + 1, false);

        // base case: empty string can always be segmented
        dp[s.length()] = true;

        // fill from right to left
        // because dp[indx] depends on dp[indx + word.length()] (further right)
        // so those must be computed first
        for(int indx = s.length() - 1; indx >= 0; indx--){
            // try every word in dictionary starting at position indx
            for(const string& word : wordDict){
                if(indx + word.length() <= s.length() && s.substr(indx, word.length()) == word){
                    if(dp[indx + word.length()]){
                        dp[indx] = true;  
                    }
                }
            }
        }

        return dp[0];
    }
};