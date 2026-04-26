class Solution {
public:
    int dfs(int i, int j, int m, int n){
        // if we reach the destination then return 1 as its a valid path
        if((i == (m-1)) && (j == (n-1))){
            return 1;
        }
        // if we reach out of bound then simply return 0 as a sign of invalid path
        if( (i >= m) || (j >= n)){
            return 0;
        }

        // downward movement
        int opt1 = dfs(i, j+1, m, n);
        // righward movement
        int opt2 = dfs(i+1, j, m, n);
        return opt1 + opt2;
    }
    int uniquePaths(int m, int n) {
        // start with (0,0) postions to reach the (m-1, n-1)th postion
        int res = dfs(0, 0, m, n);
        return res;
    }
};
