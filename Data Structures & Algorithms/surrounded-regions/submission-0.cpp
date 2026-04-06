class Solution {
public:
    void capture(vector<vector<char>>& board, int r, int c) {
        int rows = board.size();
        int cols = board[0].size();
        // if the position is outof bound or not 'O' (means either it's 'X' or already visited 'T')
        if ((r < 0 ||  r >= rows)|| (c < 0|| c >= cols) || board[r][c] != 'O'){
            return;
        }

        board[r][c] = 'T';
        // capture in all direction
        capture(board, r + 1, c);
        capture(board, r - 1, c);
        capture(board, r, c + 1);
        capture(board, r, c - 1);
    }

    void solve(vector<vector<char>>& board) {
        // think in reverse direction, instead of capturing the surrounding 
        // region we do the capture everything except the unsurrounding region
        int rows = board.size();
        int cols = board[0].size();

        // first mark the all border-connected 'O' cells as safe (teporary
        // mark "T")

        // now any remaining 'O' is truly surrounded so flip it to 'X'
        // and later on convert temporary 'T' back to 'O'

        // capture left nd right boundary
        for (int r = 0; r < rows; r++) {
            if (board[r][0] == 'O') {
                capture(board, r, 0);
            }
            if (board[r][cols - 1] == 'O') {
                capture(board, r, cols - 1);
            }
        }
        // capture top and bottom boundary
        for (int c = 0; c < cols; c++) {
            if (board[0][c] == 'O') {
                capture(board, 0, c);
            }
            if (board[rows - 1][c] == 'O') {
                capture(board, rows - 1, c);
            }
        }


        // now final conversion convert 'O' to 'X'
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (board[r][c] == 'O') {
                    board[r][c] = 'X';
                } else if (board[r][c] == 'T') {
                    board[r][c] = 'O';
                }
            }
        }
    }
};
