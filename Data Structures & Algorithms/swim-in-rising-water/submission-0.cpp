class Solution {
public:
    vector<pair<int,int>>direction = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    int dfs(int r, int c, int time, vector<vector<int>>& grid, vector<vector<bool>>& visited){
        int n = grid.size();
        // if we reach outof bound and visited simply return dummy value
        if((r < 0 || r >= n) || (c < 0 || c >=n) || visited[r][c]){
            return INT_MAX;
        }

        // if we reach end simply return the time taken to reach it
        // max time at any point is the max of curr time and height of that cell
        if(r == n-1 && c == n-1){
            return max(time, grid[r][c]);
        }

        visited[r][c] = true;
        time = max(time, grid[r][c]);

        // explore all directions
        int res = INT_MAX;
        for(auto dir : direction){
            int nr = r + dir.first;
            int nc = c + dir.second;
            int temp = dfs(nr, nc, time, grid, visited);
            res = min(res, temp);
        }
        // mark visited false for backtracking
        visited[r][c] = false;
        return res;
    }
    int swimInWater(vector<vector<int>>& grid) {
        // explore all possible paths from (0,0) to (n-1, n-1) nd
        // time for that path is the maximum height you reached so far
        // for the our solution we have to minimize the time so for each
        // step minimize the time
        int n = grid.size();
        vector<vector<bool>>visited(n, vector<bool>(n, false));
        // initially start with (0,0) position with time 0
        int ans = dfs(0, 0, 0, grid, visited);
        return ans;
    }
};
