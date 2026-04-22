class Solution {
public:
    vector<pair<int,int>>directions = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    bool isPossible(vector<vector<int>>& grid, vector<vector<bool>>& visited, int r, int c, int t){

        // if we reach out of bound or already visited node or height is greater than time
        // so return false
        if((r < 0 || r >= grid.size()) || (c < 0 || c >= grid.size()) || visited[r][c] || grid[r][c] > t){
            return false;
        }

        if(r == grid.size() - 1 && c == grid.size() - 1){
            return true;
        }

        visited[r][c] = true;
        for(auto dir : directions){
            int nr = r + dir.first;
            int nc = c + dir.second;
            if(isPossible(grid, visited, nr, nc, t)){
                return true;
            }
        }
        return false;
        
    }
                                        
    int swimInWater(vector<vector<int>>& grid) {
        // simply check that with water level t, can we reach the end nd
        // return that the minimum value of that water level, the range of t
        // on which we will check will be between min to max values of heights in 
        // given grid

        // same as previous but now instead of checking every element in minH to maxH range
        // use binary search to get min time 

        int n = grid.size();
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        int minH = grid[0][0], maxH = grid[0][0];
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                maxH = max(maxH, grid[row][col]);
                minH = min(minH, grid[row][col]);
            }
        }

        // now return the min possible value of t if its possible to
        // reach the end for that value of t
        int left = minH, right = maxH;
        while(left < right){
            int mid = (left + right)/2;
            
            if(isPossible(grid, visited, 0, 0, mid)){
                right = mid;
            }else{
                left = mid+1;
            }

            // re initiallize the visited vector for nxt cycle
            for(int i = 0; i < n; i++){
                fill(visited[i].begin(), visited[i].end(), false);
            }
        }
        return right;
        
    }
};
