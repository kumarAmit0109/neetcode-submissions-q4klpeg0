class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // if at any moment sum become the zero then, reset the current sum
        int maxSum = -1, curSum = 0;
        for (int num : nums) {
            if (curSum < 0) {
                curSum = 0;
            }
            curSum += num;
            maxSum = max(maxSum, curSum);
        }
        return maxSum;
    }
};