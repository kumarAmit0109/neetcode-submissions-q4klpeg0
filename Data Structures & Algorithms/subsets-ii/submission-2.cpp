class Solution {
public:
    void backtrack(int i, vector<int>& subset, vector<int>& nums, vector<vector<int>>& res){
        // instead of using include/exclude way here we build the subsets
        // by choosing each possible next element but only once per unique
        // value at each recursion level
        res.push_back(subset);

        // now for each index from indx to nums.size, pick unique num nd make
        // nxt recursive call
        for(int j = i; j < nums.size(); j++){
            // skip duplicates
            if(j > i && nums[j] == nums[j - 1]){
                continue;
            }
            // include
            subset.push_back(nums[j]);
            backtrack(j+1, subset, nums, res);
            // backtracking
            subset.pop_back();

        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>res;
        sort(nums.begin(), nums.end());
        // initially indx is 0, and subset is empty
        vector<int> subset;
        backtrack(0, subset, nums, res);
        return res;
    }
};
