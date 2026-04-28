class Solution {
public:
    int dfs(int i, int j, int k, string& s1, string& s2, string& s3){
        // if k reach the end of the string s3, so in that case if we reach the
        // end of both s2 and s1 so it means we can able to interleave the string
        if(k == s3.length()){
            return (i == s1.length() && j == s2.length());
        }

        // in other case select from either the s1 or s2 at a time and make the 
        // next recursive call 
        int opt1 = false;
        if(i < s1.length() && s1[i] == s3[k]){
            opt1 = dfs(i+1, j, k+1, s1, s2, s3);
        } 

        int opt2 = false;
        if(j < s2.length() && s2[j] == s3[k]){
            opt2 = dfs(i, j+1, k+1, s1, s2, s3);
        }

        return opt1 || opt2;
    }
    bool isInterleave(string s1, string s2, string s3) {
        // start with 3 pointers, i, j, k with values 0, 0, 0 as starting indexes
        int ans = dfs(0, 0, 0, s1, s2, s3);
        return ans;
    }
};
