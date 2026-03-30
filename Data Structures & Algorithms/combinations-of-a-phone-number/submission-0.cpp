class Solution {
public:
    vector<string> digitToChar = {"", "", "abc", "def", "ghi", "jkl",
                                  "mno", "qprs", "tuv", "wxyz"};

    void backtrack(int indx, string temp, string& digits, vector<string>&res){
        if(temp.size() == digits.size()){
            res.push_back(temp);
            return;
        }

        string chars = digitToChar[digits[indx] - '0'];
        for(char ch : chars){
            backtrack(indx+1, temp+ch, digits, res);
        }
    }
    
    vector<string> letterCombinations(string digits) {
        vector<string>res;
        if(digits.empty()){
            return res;
        }
        backtrack(0, "", digits, res);
        return res;
    }
};
