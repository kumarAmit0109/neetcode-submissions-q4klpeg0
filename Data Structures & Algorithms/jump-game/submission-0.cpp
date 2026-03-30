class Solution {
public:
    bool solve(vector<int>& nums, int i){
        // if we reach the end then it means its possible to reach end 
        // so return true
        if(i == nums.size()-1){
            return true;
        }

        // maximum we can jump to min(size-1, i + nums[i])
        // so now we tries whether its possible to reach end from
        // start jumping from any position between i+1 to min(size-1, i + nums[i])

        int maxPosibleFromCurrIndex = min((int)nums.size()-1, i+nums[i]);
        for(int j = i+1; j <= maxPosibleFromCurrIndex; j++){
            if(solve(nums, j)){
                return true;
            }
        }
        return false;
    }
    bool canJump(vector<int>& nums) {
        // start jumping with the index 0
        bool ans = solve(nums, 0);
        return ans;
    }
};
