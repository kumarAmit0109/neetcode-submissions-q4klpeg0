class Solution {
public:
    int dfs(vector<int>&nums, int indx, int lastIndx){
        if(indx == nums.size()){
            return 0;
        }

        // not include the curr indx element
        int opt1 = dfs(nums, indx+1, lastIndx);

        // if previous included element is smaller than curr one then we can include it
        int opt2 = -1;
        if(lastIndx == -1 || nums[lastIndx] < nums[indx]){
            // if we include after making call for nxt element pass curr indx
            // as the last included indx
            opt2 = 1 + dfs(nums, indx+1, indx);
        }
        return max(opt1, opt2);
    }
    int lengthOfLIS(vector<int>& nums) {
        // inititally start with 0 index nd -1 as the last included indx
        int res = dfs(nums, 0, -1);
        return res;
    }
};
