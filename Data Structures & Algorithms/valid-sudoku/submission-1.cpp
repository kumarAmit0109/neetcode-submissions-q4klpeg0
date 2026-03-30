class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int rows = board.size();
        int cols = board[0].size();

        unordered_set<string>seen;
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(board[i][j] == '.'){
                    continue;
                }
            
                string row = string(1,board[i][j]) + "_row_" + to_string(i);
                string col = string(1,board[i][j]) + "_col_" + to_string(j);
                string square = string(1,board[i][j]) + "_square_" + to_string(i/3) + "_" + to_string(j/3);
        
                if(seen.count(row) || seen.count(col) || seen.count(square)){
                    return false;
                }
                seen.insert(row);
                seen.insert(col);
                seen.insert(square);

            }
        }
        return true;
    }
};
