class Solution {
public:
    bool dfs(int i, int j, string& s, string& p){
        // if pattern exhausted → match only if string also exhausted
        if(j >= p.length()){
            return i >= s.length();
        }

        // check if current characters match
        // i must be valid + chars must match or pattern has '.'
        bool currMatch = (i < s.length()) && (s[i] == p[j] || p[j] == '.');

        // if next pattern char is '*' → two choices:
        if(j + 1 < p.length() && p[j+1] == '*'){
            // opt1: use '*' as zero occurrences → skip "x*" in pattern
            bool zeroOccurrence = dfs(i, j+2, s, p);
            // opt2: use '*' as one+ occurrences → consume s[i] if currMatch
            bool oneOccurrence = currMatch && dfs(i+1, j, s, p);
            return zeroOccurrence || oneOccurrence;
        }

        // no '*' → current must match, then move both forward
        return currMatch && dfs(i+1, j+1, s, p);
    }

    bool isMatch(string s, string p) {
        // start with 0th index for both strings s and p
        return dfs(0, 0, s, p);
    }
};