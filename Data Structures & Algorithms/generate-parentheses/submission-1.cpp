class Solution {
public:
    void backtrack(int openCount, int closeCount, int n, vector<string>& res, string& temp){
        // if open and close count become equal nd both are equal to n 
        // means valid string generated store and return
        if(openCount == closeCount && openCount == n){
            res.push_back(temp);
            return;
        }

        // if we have still open parentheses pending add to temp nd make call for nxt one
        if(openCount < n){
            temp += '(';
            backtrack(openCount + 1, closeCount, n, res, temp);
            // backtrack
            temp.pop_back();
        }

        // for adding close parentheses make sure we have more open parentheses 
        // as compared to close parentheses other wise string become invalid
        if(openCount > closeCount){
            temp += ')';
            backtrack(openCount, closeCount + 1, n, res, temp);
            // backtrack
            temp.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string>res;
        string temp = "";
        // initially opencount nd closecount both are zero
        // the idea behind this approach is instead of building string first
        // and checking later here we build valid string from the beginning
        backtrack(0, 0, n, res, temp);
        return res;
    }
};
