class Solution {
public:
    void capture(vector<vector<char>>& board, int rows, int cols, vector<pair<int, int>>& directions){
        queue<pair<int, int>>que;

        // push all the boundary level 'O'
        for(int r = 0; r < rows; r++){
            for(int c = 0; c < cols; c++){
                if(((r == 0 || r == rows-1) || (c == 0 || c == cols-1)) && board[r][c] == 'O'){
                    que.push({r,c});
                }
            }
        }

        while(!que.empty()){
            auto [ r, c ] = que.front();
            que.pop();

            // if it 'O' mark them 'T' and explore in all direction
            if(board[r][c] == 'O'){
                board[r][c] = 'T';

                for(auto dir : directions){
                    int newR = r + dir.first;
                    int newC = c + dir.second;
                    // if new postions are within bound then push it into que
                    if( (newR >= 0 && newR < rows) && (newC >= 0 && newC < cols)){
                        que.push({newR, newC});
                    }
                }
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        // same as previous but here we do multi source bfs traversal
        // initially push all the border 'O' cells in queue and mark every
        // reachable 'O' as temorary 'T' 

        // after that leftover 'O' are full surrounded so flip them to 'X'
        // 'T' cells are safe so change them back to 'O'

        int rows = board.size();
        int cols = board[0].size();
        vector<pair<int, int>> directions = {{1,0}, {-1,0}, {0,1}, {0,-1}};
                                         
        // used to capture non surrounded 'O' and mark them to 'T'
        capture(board, rows, cols, directions);

        // if there are temporary T so change them back to O
        // and if there are surrounded O so simply change them to X
        for(int r = 0; r < rows; r++){
            for(int c = 0; c < cols; c++){
                if(board[r][c] == 'O'){
                    board[r][c] = 'X';
                }else if(board[r][c] == 'T'){
                    board[r][c] = 'O';
                }
            }
        }
    }
};
