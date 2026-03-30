class Solution {
public:
   
   
    void backtrack(int r, vector<string>& board, vector<vector<string>>& res, 
            vector<bool>&col, vector<bool>&leftDiagonal, vector<bool>& rightDiagonal){
        // if r becomes equal to n or boardsize then it simply means all
        // the queens placed already so store nd result
        if(r == board.size()){
            res.push_back(board);
            return;
        }

        // strting from first column position strt placing the queen
        for(int c = 0; c < board.size(); c++){
                if(col[c] || leftDiagonal[r - c + board.size()] || rightDiagonal[r + c]){
                    continue;
                }
                // store indexes, row - column, row + coulmn  for keep track in column, 
                // leftDiagonal, rightDiagonal set respectively
                col[c] = true;
                rightDiagonal[r + c] = true;
                leftDiagonal[r - c + board.size()] = true;
                board[r][c] = 'Q';
                // make call for next row
                backtrack(r+1, board, res, col, leftDiagonal, rightDiagonal);
                // backtracking
                col[c] = false;
                rightDiagonal[r + c] = false;
                leftDiagonal[r - c + board.size()] = false;
                board[r][c] = '.';
            
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>res;
        // create an empty chess board
        vector<string> board(n, string(n, '.'));
         // create vectors to track the column, left and right upward diagonal
        vector<bool>col(n, false);
        vector<bool>leftDiagonal(2 *n, false); // row - col + n (we add n in order to shift so avoid negative indexing )
        vector<bool>rightDiagonal(2*n, false); // row + col
        backtrack(0, board, res, col, leftDiagonal, rightDiagonal);
        return res;
    }
};
