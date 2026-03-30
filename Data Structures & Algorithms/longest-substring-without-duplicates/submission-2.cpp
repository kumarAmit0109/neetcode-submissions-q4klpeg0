class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;

        for(int i = 0; i < s.length(); i++){
            unordered_set<char>seen;
            int count = 0;
            for(int j = i; j < s.length(); j++){
                if(seen.count(s[j])){
                    break;
                }else{
                    seen.insert(s[j]);
                    count++;
                }
            }
            ans = max(count, ans);

        }
        return ans;
    }
};
