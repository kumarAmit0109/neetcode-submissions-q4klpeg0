class Solution {
public:
    int backtrack(int indx, int sum, vector<int>& nums, int target){
        // if we reach end of nums, then simply return whether the sum
        // is equal to target or not in the end
        if(indx == nums.size()){
            return sum == target;
        }
        // add nums[i] to current sum nd make a call for nxt one
        int opt1 = backtrack(indx+1, sum + nums[indx], nums, target);
        // subtract nums[i] from the current sum nd make a call for nxt one
        int opt2 = backtrack(indx+1, sum - nums[indx], nums, target);
        return opt1 + opt2;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        // initially start with 0th index nd sum as 0 
        int ans = backtrack(0, 0, nums, target);
        return ans;
    }
};
