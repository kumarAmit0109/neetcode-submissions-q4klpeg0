class Solution {
public:
    int dfs(vector<vector<int>>& grid, int r, int c, vector<pair<int,int>>& direction){
        int rows = grid.size();
        int cols = grid[0].size();

        // base case: out of bounds OR water
        if(r < 0 || r >= rows || c < 0 || c >= cols || grid[r][c] == 0){
            return 0;
        }
        // mark current cell as visited (turn land into water)
        grid[r][c] = 0;
        int area = 1; // current cell
        // explore all 4 directions
        for(auto dir : direction){
            int newR = r + dir.first;
            int newC = c + dir.second;
            area += dfs(grid, newR, newC, direction);
        }

        return area;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int maxArea = 0;

        vector<pair<int,int>> direction = {
            {1,0}, {-1,0}, {0,1}, {0,-1}
        };

        // traverse the grid
        for(int r = 0; r < rows; r++){
            for(int c = 0; c < cols; c++){
                if(grid[r][c] == 1){  // found land
                    int area = dfs(grid, r, c, direction);
                    maxArea = max(maxArea, area);
                }
            }
        }

        return maxArea;
    }
};