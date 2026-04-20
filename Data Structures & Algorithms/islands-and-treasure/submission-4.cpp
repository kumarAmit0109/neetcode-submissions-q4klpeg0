class Solution {
public:
    int INF = 2147483647;

    int bfs(vector<vector<int>>& grid, int r, int c, vector<pair<int,int>>directions){
        int rows = grid.size();
        int cols = grid[0].size();
         vector<vector<bool>>visited(rows, vector<bool>(cols, false));
        queue<pair<int,int>>que;
        que.push({r,c});
        visited[r][c] = true;

        int steps = 0;

        while(!que.empty()){
            int size = que.size();

            for(int i = 0; i < size; i++){
                auto [row, col] = que.front();
                que.pop();

                // if we reach treasure return steps
                if(grid[row][col] == 0){
                    return steps;
                }

                // traverse all four directions
                for(auto& dir : directions){
                    int newR = row + dir.first;
                    int newC = col + dir.second;
                    // if the position is within grid, and position doesnot contain water and
                    // itnot visited then, visit it and make it entry in queue
                    if((newR >= 0 && newR < rows) && (newC >= 0 && newC < cols) && grid[newR][newC] != -1
                    && !visited[newR][newC]){
                        
                        visited[newR][newC] = true;
                        que.push({newR, newC});
                    }
                }
            }
            // after completing a level simply increase the steps
            steps++;
        }
        
        return INF;
        
    }
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        vector<pair<int,int>>directions = {{0,1}, {0,-1}, {1,0}, {-1,0}};
       
        // for every land position, call the bfs to find the
        // treasure at minimum distance
        for(int r = 0; r < rows; r++){
            for(int c = 0; c < cols; c++){
                if(grid[r][c] == INF){
                    int minDis = bfs(grid, r, c, directions);
                    grid[r][c] = minDis;
                }
            }
        }
        
    }
};
