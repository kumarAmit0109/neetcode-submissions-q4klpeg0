class Solution {
public:
    int characterReplacement(string s, int k) {
        int res = 0;
        
        for(int i = 0; i < s.length(); i++){
            unordered_map<char, int> mp;
            int maxFreq = 0;
            for(int j = i; j < s.length(); j++){
                mp[s[j]]++;
                maxFreq = max(maxFreq, mp[s[j]]);
                if((j - i + 1) - maxFreq <=k){
                    res = max(res, j - i + 1);
                }
            }
        }
        return res;
    }
};
