class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_set<char>charSet(s.begin(), s.end());
        int res = 0;

        for(char ch : charSet){
            int count = 0, left = 0;
            for(int right = 0; right < s.size(); right++){
                if(s[right] == ch){
                    count++;
                }

                while((right - left + 1) - count > k){
                    if(s[left] == ch){
                        count--;
                    }
                    left++;
                }

                res = max(res, right - left + 1);
            }
        }
        return res;
    }
};
