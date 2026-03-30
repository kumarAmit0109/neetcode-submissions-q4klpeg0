class Solution {
public:
    bool isValid(string s){
        int opnCnt = 0;
        for(char c : s){
            // for ( increase count for ) decrese , if any moment count become
            // -ve means we have invalid string 
            opnCnt += (c == '(') ? 1 : -1;
            if(opnCnt < 0){
                return false;
            }
        }

        // if in the end count is 0 means string in valid
        return opnCnt == 0;
    }
    void dfs(string s, vector<string>& res, int n){
        // if string length become twice of n then string is generated 
        // now only validation is needed to check
        if(s.length() == 2 * n){
            if(isValid(s)){
                res.push_back(s);
            }
            return;
        }
        // once add '(' and continue
        dfs(s+'(', res, n);
        // ten add ')' and continue
        dfs(s+')', res, n);
    }
    vector<string> generateParenthesis(int n) {
        // generate all string nd then check before storing in the
        // result whether its valid or not if valid then only store 
        vector<string>res;
        dfs("", res, n);
        return res;
    }
};
