class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        // its the similar ques to min time required to burn the tree completely
        // make a que for bfs traversal nd initialize with the position of the
        // rotten fruits initially 
        queue<pair<int,int>> que;
        int freshCount = 0;
        int time = 0;

        int rows = grid.size();
        int cols = grid[0].size();
        for(int r = 0; r < rows; r++){
            for(int c = 0; c < cols; c++){
                // val = 1 indicates the fresh fruit
                if(grid[r][c] == 1){
                    freshCount++;
                }

                // val = 2 indicates the rotten fruit so make the
                // entry in the que
                if(grid[r][c] == 2){
                    que.push({r, c});
                }
            }
        }

        vector<pair<int,int>>directions = {{0,1}, {0,-1}, {1,0}, {-1,0}};
        
        // start the bfs traversal
        while(freshCount > 0 && !que.empty()){
            int len = que.size();

            // now for each rotten fruits in que till now , 
            // traverse in each 4 direction nd if fresh fruit exist make it
            // rotten nd decrease count nd store in que
            for(int i = 0; i < len; i++){
                auto curr = que.front();
                que.pop();
                int r = curr.first;
                int c = curr.second;

                // traverse in all 4 direction
                for(const auto& dir : directions){
                    int newR = r + dir.first;
                    int newC = c + dir.second;
                    // if newposition is within range + having fresh fruit then mark it rotten nd
                    // make it enty in que + decrease the fresh fruit count
                    if((newR >= 0 && newR < rows) && (newC >=0 && newC <cols) && (grid[newR][newC] == 1)){
                        grid[newR][newC] = 2;
                        que.push({newR, newC});
                        freshCount--;
                    }
                }
            }

            time++;
        }

        // if at the end of traversal we still have any fresh fruit then
        // it's not possible to rott every fruit so return -1 else return time
        if(freshCount == 0){
            return time;
        }else{
            return -1;
        }
    }
};
