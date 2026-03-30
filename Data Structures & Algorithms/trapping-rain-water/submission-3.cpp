class Solution {
public:
    int trap(vector<int>& height) {
        if(height.empty()){
            return 0;
        }

        stack<int>stk;
        int res =  0;

        for(int i = 0; i < height.size(); i++){
            while(!stk.empty() && height[i] > height[stk.top()]){
                int bottom = height[stk.top()];
                stk.pop();
                if(!stk.empty()){
                    int rightWall = height[i];
                    int leftWall = height[stk.top()];
                    int ht = min(rightWall, leftWall) - bottom;
                    int wdth = i - stk.top() - 1;
                    res += ht * wdth;
                }
            }
            stk.push(i);
        }
        return res;
    }
};
