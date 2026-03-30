class Solution {
public:
    void backtrack(vector<int>& nums, vector<vector<int>>& res, int indx){
        if(indx == nums.size()){
            res.push_back(nums);
            return;
        }

        for(int i = indx; i < nums.size(); i++){
            swap(nums[indx], nums[i]);
            backtrack(nums, res, indx+1);
            // swap again for backtracking purpose
            swap(nums[indx], nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>res;
        // initially indx is 0
        backtrack(nums, res, 0);
        return res;
    }
};
