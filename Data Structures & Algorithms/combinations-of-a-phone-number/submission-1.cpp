class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};

        vector<string> res = {""};
        vector<string> digitToChar = {
            "", "", "abc", "def", "ghi", "jkl",
            "mno", "qprs", "tuv", "wxyz"
        };

        // Process each digit one by one
        for(char digit : digits) {
            // Temporary vector to store new combinations
            vector<string> temp;
             // Go through all existing combinations
                for(string& currStr : res) {
                    for(char ch : digitToChar[digit - '0']) {
                        // Create new combination by adding current letter
                        // to existing string and store it
                        temp.push_back(currStr + ch);
                    }
                }

                // After processing current digit,
                // update result with newly built combinations
                res = temp;
            }
        return res;
    }
};
