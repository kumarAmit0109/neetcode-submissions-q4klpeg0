class Solution {
public:
    bool isPalindrome(string s, int left, int right){
        while(left < right ){
            if(s[left]!= s[right]){
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
    int countSubstrings(string s) {
        int cnt = 0;
        // simply generate all sustring and then check if it is 
        // palindrome or not if yes then increase cnt
        for(int i = 0; i < s.size(); i++){
            for(int j = i; j < s.size(); j++){
                if(isPalindrome(s, i, j)){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
