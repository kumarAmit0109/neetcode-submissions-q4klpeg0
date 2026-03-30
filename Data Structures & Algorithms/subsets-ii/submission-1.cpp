class Solution {
public:
    void backtrack(vector<int>& nums, int i, vector<int>subset, vector<vector<int>>& res){
        if(i == nums.size()){
            res.push_back(subset);
            return;
        }

        // include the current element;
        subset.push_back(nums[i]);
        backtrack(nums, i+1, subset, res);
        // backtrack
        subset.pop_back();
        // exclude the current element as well as the duplicates means
        // move the index as long as the nums[i] == nums[i+1]
        while(i+1 < nums.size() && nums[i] == nums[i+1]){
            i++;
        }
        backtrack(nums, i+1, subset, res);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        // sort the input array so that Subsets are generated in a consistent order
        // also duplicates occur in consecutive orders and easily avoided
        sort(nums.begin(), nums.end());
        vector<vector<int>>res;
        // initially index is 0 and subset is empty
        backtrack(nums, 0, {}, res);

        return res;

    }
};
