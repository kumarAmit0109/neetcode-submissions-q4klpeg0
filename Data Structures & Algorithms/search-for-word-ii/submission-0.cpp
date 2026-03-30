class Solution {
public:

    bool backtrack(vector<vector<char>>& board, int r, int c, string& word, int indx){
        // if we reach the end means word found
        if(indx == word.size()){
            return true;
        }

        // if its not within range then return false,
        if((r < 0 || r >= board.size()) || (c < 0 || c >= board[0].size()) || board[r][c] != word[indx]){
            return false;
        }
        // we are using the "*" char as marking whether the char is already 
        // visited in the board or not instead of using the separate map for this
        char temp = board[r][c];
        board[r][c] = '*';
        
        vector<pair<int,int>>directions{{1,0}, {-1,0}, {0,1}, {0,-1}};
        for(auto dir : directions){
            int newr = r + dir.first;
            int newc = c + dir.second;
            if(backtrack(board, newr, newc, word, indx+1 )){
                // backtracking
                board[r][c] = temp; 
                return true;
            }
        }
        // backtracking
        board[r][c] = temp;
        return false;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int rows = board.size();
        int cols = board[0].size();

        vector<string>res;

        // check each word whether it can exist in the board or not if
        // not skip if yes then add it to the word
        for(string& word : words){
            bool flag = false;
            for(int r = 0; r < rows && flag == false; r++){
                for(int c = 0; c < cols; c++){
                    // if first character is not match simply continue
                    if(board[r][c] != word[0]){
                        continue;
                    }
                    // start the fxn call with the index 0
                    if(backtrack(board, r, c, word, 0)){
                        res.push_back(word);
                        flag = true;
                        break;
                    }

                }
            }
        }

        return res;
    }
};
