class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = INT_MIN;

        // use brute force to find the max product 
        // for every subarray find the product nd update the maximum one
        for(int i = 0; i < nums.size(); i++){
            // fix the starting indx
            int curr = nums[i];
            res = max(res, curr);
            // now keep multiplying elements to the right nd keep track of
            // max product seen
            for(int j = i+1; j < nums.size(); j++){
                curr *= nums[j];
                res = max(res, curr);
            }
        }
        return res;
    }
};
