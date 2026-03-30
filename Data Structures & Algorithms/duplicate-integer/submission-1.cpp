class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        set<int>seen;
        for(int i = 0; i < nums.size(); i++){
            if(seen.count(nums[i])){
                return true;
            }else{
                seen.insert(nums[i]);
            }
            
        }
        return false;
    }
};