class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        queue<pair<int,int>>que;
        // start the bfs traversal with the all the treasure point at the
        // same time to find the nearst land.(here we reverse the problem, now
        // we are finding the nearest land positons from each treasure point)
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(grid[i][j] == 0){
                    que.push({i, j});
                }
            }
        }

        vector<pair<int,int>>directions = {{0,1}, {0,-1}, {1,0}, {-1,0}};

        while(!que.empty()){
            int r = que.front().first;
            int c = que.front().second;
            que.pop();

            for(auto dir : directions){
                int newR = r + dir.first;
                int newC = c + dir.second;
                
                // if the positon is outof grid or contains not land simply continue,
                // else store the treasure dis as one more distance from the front position 
                // distance from the treasure
                if((newR < 0 || newR >= rows) || (newC < 0 || newC >= cols)
                || grid[newR][newC] != INT_MAX){
                    continue;
                }

                grid[newR][newC] = grid[r][c] + 1;
                que.push({newR, newC});
            }
        }
        
    }
};
