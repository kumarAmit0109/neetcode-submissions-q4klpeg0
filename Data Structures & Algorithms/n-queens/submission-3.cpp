class Solution {
public:
    // instead of set or vector we use bit mask to keep track of placed queen
    int col = 0, leftDiagonal = 0, rightDiagonal = 0;

    void backtrack(int r, vector<string>& board, vector<vector<string>>& res){
        // if r becomes equal to n or boardsize then it simply means all
        // the queens placed already so store nd result
        if(r == board.size()){
            res.push_back(board);
            return;
        }

        for(int c = 0; c < board.size(); c++){
            if((col & (1 << c)) || (rightDiagonal &(1<<(r+c))) 
                || (leftDiagonal &( 1 <<(r - c + board.size())))){
                    continue;
                }

            col ^= (1 << c);
            rightDiagonal ^= (1<<(r+c));
            leftDiagonal ^= (1<< (r - c + board.size()));
            board[r][c] = 'Q';

            backtrack(r+1, board, res);
            // backtracking
            board[r][c] = '.';
            // Unmark bits (toggle back using XOR)
            col ^= (1 << c);
            rightDiagonal ^= (1<<(r+c));
            leftDiagonal ^= (1<< (r - c + board.size()));
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
