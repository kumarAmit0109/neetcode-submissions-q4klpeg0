class Solution {
public:
    vector<vector<int>>res;
    
    void dfs(int i, vector<int>curr, int total, vector<int>&nums, int target){
        // if total == target, means we found one way of making target
        // simply store and return
        if(total == target){
            res.push_back(curr);
            return;
        }

        // try all numbers starting from index i
        for(int j = i; j < nums.size(); j++){
            // if total + nums[j] exceeds the target means, we can not able
            // to make the target as nums is now sorted so return simply
            if(total + nums[j] > target){
                return;
            }

            // include the nums[j] in list nd make a call with the updated total
            curr.push_back(nums[j]);
            dfs(j, curr, total + nums[j], nums, target);
            // backtrack
            curr.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        // Sort nums so we can stop early when the sum exceeds the target.
        sort(nums.begin(), nums.end());
        dfs(0, {}, 0, nums, target);
        return res;
    }
};
