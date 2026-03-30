class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int>prevSmaller(n, -1);
        vector<int>nextSmaller(n, n);
        stack<int>st;

        // for finding previous smaller
        for(int i = 0; i < n; i++){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }
            if(!st.empty()){
                prevSmaller[i] = st.top();
            }
            st.push(i);
        }

        while(!st.empty()) st.pop();

        // for finding next smaller
        for(int i = n - 1; i >= 0; i--){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }
            if(!st.empty()){
                nextSmaller[i] = st.top();
            }
            st.push(i);
        }


        int maxArea = 0;
        for(int i = 0; i < n; i++){
            maxArea = max(maxArea, heights[i] * (nextSmaller[i] - prevSmaller[i] - 1));
        }

        return maxArea;
    }
};
