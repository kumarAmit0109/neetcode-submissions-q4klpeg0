class Solution {
public:
    int solve(vector<int>&nums, int i){
        if(i == 0){
            return nums[0];
        }

        if(i == 1){
            return max(nums[0], nums[1]);
        }

        // include the current element
        int res1 = solve(nums, i-2) + nums[i];
        // exclude the current element
        int res2 = solve(nums, i-1) + 0;
        return max(res1, res2);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        int ans = solve(nums, n-1);
        return ans;
    }
};
