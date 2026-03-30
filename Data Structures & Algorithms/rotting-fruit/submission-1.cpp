class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int fresh = 0, time = 0;

        for (int r = 0; r < rows; r++){
            for (int c = 0; c < cols; c++){
                if (grid[r][c] == 1){
                    fresh++;
                }
            }
        }

        vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        // simulate minute by minute until all fresh oranges are rotten
        while (fresh > 0){
            // flag to check if any orange rots in this minute
            bool flag = false;
            // scan the whole grid
            for (int r = 0; r < rows; r++){
                for (int c = 0; c < cols; c++){
                    // if current cell is rotten, then rott in all direction
                    if (grid[r][c] == 2){
                        for (auto& d : directions){
                            int row = r + d[0], col = c + d[1];
                            // check bounds and if neighbor is fresh, if yes then mark it 3 , which 
                            // indicates its freshly rotten nd can be used in nxt cycle plus decrese
                            // the fresh count
                            if ((row >= 0 && row < rows) && (col >= 0 && col < cols) && grid[row][col] == 1){
                                grid[row][col] = 3;
                                fresh--;
                                flag = true;
                            }
                        }
                    }
                }
            }
            // if flag doesnt change means no orange rotted in this minute but fresh still exist
            // indicating impossible to rot all oranges
            if (!flag){
                return -1;
            }

            // convert all 3 to 2 , so it can be used in next cycle 
            for (int r = 0; r < rows; r++){
                for (int c = 0; c < cols; c++){
                    if (grid[r][c] == 3){
                        grid[r][c] = 2;
                    } 
                }
            }
            // increase time after one full level (minute)
            time++;
        }

        return time;
    }
};