class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int len1 = s1.length();
        sort(s1.begin(), s1.end());

        for (int i = 0; i + len1 <= s2.length(); i++) {
            string subStr = s2.substr(i, len1);
            sort(subStr.begin(), subStr.end());

            if (subStr == s1) {
                return true;
            }
        }
        return false;
    }
};
