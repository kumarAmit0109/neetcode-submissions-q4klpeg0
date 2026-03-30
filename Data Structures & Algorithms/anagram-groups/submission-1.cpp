class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }

        vector<int> count(26, 0);
        for (int i = 0; i < s.length(); i++) {
            count[s[i] - 'a']++;
            count[t[i] - 'a']--;
        }

        for (int val : count) {
            if (val != 0) {
                return false;
            }
        }
        return true;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        vector<bool> used(strs.size(), false);

        for (int i = 0; i < strs.size(); i++) {
            if (used[i]) continue;

            vector<string> temp;
            temp.push_back(strs[i]);
            used[i] = true;

            for (int j = i + 1; j < strs.size(); j++) {
                if (!used[j] && isAnagram(strs[i], strs[j])) {
                    temp.push_back(strs[j]);
                    used[j] = true;
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
