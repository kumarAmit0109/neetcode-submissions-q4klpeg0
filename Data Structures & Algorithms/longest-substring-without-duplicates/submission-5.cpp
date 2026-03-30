class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
        int left = 0;
        int res = 0;

        for (int right = 0; right < s.length(); right++) {
            if (mp.find(s[right]) != mp.end()) {
                // left pointer must never move backward in sliding window problems.
                // That’s why max(left, lastIndex + 1) is required
                left = max(left, mp[s[right]] + 1);  
            }

            mp[s[right]] = right;
            res = max(res, right - left + 1);
        }
        return res;
    }
};
