class Solution {
public:
    void dfs(vector<vector<int>>& heights, int r, int c, int preVal, bool& pacific, bool& atlantic, vector<pair<int,int>>& directions){
        // if we reach left-top out of bound reason means
        // we can reach pacific reason
        if(r < 0 || c < 0){
            pacific = true;
            return;
        }
        // if we reach right-bottom out of bound reason means
        // we can reach atlantic reason
        if(r >= heights.size() || c >= heights[0].size()){
            atlantic = true;
            return;
        }

        // if current height is greater than previos one means water cant flow here
        // so, simply return 
        if(heights[r][c] > preVal){
            return;
        }

        int temp = heights[r][c];
        // make curr height at int_max to mark it visited
        heights[r][c] = INT_MAX;

        // traverse in all 4 directions
        for(auto dir : directions){
            int newR = r + dir.first;
            int newC = c + dir.second;
            dfs(heights, newR, newC, temp, pacific, atlantic, directions);

            if(pacific && atlantic){
                break;
            }
        }
        // backtrack, restore original value
        heights[r][c] = temp;
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();
        vector<pair<int,int>>directions = {{0,1}, {0,-1}, {1,0}, {-1,0}};

        vector<vector<int>>ans;

        // for each position tries to find whether water can reach the both
        // pacific and atlanctic ocean if we start from there or not
        for(int r = 0; r < rows; r++){
            for(int c = 0; c < cols; c++){
                bool pacific = false;
                bool atlantic = false;
                // initially treat previous height as INT_MAX
                dfs(heights, r, c, INT_MAX, pacific, atlantic, directions);
                if(pacific && atlantic){
                    ans.push_back({r,c});
                }

            }
        }
        return ans;
    }
};
