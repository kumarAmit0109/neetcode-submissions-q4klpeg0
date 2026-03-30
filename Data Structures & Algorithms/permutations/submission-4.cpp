class Solution {
public:
    void backtrack(vector<int>& perm, vector<int>& nums, int mask, vector<vector<int>>& res){
        // If perm has length equal to nums, add a copy to the result
        if (perm.size() == nums.size()) {
            res.push_back(perm);
            return;
        }

        for(int i = 0; i < nums.size(); i++){
            // check whether the nums[i] is included or not, if not then include
            // it nd make call for nxt one
            if(!(mask & (1 << i))){
                perm.push_back(nums[i]);
                // Create new mask instead of modifying original mask
                int newMask = mask | (1 << i);
                backtrack(perm, nums, newMask, res);
                
                // backtracking 
                perm.pop_back();
                // no need to restore the mask, as its pass by value so it remains the same
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        // same as previous but here we use the bitmask to track which element
        // in the nums have been used instead of boolean array
        // (mask & (1 << i)) → checks if index i is used.
        // (mask | (1 << i)) → marks index i as used for the next recursive call

        vector<vector<int>> res;
        vector<int> perm = {};
        int mask = 0;

        backtrack(perm, nums, mask, res);
        return res;
    }
};
