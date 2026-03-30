class Solution {
public:
    void dfs(vector<int>&nums, int i, vector<int>& subset, vector<vector<int>>&res){
        if(i >= nums.size()){
            res.push_back(subset);
            return;
        }
        // make call by including the curr element
        subset.push_back(nums[i]);
        dfs(nums, i+1, subset, res);

        // make call by exluding the curr element
        subset.pop_back();
        dfs(nums, i+1, subset, res);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>res;
        vector<int>subset;
        dfs(nums, 0, subset, res);
        return res;
    }
};
