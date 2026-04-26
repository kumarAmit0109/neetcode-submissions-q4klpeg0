class Solution {
public:
    int dfs(string text1, string text2, int i, int j){
        // if we reach the end of either text1 or text2 we can take 
        // further chars so return 0
        if(i == text1.size() || j == text2.size()){
            return 0;
        }

        // if char matches take it nd increase both pointers
        if(text1[i] == text2[j]){
            return 1 + dfs(text1, text2, i+1, j+1);
        }
        // else consider two cases in one increase i nd make call for nxt reccursion
        // in other case increase j nd make call for nxt reccursion and in the end
        // return the mex result of both call
        int opt1 = dfs(text1, text2, i+1, j);
        int opt2 = dfs(text1, text2, i, j+1);
        return max(opt1, opt2);
    }
    int longestCommonSubsequence(string text1, string text2) {
        // initially start with indx 0 for txt1, and indx 0 for txt2
        int res = dfs(text1, text2, 0, 0);
        return res;
    }
};
