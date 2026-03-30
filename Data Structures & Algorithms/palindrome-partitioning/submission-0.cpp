class Solution {
public:
    bool isPalindrome(string& str, int left, int right){
        while(left < right){
            if(str[left] != str[right]){
                return false;
            }
            left++;
            right--;
        }
        return true;
    }

    vector<vector<string>> res;  

    // strt = start index of current piece
    // end = end index we are currently trying
    void solve(int strt, int end, string& s, vector<string>& part){

        // Base case: end has gone past the end of the string
        if(end >= s.size()){
            // strt == end means strt is also past the end
            // i.e., every character was perfectly covered by palindrome pieces
            if(strt == end){
                res.push_back(part);  // valid partition found, save it
            }
            return;  
        }

        // Choice 1: if s[strt..end] is a palindrome, cut here
        if(isPalindrome(s, strt, end)){
            part.push_back(s.substr(strt, end - strt + 1));  // choose this piece
            solve(end + 1, end + 1, s, part);             // recurse: start fresh from end+1
            part.pop_back();                           // backtrack: undo the choice
        }

        // Choice 2: don't cut here, extend the current piece by moving end forward
        solve(strt, end + 1, s, part);
    }

    vector<vector<string>> partition(string s) {
        vector<string> part;   // current partition being built
        solve(0, 0, s, part);  // start with strt=0, end=0
        return res;
    }
};