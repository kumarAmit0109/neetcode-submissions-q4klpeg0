class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int>leftMax(n);
        vector<int>rightMax(n);

        leftMax[0] = height[0];
        rightMax[n-1] = height[n-1];

        // for leftMax
        int leftMaxi = height[0];
        for(int i = 1; i < n; i++){
            leftMax[i] = max(leftMaxi, height[i]);
            leftMaxi = leftMax[i];
        }

        // for rightMax
        int rightMaxi = height[n-1];
        for(int i = n-2; i >=0; i--){
            rightMax[i] = max(rightMaxi, height[i]);
            rightMaxi = rightMax[i];
        }

        int res = 0;
        for(int i = 0; i < n; i++){
            res += (min(leftMax[i], rightMax[i]) - height[i]);
        }
        return res;
    }
};
