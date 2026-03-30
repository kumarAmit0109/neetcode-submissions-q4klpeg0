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

    void solve(int indx, string& s, vector<string>& part){

        if(indx >= s.size()){
            res.push_back(part);  
            return;  
        }

        // Try all possible substrings starting from index 'indx'
        for(int j = indx; j < s.length(); j++){
            // check if string form indx to j, is palindrome then add it to
            // the part and call for rest of the s with j+1 as the indx 
            if(isPalindrome(s, indx, j)){
                part.push_back(s.substr(indx, j-indx+1));
                solve(j+1, s, part);
                // backtracking
                part.pop_back();
            }
        }
    
    }

    vector<vector<string>> partition(string s) {
        vector<string> part;   // current partition being built
        // Start recursion from index 0
        solve(0, s, part);  
        return res;
    }
};