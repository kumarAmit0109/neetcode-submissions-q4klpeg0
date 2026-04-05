class Solution {
public:
    vector<pair<int,int>>directions = {{0,1}, {0,-1}, {1,0}, {-1,0}};

    void dfs(int r, int c, vector<vector<bool>>& visited, vector<vector<int>>& heights){
        
        visited[r][c] = true;
        for(auto dir : directions){
            int newR = r + dir.first;
            int newC = c + dir.second;

            // if its within range, and not visited, and heights of new position
            // is greater than curr one then make nxt recursion call
            if((newR >= 0 && newR < heights.size()) && (newC >=0 && newC < heights[0].size())
            && !visited[newR][newC] && heights[newR][newC] >= heights[r][c]){
                dfs(newR, newC, visited, heights);
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        // instead of starting from every cell, we reverse the thinking:
        // start from the ocean borders and move uphill/flat (to neighbours with
        // height >= current)
        // step 1 : from all pacific border cell mark all reachable cells in pac
        // step 2 : from all atlantic border cell mark all reachable cells in atl
        // ans is cells that are in both sets

        int rows = heights.size();
        int cols = heights[0].size();

        vector<vector<bool>>pac(rows, vector<bool>(cols, false));
        vector<vector<bool>>alt(rows, vector<bool>(cols, false));

        for(int c = 0; c < cols; c++){
            // start dfs from the pacific cells (first row)
            dfs(0, c, pac, heights);
            // start dfs from atlantic cells (last row)
            dfs(rows-1, c, alt, heights);
        }
        
        for(int r = 0; r < rows; r++){
            // start dfs from the pacific cells (first col)
            dfs(r, 0, pac, heights);
            // start dfs from atlantic cells (last col)
            dfs(r, cols-1, alt, heights);
        }

        // find the cells whose pac and alt both are mark true
        vector<vector<int>>res;
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(pac[i][j] && alt[i][j]){
                    res.push_back({i,j});
                }
            }
        }
        return res;
    }
};
