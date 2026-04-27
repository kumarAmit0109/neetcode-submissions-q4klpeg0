class Solution {
public:
    int dfs(string s, string t, int i, int j){
        // if we reach the end of string t means we found a valid subsequence
        if(j == t.length()){
            return 1;
        }
        // but in case we reach the string s length means we are not able to 
        // found any subsequence on this path so, simply  return 0 
        if(i == s.length()){
            return 0;
        }

        // at any step we can either skip curr char or take it if it match
        // in both strings s and t
        int skip = dfs(s, t, i+1, j);
        
        int take = 0;
        if(s[i] == t[j]){
            take = dfs(s, t, i+1, j+1);
        }
        return skip + take;
    }
    int numDistinct(string s, string t) {
        // if the length of second string is more than the first one
        // this indicates that no, such subsequence possible
        if(t.length() > s.length()){
            return 0;
        }

        // in other case simply start recursive dfs call with the 0th index
        // for both s and t string
        return dfs(s, t, 0, 0);
    }
};
