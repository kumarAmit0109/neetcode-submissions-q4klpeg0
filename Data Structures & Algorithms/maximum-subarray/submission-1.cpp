class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // for every subarray find the sum of that subarray nd update the
        // maxsum 
        int n = nums.size();
        int maxSum = -1;

        for(int i = 0; i < n; i++){
            int currSum = 0;
            for(int j = i; j < n; j++){
                currSum += nums[j];
                maxSum = max(maxSum, currSum);
            }
            

        }
        return maxSum;
    }
};