class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int rows[9] = {0};
        int cols[9] = {0};
        int squares[9] = {0};

        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                if(board[i][j] == '.'){
                    continue;
                }
                int val = board[i][j] - '1'; // subtracting bcoz shifting mapping one step left, like 1 ->0, 2->1,..
                int bitmask = 1 << val;

                if((rows[i] & bitmask) || (cols[j] & bitmask) || (squares[(i/3)*3 + (j/3)] & bitmask)){
                    return false;
                }
                rows[i] |= (1 << val);
                cols[j] |= (1 << val);
                squares[(i/3) * 3 + (j/3)] |= (1 << val);
            }
        }
        return true;
    }
};
