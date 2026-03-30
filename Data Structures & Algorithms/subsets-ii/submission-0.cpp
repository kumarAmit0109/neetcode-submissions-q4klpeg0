class Solution {
public:
    void backtrack(vector<int>& nums, int i, vector<int>subset, set<vector<int>>& res){
        if(i == nums.size()){
            res.insert(subset);
            return;
        }

        // include the current element;
        subset.push_back(nums[i]);
        backtrack(nums, i+1, subset, res);
        // backtrack
        subset.pop_back();
        // exclude the current element
        backtrack(nums, i+1, subset, res);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        // sort the input array so that Subsets are generated in a consistent order
        // so u avoid the cases like [1,2] and [2,1] are avoided
        sort(nums.begin(), nums.end());
        set<vector<int>> res;
        backtrack(nums, 0, {}, res);

        return vector<vector<int>>(res.begin(), res.end());

    }
};
