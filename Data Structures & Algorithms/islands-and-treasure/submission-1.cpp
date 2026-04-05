class Solution {
public:
    int INF = 2147483647;

    int dfs(vector<vector<int>>& grid, int r, int c, vector<vector<bool>>visited, vector<pair<int,int>>directions){
        int rows = grid.size();
        int cols = grid[0].size();

        // if the position is out of grid, or position contain water or
        // it already visited then simply return INF indicating not reachable gate
        if((r < 0 || r >= rows) || (c < 0 || c >= cols) || grid[r][c] == -1
        || visited[r][c]){
            return INF;
        }

        // if the position contain already treasure, then return 0 distance
        if(grid[r][c] == 0){
            return 0;
        }

        // in other case make call in all direction for minimum direction
        visited[r][c] = true;
        int res = INF;
        
        for(auto& dir : directions){
            int newR = r + dir.first;
            int newC = c + dir.second;
            int temp = dfs(grid, newR, newC, visited, directions);

            if(temp != INF){
                res = min(res, 1 + temp);
            }
        }

        // after visiting this mark unvisited so can be used in other call
        visited[r][c] = false;
        return res;


        
    }
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        vector<pair<int,int>>directions = {{0,1}, {0,-1}, {1,0}, {-1,0}};
        vector<vector<bool>>visited(rows, vector<bool>(cols, false));
        // for every land position, call the dfs to find the
        // treasure at minimum distance
        for(int r = 0; r < rows; r++){
            for(int c = 0; c < cols; c++){
                if(grid[r][c] == INF){
                    int minDis = dfs(grid, r, c, visited, directions);
                    grid[r][c] = minDis;
                }
            }
        }
        
    }
};
