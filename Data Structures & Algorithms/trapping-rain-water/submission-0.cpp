class Solution {
public:
    int trap(vector<int>& height) {
        if(height.empty()){
            return 0;
        }

        int n = height.size();
        int res = 0;

        for(int i = 0; i < n; i++){
            int leftMax = height[i];
            int rightMax = height[i];

            // finding leftMax from 0 to i-1
            for(int j = 0; j < i; j++){
                leftMax = max(leftMax, height[j]);
            }

            // finding rightMax from i+1 to n 
            for(int j = i+1; j < n; j++){
                rightMax = max(rightMax, height[j]);
            }

            res += (min(leftMax , rightMax) - height[i]);
            
        }
        return res;
    }
};
