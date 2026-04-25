class Solution {
public:
    int dfs(int indx, string s){
        // if we reach end means possible decode so return 1;
        if(indx == s.size()){
            return 1;
        }
        // if value at indx is 0, means no decode possible simply return 0
        // as not any char is mapped to 0
        if(s[indx] == '0'){
            return 0;
        }

        // decode 1 char nd call for rest one with indx+1
        int res = dfs(indx+1, s);

        // if indx is within range nd value at indx is either 1 or 2 with nxt value less than
        // 7 so decode 2 char and add it to the result
        if(indx < s.size() - 1){
            if((s[indx] == '1') || (s[indx] == '2' && s[indx+1] < '7')){
                res += dfs(indx+2, s);
            }
        }
        return res;
    }
    int numDecodings(string s) {
        
        // start with index 0
        int res = dfs(0, s);
        return res;
    }
};
