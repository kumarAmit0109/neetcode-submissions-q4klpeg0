class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int rows = board.size();
        int cols = board[0].size();

        // row check
        for(int i = 0; i < rows; i++){
            unordered_set<char>seenRow;
            for(int j = 0; j < cols; j++){
                if(board[i][j] == '.'){
                    continue;
                }
                if(seenRow.count(board[i][j])){
                    return false;
                }
                seenRow.insert(board[i][j]);
            }
        }

        // column check
        for(int j = 0; j < cols; j++){
            unordered_set<char>seenCol;
            for(int i = 0; i < rows; i++){
                if(board[i][j] == '.'){
                    continue;
                }
                if(seenCol.count(board[i][j])){
                    return false;
                }
                seenCol.insert(board[i][j]);
            }
        }

        // Each 3 * 3 box check
        for(int square = 0; square < 9; square++){
            unordered_set<char>seen;
            for(int i = 0; i < 3; i++){
                for(int j = 0; j < 3; j++){
                    int row = (square / 3) * 3 + i;
                    int col = (square % 3) * 3 + j;
                    if(board[row][col] == '.'){
                        continue;
                    }
                    if(seen.count(board[row][col])){
                        return false;
                    }
                    seen.insert(board[row][col]);
                }
            }
        }
        return true;
    }
};
