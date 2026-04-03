class Solution {
public:
    int bfs(vector<vector<int>>& grid, int r, int c, vector<pair<int,int>>& direction){
        int rows = grid.size();
        int cols = grid[0].size();
        queue<pair<int,int>>que;
        // visit the current land cell
        grid[r][c] = 0;
        que.push({r, c});
        int area = 1;
        while(!que.empty()){
            auto node = que.front();
            que.pop();
            int r = node.first;
            int c = node.second;
            // explore in all direction
            for(auto dir : direction){
                int newR = r + dir.first;
                int newC = c + dir.second;
                // if cell is  within range nd still land then visit it nd
                // simply create the entry in the que
                if((newR >=0 && newR < rows) && (newC >=0 && newC < cols) &&
                (grid[newR][newC] == 1)){
                    que.push({newR, newC});
                    grid[newR][newC] = 0;
                    area++;
                }
            } 
        }
        return area;
        
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        // think of problem is like no. of connected components
        int rows = grid.size();
        int cols = grid[0].size();
        int count = 0;

        vector<pair<int,int>>direction = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        // use grid itself as a matrix to mark whether the land cell is
        //  visited or not, (after visiting simply turn the land cell to water cell by making it 0 to indicate
        //  land cell is visited)
        int maxArea = 0;
        // instead of dfs use bfs here
        for(int r = 0; r < rows; r++){
            for(int c = 0; c < cols; c++){
                if( grid[r][c] == 1){
                    int area = bfs(grid, r, c, direction);
                    maxArea = max(area, maxArea);
                }
            }
        }
        return maxArea;
    }
};
