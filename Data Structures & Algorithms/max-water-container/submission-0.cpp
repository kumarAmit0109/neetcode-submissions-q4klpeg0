class Solution {
public:
    int maxArea(vector<int>& heights) {
        int area = 0;
        int n = heights.size();
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                int length = j - i;
                int breadth = min(heights[i],heights[j]);
                area = max(area, length*breadth);
            }
        }
        return area;
    }
};
