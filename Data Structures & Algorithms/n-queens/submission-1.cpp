class Solution {
public:
    // create set to track the column, left and right upward diagonal
    unordered_set<int>col;
    unordered_set<int>leftDiagonal; // row - col
    unordered_set<int>rightDiagonal; // row + col
   
    void backtrack(int r, vector<string>& board, vector<vector<string>>& res){
        // if r becomes equal to n or boardsize then it simply means all
        // the queens placed already so store nd result
        if(r == board.size()){
            res.push_back(board);
            return;
        }

        // strting from first column position strt placing the queen
        for(int c = 0; c < board.size(); c++){
                if(col.count(c) || leftDiagonal.count(r - c) || rightDiagonal.count(r + c)){
                    continue;
                }
                // store indexes, row - column, row + coulmn  for keep track in column, 
                // leftDiagonal, rightDiagonal set respectively
                col.insert(c);
                rightDiagonal.insert(r + c);
                leftDiagonal.insert(r - c);
                board[r][c] = 'Q';
                // make call for next row
                backtrack(r+1, board, res);
                // backtracking
                col.erase(c);
                rightDiagonal.erase(r + c);
                leftDiagonal.erase(r - c);
                board[r][c] = '.';
            
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
