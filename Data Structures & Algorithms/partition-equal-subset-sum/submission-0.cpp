class Solution {
public:
    bool dfs(vector<int>& nums, int indx, int target){
        // if we reach the end simply return whether we are able
        // to meet the target or not
        if(indx == nums.size()){
            return target == 0;
        }
        // if at any point we have to form -ve target simply return 0
        if(target < 0){
            return 0;
        }

        bool include = dfs(nums, indx+1, target - nums[indx]);
        bool exclude = dfs(nums, indx+1, target);
        return include || exclude;
    }
    bool canPartition(vector<int>& nums) {
        // idea is pretty simple try to build the subset having sum 
        // of total/2, so other half automatically equal to first half

        int sum = 0;
        for(int num : nums){
            sum += num;
        }
        // if there is odd sum we are not able to divide it in equl half 
        if(sum % 2 != 0){
            return false;
        }
        // strt with indx 0, nd try to find the subset having total/2 as sum
        return dfs(nums, 0, sum/2);
    }
};
