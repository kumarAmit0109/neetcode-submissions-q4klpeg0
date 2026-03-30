class Solution {
public:
    // here we will use the board to keep track of the cell used or not
    // like after using we replace it with any character like '#' and check
    // if its already mark '#' then return false 

    bool isFound(vector<vector<char>>& board, string word, int r, int c, int rows, int cols, int i){
        if(i == word.length()){
            return true;
        }

        // check if the node is out of range or char is already visited or
        // curr char is  not equal to word char so in those case return false
        if( r < 0 || c < 0 || r >= rows || c >= cols ||
            board[r][c] == '#' ||
            board[r][c] != word[i]
            ){
                return false;
            }

        // make call in each direction left, right, up, down
        char ch = board[r][c];
        board[r][c] = '#';
        bool left = isFound(board, word, r-1, c, rows, cols, i+1);
        bool right = isFound(board, word, r+1, c, rows, cols, i+1);
        bool up = isFound(board, word, r, c+1, rows, cols, i+1);
        bool down = isFound(board, word, r, c-1, rows, cols, i+1);
        // backtrack
        board[r][c] = ch;

        return left || right || up || down;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int cols = board[0].size();

        // choose every cell as the starting point and strt searching for the word
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(isFound(board, word, i, j, rows, cols, 0)){
                    return true;
                }
            }
        }
        return false;
    }
};
