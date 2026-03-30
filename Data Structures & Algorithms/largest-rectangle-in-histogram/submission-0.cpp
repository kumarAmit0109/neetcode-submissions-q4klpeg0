class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int maxArea = 0;

        for(int i = 0; i < n; i++){
            int height = heights[i];
            
            int right = i + 1;
            while(right < n){
                if(heights[right] < height){
                    break;
                }
                right++;
            }

            int left = i;
            while(left >= 0 ){
                if(heights[left] < height){
                    break;
                }
                left--;
            }

            int tempArea = height * (right - left - 1);
            maxArea = max(maxArea, tempArea);
        }
        return maxArea;
    }
};
