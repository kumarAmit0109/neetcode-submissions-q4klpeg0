class Solution {
public:
    void solve(int rows, int cols, pair<int,int> pos, pair<int,int> dir,
            vector<vector<int>>& matrix, vector<int>& res){
        
        // means nothing to process 
        if(rows == 0 || cols == 0){
            return;
        }
        int dr = dir.first;
        int dc = dir.second;

        int r = pos.first;
        int c = pos.second;
        // strt traversing first row
        for(int i = 0; i < cols; i++){
            r += dr;
            c += dc;
            res.push_back(matrix[r][c]);
        }
        // new position should be the last visited cell
        pair<int,int>newPos = {r, c};
        // directions moves from (0,1) -> (1,0) -> (0,-1) -> (-1,0)
        pair<int,int>newDir = {dc, -dr}; 

        // after one recursion rows -1 becomes new cols (as one row is process alreadu) 
        // and cols becomes new rows
        solve(cols, rows-1, newPos, newDir, matrix, res);  
    }

    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<int>res;
        // initially keep the current positon as (0, -1) so after moving 
        // right we get to (0,0) position
        pair<int,int>pos = {0, -1};
        // initially keep direction as (0, 1);
        pair<int,int>dir = {0, 1};
        
        solve(rows, cols, pos, dir, matrix, res);

        return res;

    }
};
