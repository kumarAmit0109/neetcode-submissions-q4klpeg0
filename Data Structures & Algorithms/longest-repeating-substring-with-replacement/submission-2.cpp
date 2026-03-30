class Solution {
public:
    int characterReplacement(string s, int k) {
        int res = 0;
        unordered_set<char>charSet(s.begin(), s.end());

        for(char ch : charSet){
            int count = 0, left = 0;
            for(int right = 0; right < s.length(); right++){
                if(s[right] == ch){
                    count++;
                }

                while((right - left +1 ) - count > k){
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
