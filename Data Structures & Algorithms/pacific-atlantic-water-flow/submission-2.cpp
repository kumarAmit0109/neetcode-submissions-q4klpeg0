class Solution {
public:
    vector<pair<int,int>>directions = {{0,1}, {0,-1}, {1,0}, {-1,0}};

    void bfs(queue<pair<int,int>>& que, vector<vector<bool>>& visited, vector<vector<int>>& heights){
        while(!que.empty()){
            auto [r,c] = que.front();
            que.pop();

            visited[r][c] = true;
            for(auto dir : directions){
                int newR = r + dir.first;
                int newC = c + dir.second;

                // if its within range, and not visited, and heights of new position
                // is greater than curr one then make its entry in queue
                if((newR >= 0 && newR < heights.size()) && (newC >=0 && newC < heights[0].size())
                && !visited[newR][newC] && heights[newR][newC] >= heights[r][c]){
                    que.push({newR, newC});
                }
            }
        }
        
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        // idea is same as previous thinking in the reverse direction 
        // but here we are using the multi-source bfs traversal one with
        // pacific border cells as sources and other with the atlantic border
        // cells as the sources
        int rows = heights.size();
        int cols = heights[0].size();

        vector<vector<bool>>pac(rows, vector<bool>(cols, false));
        vector<vector<bool>>alt(rows, vector<bool>(cols, false));

        queue<pair<int,int>>pacQue;
        queue<pair<int,int>>altQue;

        for(int c = 0; c < cols; c++){
            //push pacific cells (first row) in pacQue
            pacQue.push({0, c});
            //push atlantic cells (last row) in altQue
            altQue.push({rows-1, c});
        }
        
        for(int r = 0; r < rows; r++){
            // push the pacific cells (first col) in pacQue
            pacQue.push({r, 0});
            // push the atlantic cells (last col) in altQue
            altQue.push({r, cols-1});
        }

        // call bfs with pacific queue and atlantic queue
        bfs(pacQue, pac, heights);
        bfs(altQue, alt, heights);

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
