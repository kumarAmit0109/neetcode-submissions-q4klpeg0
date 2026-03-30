class Solution {
public:
    int maxArea(vector<int>& heights) {
        int i = 0, j = heights.size() - 1;
        int area = 0;

        while (i < j) {
            int height = min(heights[i], heights[j]);
            int breadth = j - i;

            area = max(area, height * breadth);

            if (heights[i] < heights[j]) {
                i++;
            } else {
                j--;
            }
        }
        return area;
    }
};
