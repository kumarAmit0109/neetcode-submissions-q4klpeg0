class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int maxArea = 0;

        // Stack to store indices of histogram bars
        // Bars are stored in increasing height order
        stack<int> st;

        // Traverse all bars (extra iteration for emptying the stack)
        for(int i = 0; i <= n; i++) {

            // Process bars that are taller than the current bar
            // If i == n, we process all remaining bars in the stack
            while(!st.empty() && (i == n || heights[st.top()] >= heights[i])) {

                // Height of the rectangle
                int height = heights[st.top()];
                st.pop();

                // Calculate width of rectangle
                // If stack is empty, width is i
                // Else, width is distance between current index and stack top
                int width = st.empty() ? i : i - st.top() - 1;

                // Update maximum area
                maxArea = max(maxArea, height * width);
            }

            // Push current index to stack
            st.push(i);
        }

        return maxArea;
    }
};
