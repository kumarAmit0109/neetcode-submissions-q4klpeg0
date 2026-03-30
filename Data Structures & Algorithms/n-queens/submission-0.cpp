class Solution {
public:
    bool isSafe(int r, int c, vector<string>& board){
        // check upper col whether queen exist or not in same column
        for(int i = r - 1; i >= 0; i--){
            if(board[i][c] == 'Q'){
                return false;
            }
        }

        // check in left upward diagonal
        for(int i = r-1, j = c-1; i>=0 && j >=0; i--, j--){
            if(board[i][j] == 'Q'){
                return false;
            }
        }
        // check in right upward diagonal
        for(int i = r-1, j = c+1; i>=0 && j < board.size(); i--, j++){
            if(board[i][j] == 'Q'){
                return false;
            }
        }
        return true;
    }
    void backtrack(int r, vector<string>& board, vector<vector<string>>& res){
        // if r becomes equal to n or boardsize then it simply means all
        // the queens placed already so store nd result
        if(r == board.size()){
            res.push_back(board);
            return;
        }

        // strting from first column position strt placing the queen
        for(int c = 0; c < board.size(); c++){
            if(isSafe(r, c, board)){
                board[r][c] = 'Q';
                // make call for next row
                backtrack(r+1, board, res);
                // backtracking
                board[r][c] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>res;
        // create an empty chess board
        vector<string> board(n, string(n, '.'));
        backtrack(0, board, res);
        return res;
    }
};
