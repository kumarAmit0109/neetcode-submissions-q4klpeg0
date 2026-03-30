class Solution {
public:
    void solve(vector<int>& perm, vector<int>& nums, vector<bool>& pick, vector<vector<int>>& res){
        // if we picked all element then store temp permutation nd return
        if(perm.size() == nums.size()){
            res.push_back(perm);
            return;
        }

        // pick one element one by one nd insert it into temp perm, and make
        // call for rest , after that remove current elem in order to backtrack 
        // nd repeat 
        for(int i = 0; i < nums.size(); i++){
            // if not pick then pick it 
            if(!pick[i]){
                perm.push_back(nums[i]);
                pick[i] = true;
                solve(perm, nums, pick, res);

                // backtrack 
                perm.pop_back();
                pick[i] = false;
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        // to store result
        vector<vector<int>>res;
        // to keep track of whether number is picked or not
        vector<bool>pick(nums.size(), false);
        // to store temp permutation
        vector<int>perm;
        solve(perm, nums, pick, res);
        return res;
    }
};
