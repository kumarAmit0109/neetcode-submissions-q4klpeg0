class Solution {
public:
    bool alphaNum(char ch){
        if((ch >= 'a' && ch <='z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9')){
            return true;
        }
        return false;
    }
    bool isPalindrome(string s) {
        int strt = 0, end = end = s.length()-1;

        while(strt < end){
            while(strt < end && !alphaNum(s[strt])){
                strt++;
            }

            while(end > strt && !alphaNum(s[end])){
                end--;
            }
            if(tolower(s[strt]) != tolower(s[end])){
                return false;
            }
            strt++;
            end--;
        }
        return true;
    }
};
