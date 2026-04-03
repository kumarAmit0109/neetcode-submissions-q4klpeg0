class Solution {
public:
    void dfs(vector<vector<char>>& grid, int r, int c, vector<pair<int,int>>& direction){
        int rows = grid.size();
        int cols = grid[0].size();
        // if cell is not within range or its water or its visited simply return

        if((r < 0 || r >= rows) || (c < 0 || c >= cols) || grid[r][c] == '0' 
            || grid[r][c] == 'v'){
                return;
            }

        // visit the current land cell
        grid[r][c] = 'v';
        // explore in all direction
        for(auto dir : direction){
            int newR = r + dir.first;
            int newC = c + dir.second;
            dfs(grid, newR, newC, direction);
        } 
    }
    int numIslands(vector<vector<char>>& grid) {
        // think of problem is like no. of connected components
        int rows = grid.size();
        int cols = grid[0].size();
        int count = 0;

        vector<pair<int,int>>direction = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        // use grid itself as a matrix to mark whether the land cell is
        //  visited or not, (after visiting simply turn the value to 'v' to indicate
        //  land cell is visited)
        for(int r = 0; r < rows; r++){
            for(int c = 0; c < cols; c++){
                if( grid[r][c] == '1'){
                    dfs(grid, r, c, direction);
                    count++;
                }
            }
        }
        return count;
    }
};
